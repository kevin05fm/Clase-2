#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "employees.h"
#include "FuncionesUtn.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(eEmployees* array,int limite);

//__________________



/** \brief modifica el valor del estado
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return si el retorno es correcto[0] o erroneo[-1]
 *
 */
int employees_init(eEmployees* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}


/** \brief muestra las personas ingresadas
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return si el retorno es correcto[0] o erroneo[-1]
 *
 */
int employees_mostrar(eEmployees* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        printf("Nombre -  Apellido  -   Salario   - Sector - Estado\n\n");
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("%s  - %s  -  %.2f  -   %d   -  %d\n",array[i].name,array[i].lastName,array[i].salary,array[i].sector,array[i].isEmpty);
        }
    }
    return retorno;
}
/** \brief se ingresa el alta de una persona
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return si el retorno es correcto[0] o erroneo[-1]
 *
 */
int employees_alta(eEmployees* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    float salario;
    int auxSector;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("ingrese Nombre\n","\nEso no es un nombre\n","\nEl maximo de caracteres es 50",nombre,50,2))
            {
                if(!getValidString("ingrese Apellido \n","\nEso no es un Apellido\n","\nEl maximo de caracteres es 50",apellido,50,2))
                {
                    if(!getValidFloat("Ingrese Salario\n","Salario incorrecto",&salario,0,99999999,2))
                    {
                        if(!getValidInt("Ingrese Sector\n","\n Eso no es un Sector valido\n",&auxSector,0,999999999,2))
                        {
                            retorno = 0;
                            strcpy(array[i].name,nombre);
                            strcpy(array[i].lastName,apellido);
                            array[i].salary = salario;
                            array[i].sector = auxSector;
                            //------------------------------
                            //------------------------------
                            array[i].idEmployees=proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


/** \brief se ingresa la baja de una persona
 *
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \param id int corresponde al numero con el que se identifica a la persona
 * \return int si el retorno es correcto[0] o erroneo[-1]
 *
 */
int employees_baja(eEmployees* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = employees_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}



/** \brief se ordena el listado de personas
 *
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \param orden int corresponde a la forma en que lo quiera ordenar el usuario
 * \return int si el retorno es correcto[0] o erroneo[-1]
 *
 */
int employees_ordenar(eEmployees* array,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    eEmployees auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].lastName,array[i+1].lastName) > 0 && orden) || (strcmp(array[i].lastName,array[i+1].lastName) < 0 && !orden) )
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }else if((strcmp(array[i].lastName,array[i+1].lastName) == 0 && !orden) && ((array[i].sector > array[i+1].sector) && orden))
                    {
                         auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;

                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}



/** \brief calcula el proximo identificador de persona
 *
 * \param void
 * \return int retorna el identificador nuevo
 *
 */
static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


/** \brief busca por identificador a la persona
 *
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \param id int corresponde al numero de identificador que ingresa el usuario
 * \return int retorna el identificador a buscar
 *
 */
int employees_buscarPorId(eEmployees* array,int limite, int id)
//static int buscarPorId(eEmployees* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idEmployees==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief busca un lugar de estado que no este ocupado
 *
 * \param array eEmployees* corresponde al array ingresado por el usuario
 * \param limite int corresponde a la cantidad de elementos del array
 * \return int retorna el estado libre
 *
 */
static int buscarLugarLibre(eEmployees* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int employees_modificacion(eEmployees* array,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char auxNombre[50];
    char auxLastName[50];
    int auxSector;
    float auxSalary;

    indiceAModificar = employees_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nIngrese Nombre nuevo?","\nNombre no valido","El maximo es 50",auxNombre,50,2))
        {
            if(!getValidString("\nIngrese el apellido nuevo?","\nApellido no valido","El maximo de caracteres es 50",auxLastName,50,2))
             {

                if(!getValidInt("\nIngrese Sector nuevo?","No es un Sector valido",&auxSector,0,99999999,2))
                {

                    if(!getValidFloat("\n Ingrese salario nuevo?","No es un salario valido",&auxSalary,0,99999999999,2))
                    {
                        retorno = 0;
                        strcpy(array[indiceAModificar].name,auxNombre);
                        strcpy(array[indiceAModificar].lastName,auxLastName);
                        array[indiceAModificar].sector=auxSector;
                        array[indiceAModificar].salary=auxSalary;

                    }
                }
            }
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

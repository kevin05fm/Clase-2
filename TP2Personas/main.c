#include <stdio.h>
#include <stdlib.h>
#include "FuncionesUtn.h"
#include "employees.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;
    eEmployees array[CANT];
    int auxId;
    int opciones;

    employees_init(array,CANT);


    while(seguir=='s')
    {
        printf("1- Agregar Empleado\n");
        printf("2- Modificar Empleado\n");
        printf("3- Borrar Empleado\n");
        printf("4- Informar\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                employees_alta(array,CANT);
                break;
            case 2:
                getValidInt("ingresar id\n","id no valido",&auxId,0,99999999,2);
                employees_modificacion(array,CANT,auxId);
                break;
            case 3:
                getValidInt("ingresar id\n","id no valido",&auxId,0,99999999,2);
                employees_baja(array,CANT,auxId);
                break;
            case 4:
                getValidInt("1- Ordenador por Apellido y Sector\n2- promedio","No es una opcion valida",&opciones,1,2,2);
                switch(opciones)
                {
                    case 1:

                    employees_ordenar(array,CANT,1);
                    employees_mostrar(array,CANT);
                        break;
                    case 2:

                        break;
                }

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}

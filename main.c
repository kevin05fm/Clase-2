#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;
    char respuesta;

    //HOLA
    while(respuesta!='s')
    {
        printf("ingresar un numero\n");
        scanf("%d",&numeroUno);
        printf("ingrese segundo numero\n");
        scanf("%d",&numeroDos);

        if(numeroUno>0 && numeroDos>0)
        {
            resultado=numeroUno+numeroDos;
            printf("el resultado es: %d \n",resultado);
        }
        else
        {
            printf("No se puede realizar la operacion");
        }

        printf("Para terminar ingrese la letra s \n");
        fflush(stdin);
        scanf("%c",&respuesta);


    }
    return 0;
}

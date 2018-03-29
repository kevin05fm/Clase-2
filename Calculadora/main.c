#include <stdio.h>
#include <stdlib.h>
#include "lib.h"




int main()
{
    int numeroUno;
    int numeroDos;
    float resultado;
    int opcion;


    printf("ingrese numero 1\n");
    scanf("%d",&numeroUno);
    printf("ingrese numero 2\n");
    scanf("%d",&numeroDos);

    // resultado=sumaEnteros(numeroUno,numeroDos);

    //printf("el resultado es %d ",resultado);

    printf(" 1 sumar\n 2 restar\n 3 multiplicar\n 4 dividir\n");
    scanf("%d",&opcion);

    switch(opcion)
    {
        case 1:
            resultado=sumaEnteros(numeroUno,numeroDos,&resultado);
            if(sumaEnteros (numeroUno,numeroDos,&resultado)==0)
            {
                printf("el resultado es %.2f ",resultado);
            }
            else
            {
                printf("ERROR");
            }
        break;
        case 2:
            resultado=restaEnteros(numeroUno,numeroDos,&resultado);
            if(restaEnteros(numeroUno,numeroDos,&resultado)==0)
            {
                printf("el resultado es %.2f ",resultado);
            }
            else
            {
                printf("ERROR");
            }
        break;
        case 3:
            resultado=multiplicacionEnteros(numeroUno,numeroDos);
        break;
        case 4:
            resultado=divisionEnteros(numeroUno,numeroDos);
        break;

    }



    return 0;

}



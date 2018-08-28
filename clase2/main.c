#include <stdio.h>
#include <stdlib.h>


/*  1-Suma de los negativos.
    2-Suma de los positivos.
    3-Cantidad de positivos.
    4-Cantidad de negativos.
    5-Cantidad de ceros.
    6-Cantidad de números pares.
    7-Promedio de positivos.
    8-Promedios de negativos.
    9-Diferencia entre positivos y negativos, (positvos-negativos).
    10-Maximo y minimo */

int main()
{
    int numero;
    int sumaPositivos=0;
    int sumaNegativos=0;
    int cantidadPositivos=0;
    int cantidadNegativos=0;
    int cantidadPares;
    int cantidadCeros;
    float promedioPositivos;
    float promedioNegativos;
    char respuesta;



    do
    {
        printf("ingrese numero\n");
        scanf("%d",&numero);

        if(numero>0)
        {
            cantidadPositivos++;
            sumaPositivos=sumaPositivos+numero;

        }else if(numero<0)
        {
            cantidadNegativos++;
            sumaNegativos=sumaNegativos+numero;

        }


            printf("desea seguir ingrese s \n");
            printf("La suma de los positivos es :\n",sumaPositivos);
            printf("La suma de los negativos es :\n",sumaNegativos);

    }while(respuesta=='s');

    printf("La suma de los positivos es :\n",sumaPositivos);
    printf("La suma de los negativos es :\n",sumaNegativos);


    return 0;
}

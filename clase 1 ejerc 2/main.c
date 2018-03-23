#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 3

int main()
{
    int acumulador=0;
    float promedio;
    int contador;
    int numero;
    float maximo;

    for(contador=0;contador< CANTIDAD_NUMEROS ;contador++)
    {
        printf("ingrese un numero %d \n",contador+1);
        scanf("%d",&numero);
        acumulador=acumulador+numero;

        if(contador==0)
        {
            maximo=numero;
        }
        else if(numero>maximo)
            {
                maximo=numero;
            }
    }
    promedio=(float)acumulador/contador;
    printf("el promedio es %.2f",promedio);
    printf("\nel numero maximo es %.2f ",maximo);


    return 0;
}

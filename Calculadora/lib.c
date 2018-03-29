
int sumaEnteros (int numeroUno, int numeroDos, float* resultado)
{
    long resultadoCalculo;
    int retorno=-1;

    resultadoCalculo=numeroUno+numeroDos;
    if(resultadoCalculo< 32767)
    {
        *resultado=resultadoCalculo;
        retorno=0;
    }
    return retorno;
}

int divisionEnteros(int numeroUno, int numeroDos)
{
    int resultado=0;
    if(numeroDos>0)
    {
        resultado=numeroUno/numeroDos;
    }

    return resultado;
}
int multiplicacionEnteros(int numeroUno, int numeroDos)
{
    int resultado;
    resultado=numeroUno*numeroDos;
    return resultado;
}
int restaEnteros(int numeroUno, int numeroDos,float* resultado)
{
    long resultadoCalculo;
    int retorno=-1;

    resultadoCalculo=numeroUno-numeroDos;
    if(resultadoCalculo>32767)
    {
        *resultado=resultadoCalculo;
        retorno=0;

    }

    return retorno;
}

//funciones de la calculadora
#include "funciones.h"
//Funcion suma
float sumar(float x, float y)
{
    float sumaDeOperandos;
    sumaDeOperandos = x + y;
    return sumaDeOperandos;
}

//Funcion resta
float restar(float x, float y)
{
    float restaDeOperandos;
    restaDeOperandos = x - y;
    return restaDeOperandos;
}

//Funcion Multiplicacion
float multiplicar(float x, float y)
{
    float multiplicacionDeOperandos;
    multiplicacionDeOperandos = x * y;
    return multiplicacionDeOperandos;
}

//Funcion division
float dividir(float x, float y)
{
    float divisionDeOperandos;
    if(y != 0)
    {
        divisionDeOperandos = x / y;
    }
    return divisionDeOperandos;
}

//Funcion factoriales
int calcularFactoriales(float numero)
{
    int resultado;
    //int i;
    if(numero==0){
        resultado = 1;
    } else{
        resultado = (int)numero*calcularFactoriales(numero - 1);

    }
    return resultado;
}

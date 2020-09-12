//funciones de la calculadora

#include "funciones.h"
int sumaDeOperandos(int primerNumero, int segundoNumero){

    int sumaDeOperandos = primerNumero + segundoNumero;
    return sumaDeOperandos;
}

int restaDeOperandos(int primerNumero, int segundoNumero){

    int restaDeOperandos = primerNumero - segundoNumero;
    return restaDeOperandos;
}

int multiplicacionDeOperandos(int primerNumero, int segundoNumero){

    int multiplicacionDeOperandos = primerNumero * segundoNumero;
    return multiplicacionDeOperandos;
}

float divisionDeOperandos(int primerNumero, int segundoNumero){
    float divisionDeOperandos;
    if(segundoNumero != 0){
        divisionDeOperandos = primerNumero / segundoNumero;
    }
    return divisionDeOperandos;

int factoriales(int primerNumero){
    int factoriales;
    if(primerNumero==0){
        factoriales = 1;
    } else{
        for(int i = primerNumero; i<1; i++){
            factoriales = primerNumero*(primerNumero - 1);
        }
    }
    return factoriales;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedirDatos.h"

int pedirNumeroEntero(int* resultado, char* mensaje, char*mensajeDeError, int* maximo, int* minimo, int* intentos)
{
    int espacioEnInt;
    int retornar=-1;
    if(resultado != NULL && mensaje != NULL && mensajeDeError != NULL && minimo <= maximo && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("&d", &espacioEnInt);
            if(espacioEnInt >= minimo && espacioEnInt <= maximo)
            {
                *resultado=espacioEnInt;
                retornar=0;
                break;
            }else
            {
                printf("%s", mensajeDeError);
                intentos--;
            }
        }while(intentos>=0);
    }
    return retornar;
}

float pedirNumeroFlotante(float* resultado, char* mensaje, char*mensajeDeError, float* maximo, float* minimo, int* intentos)
{
    float espacioEnFloat
    int retornar=-1
    if(resultado != NULL && mensaje != NULL && mensajeDeError != NULL && minimo <= maximo && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("&d", &espacioEnFloat);
            if(espacioEnFloat >= minimo && espacioEnFloat <= maximo)
            {
                *resultado=espacioEnFloat;
                retornar=0;
                break;
            }else
            {
                printf("%s", mensajeDeError);
                intentos--;
            }
        }while(intentos>=0);
    }
    return retornar;
}

char pedirCaracter(char* resultado, char* mensaje, char*mensajeDeError, char* maximo, char* minimo, int* intentos)
{
    char espacioEnChar;
    int retornar=-1;
    if(resultado != NULL && mensaje != NULL && mensajeDeError != NULL && minimo <= maximo && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("&d", &espacioEnChar);
            if(espacioEnChar >= minimo && espacioEnChar <= maximo)
            {
                *resultado=espacioEnChar;
                retornar=0;
                break;
            }else
            {
                printf("%s", mensajeDeError);
                intentos--;
            }
        }while(intentos>=0);
    }
    return retornar;
}

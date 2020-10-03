#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pedirDatos.h"

/** \brief el usuario ingresa un numero entero
 *
 * \param resultado int* lugar de memoria
 * \param mensaje char* mensaje al mostrar
 * \param char*mensajeDeError mensaje al ingresar algo incorrecto
 * \param maximo int* numero maximo al ser ingresado
 * \param minimo int* numero minimo al ser ingresado
 * \param intentos int* numero de intentos del usuario
 * \return int 0 si esta bien; -1 si hubo error
 *
 */
int pedirNumeroEntero(int* resultado, char* mensaje, char* mensajeDeError, int* maximo, int* minimo, int* intentos)
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

/** \brief el usuario ingresa un numero flotante
 *
 * \param resultado int* lugar de memoria
 * \param mensaje char* mensaje al mostrar
 * \param char*mensajeDeError mensaje al ingresar algo incorrecto
 * \param maximo int* numero maximo al ser ingresado
 * \param minimo int* numero minimo al ser ingresado
 * \param intentos int* numero de intentos del usuario
 * \return int 0 si esta bien; -1 si hubo error
 *
 */
float pedirNumeroFlotante(float* resultado, char* mensaje, char* mensajeError, float minimo, float maximo, int intentos)
{
    float espacioEnFloat;
    int retornar=-1;
    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &espacioEnFloat);
            if(espacioEnFloat >= minimo && espacioEnFloat <= maximo)
            {
                *resultado=espacioEnFloat;
                retornar=0;
                break;
            }else
            {
                printf("%s", mensajeError);
                intentos--;
            }
        }while(intentos>=0);
    }
    return retornar;
}

/** \brief el usuario ingresa un caracter
 *
 * \param resultado int* lugar de memoria
 * \param mensaje char* mensaje al mostrar
 * \param char*mensajeDeError mensaje al ingresar algo incorrecto
 * \param maximo int* numero maximo al ser ingresado
 * \param minimo int* numero minimo al ser ingresado
 * \param intentos int* numero de intentos del usuario
 * \return int 0 si esta bien; -1 si hubo error
 *
 */
char pedirCaracter(char* resultado, char* mensaje, char* mensajeError, char minimo, char maximo, int intentos)
{
    char espacioEnChar;
    int retornar=-1;
    if(resultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
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
                printf("%s", mensajeError);
                intentos--;
            }
        }while(intentos>=0);
    }
    return retornar;
}

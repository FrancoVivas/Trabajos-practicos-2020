//Tp 1
//Franco Vivas


//Funciones creadas
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
    //Variables
    int opcion;
    float primerNumero;
    float segundoNumero;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int factorialR1;
    int factorialR2;

    int valorPrimerNumero;
    int valorSegundoNumero;

    valorPrimerNumero = 0;
    valorSegundoNumero = 0;

    do
    {
        //Opciones del usuario
       printf("1-Ingresar el primer numero \n");
       printf("2-Ingresar el segundo numero \n");
       printf("3-Calcular todas las operaciones \n");
       printf("4-Mostrar resultados \n");
       printf("5-Salir \n");

        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1://Primer Operando
                printf("\nPrimer Operando...\n");
                scanf("%f", &primerNumero);
                valorPrimerNumero = 1;
            break;
            case 2://Segundo Operando
                printf("Segundo Operando...\n");
                scanf("%f", &segundoNumero);
                valorSegundoNumero = 1;
            break;
            case 3://Calculo de las 2 operaciones
                if(valorPrimerNumero == 0 || valorSegundoNumero == 0)
                {
                    printf("No ingreso numeros \n");
                }
                else
                {
                    suma = sumar(primerNumero,segundoNumero);
                    resta = restar(primerNumero,segundoNumero);
                    multiplicacion = multiplicar(primerNumero,segundoNumero);
                    division = dividir(primerNumero,segundoNumero);
                    factorialR1 = calcularFactoriales(primerNumero);
                    factorialR2 = calcularFactoriales(segundoNumero);
                    printf("\nCalcular Operaciones...\n");
                }

            break;
            case 4://Resultado de las operaciones
                printf("\nA. El resultado de A + B es: %f\n", suma);
                printf("\nB. El resultado de A - B es: %f\n", resta);
                printf("\nD. El resultado de A * B es: %f\n", multiplicacion);

                if(segundoNumero != 0)
                {
                    printf("El resultado de la division es: %f \n", division);
                }
                else
                {
                    printf("No se puede dividir por cero \n");
                }


                printf("\nE. El resultado del factorial de R1 es: %f\n", factorialR1);
                printf("\nE. El resultado del factorial de R2 es: %f\n", factorialR2);
            break;
            case 5://Si el usuario quiere salir
                printf("\nSaliendo...\n");
                break;
            default:
                printf("Opcion Incorrecta \n");
                printf("Elija una opcion valida \n");
                break;

        }


    }while(opcion!=5);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void)
{
    int opcion;
    int primerNumero;
    int segundoNumero;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorialR1;
    int factorialR2;

    do
    {
        printf("1. Primer Operando\n2. Segundo Operando\n3. Calcular Operaciones\n4. Resultados\n5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("\nPrimer Operando...\n");
                scanf("%d", primerNumero);
            break;
            case 2:
                printf("Segundo Operando...\n");
                scanf("%d", segundoNumero);
            break;
            case 3:
                suma = sumaDeOperandos(primerNumero,segundoNumero);
                resta = restaDeOperandos(primerNumero,segundoNumero);
                multiplicacion = multiplicacionDeOperandos(primerNumero,segundoNumero);
                division = divisionDeOperandos(primerNumero,segundoNumero);
                factorialR1 = factoriales(primerNumero);
                factorialR2 = factoriales(segundoNumero);
                printf("\nCalcular Operaciones...\n");
            break;
            case 4:
                printf("\nA. El resultado de A + B es: %d\n", suma);
                printf("\nB. El resultado de A - B es: %d\n", resta);
                printf("\nC. El resultado de A / B es: %f\n", division);
                printf("\nD. El resultado de A * B es: %d\n", multiplicacion);
                printf("\nE. El resultado del factorial de R1 es: %d\n", factorialR1);
                printf("\nE. El resultado del factorial de R2 es: %d\n", factorialR2);
            break;
            case 5:
                printf("\nSaliendo...\n");
                break;

        }


    }while(opcion!=5);

    return 0;
}

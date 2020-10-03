//Franco Vivas
//TP2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "arrayEmpleados.h"
#include "pedirDatos.h"

#define cantidadEmpleados 1
#define empty 0
#define ocupado 1


int main(void)
{
    setbuf(stdout, NULL);
    empleado lista[cantidadEmpleados];
    int id=0;
    char nombre[20];
    char apellido[20];
    float salario=0;
    int sector=0;
    int opcion;
    int indexEspacioLibre;

    iniciarEmpleado(lista, cantidadEmpleados, empty);

    do
    {
        opcion=menu();
            switch(opcion)
            {
            case 1:
                indexEspacioLibre=mirarEspacioLibre(lista, cantidadEmpleados);
                if(indexEspacioLibre==-1)
                {
                    printf("No hay lugares libres.");
                }
                agregarEmpleado(lista, cantidadEmpleados, indexEspacioLibre, nombre[20], apellido[20], salario, sector);
                break;
            case 2:
                encontrarEmpleadoPorId(lista, cantidadEmpleados, id);
                break;
            case 3:
                encontrarEmpleadoPorId(lista, cantidadEmpleados, id);
                break;
            case 4:
                mostrarEmpleados(lista, cantidadEmpleados);
                break;
            }
            printf("%d", opcion);
    }while(opcion!=5);
    return 0;
}

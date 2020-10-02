//Franco Vivas
//TP2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "arrayEmployees.h"
#include "pedirDatos.h"

#define cantidadEmplados 1
#define empty 0
#define ocupado 1


int main(void)
{
    setbuf(stdout, NULL);
    empleado list[cantidadEmplados];
    int id=0;
    char nombre;
    char apellido;
    float salario=0;
    int sector=0;
    int opcion;
    int indexEspacioLibre;

    iniciarEmpleado(lista, cantidadEmplados, empty);

    do
    {
        opcion=menu();
            switch(opcion)
            {
            case 1:
                indexEspacioLibre=mirarPorEspacioLibre(lista, cantidadEmplados);
                if(indexEspacioLibre==-1)
                {
                    printf("No hay lugares libres.");
                }
                agregarEmpleado(lista, cantidadEmplados, indexEspacioLibre, nombre[20], apellido[20], salario, sector);
                break;
            case 2:
                encontrarEmpleadoPorId(lista, cantidadEmplados, id);
                break;
            case 3:
                encontrarEmpleadoPorId(lista, cantidadEmplados, id);
                break;
            case 4:
                mostrarEmpleados(lista, cantidadEmplados);
                break;
            }
    }while(opcion!=5);
    return 0;
}

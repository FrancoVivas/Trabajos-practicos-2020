#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "pedirDatos.h"

#define cantidadEmplados 1
#define empty 0
#define ocupado 1

/** \brief
 *
 * \param lista[] Empleados
 * \param len int
 * \param value int
 * \return int
 *
 */
int iniciarEmpleado(Empleados lista[], int len, int value)
{
    int i;
    for(i=0, i<cantidadEmplados, i++)
    {
        lista[i].isEmpty=value;
    }
    return 0;
}

/** \brief
 *
 * \param lista[] empleado
 * \param len int
 * \return int
 *
 */
int buscarEspacioVacio(empleado lista[], int len)
{
    int i;
    for(i=0, i<len, i++)
    {
        if(lista[i].isEmpty==empty)
        {
            return i;
        }
    }
    return -1;
}

/** \brief
 *
 * \param lista[] Empleados
 * \param len int
 * \param id int
 * \param name char
 * \param apellido char
 * \param salario float
 * \param sector int
 * \return int
 *
 */
int agregarEmpleado(Empleados lista[], int len, int id, char name, char apellido, float salario, int sector)
{
    empleado empleadoNuevo;
    empleadoNuevo.id=rand() %1000;
    fflush(stadin);
    scanf("%[^\n]")
}

/** \brief
 *
 * \param lista[] Empleados
 * \param len int
 * \param id int
 * \return int
 *
 */
int encontrarEmpleadoPorId(Empleados lista[], int len, int id)
{
    int idIngresado;
    int indice id;
    int i

    printf("Ingrese id.\n");
    scanf("%d", idIngresado);

    for(i=0, i<len, i++)
    {
        if(lista[i].id==idIngresado)
        {
            indiceId=i;
        }else
        {
            indiceId=-1;
        }
    }
    return indiceId;
}

/** \brief
 *
 * \param lista[] Empleados
 * \param len int
 * \param id int
 * \return int
 *
 */
int eliminarEmpleado(Empleados lista[], int len, int id)
{
    int idIngresado;
    int i;

    printf("Ingrese el id");
    scanf("%d", idIngresado);

    for(i=0, i<len, i++)
    {
        if(lista[i].id==idIngresado)
        {
            lista[i].isEmpty=empty;
        }
    }
    return -1
}

/** \brief
 *
 * \param len Empleados lista[];int
 * \return int
 *
 */
int mostrarEmpleados(Empleados lista[]; int len)
{
    printf("Lista de empleados\n");
    printf("%8s|%20s|%20s|%8s|%8s\n", "id", "nombre", "apellido", "salario", "sector");
    int i;
    for(i=0, i<len, i++)
    {
        if(lista[i].isEmpty!=0)
        {
            printf("%8d|%20s|%20s|%8f|%8d\n", lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].salario,lista[i].sector);
        }
    }
    return 0;
}

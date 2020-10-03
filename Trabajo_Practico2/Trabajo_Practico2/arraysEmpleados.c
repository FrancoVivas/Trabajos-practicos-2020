#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmpleados.h"
#include "pedirDatos.h"

#define cantidadEmplados 1
#define empty 0
#define ocupado 1

/** \brief indica las posiciones vacias de la array
 *
 * \param lista[] Empleados array de empleados
 * \param len int devuelve la longitud de la array
 * \param value int devuelve el valor de la array
 * \return int si da -1, tira error y si da 0 esta bien
 *
 */
int iniciarEmpleado(empleado lista[], int len, int value)
{
    int i;
    for(i=0; i<cantidadEmplados; i++)
    {
        lista[i].isEmpty=value;
    }
    return 0;
}

/** \brief busca un espacio vacio en una array
 *
 * \param lista[] empleado es la array de empleados
 * \param len int es el largo de un array
 * \return int retorna -1 si no hay espacios vacios
 *
 */
int buscarEspacioVacio(empleado lista[], int len)
{
    int i;
    for(i=0; i<len; i++)
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
 * \param lista[] Empleados es la array de empleados
 * \param len int
 * \param id int
 * \param name char
 * \param apellido char
 * \param salario float
 * \param sector int
 * \return int devuelve -1 si da error
 *
 */
int agregarEmpleado(empleado lista[], int len, int id, char name, char apellido, float salario, int sector)
{
    int retornar=-1;
    int i;
    for(i=0; i<len; i++)
    {
        int idEmpleado=1;
        printf("Ingrese un nombre");
        fflush(stdin);
        scanf("%[^\n]", lista[i].nombre);

        printf("Ingrese un apellido");
        fflush(stdin);
        scanf("%[^\n]", lista[i].apellido);

        printf("Ingrese un salario");
        fflush(stdin);
        scanf("%[^\n]", lista[i].salario);

        printf("Ingrese un sector");
        fflush(stdin);
        scanf("%[^\n]", lista[i].sector);

        lista[i].isEmpty=ocupado;
        retornar=0;
    }
    return retornar;
}

/** \brief encuentra un empleado por id y retorna el indice de la posicion en array
 *
 * \param lista[] Empleados
 * \param len int
 * \param id int
 * \return int retorna la posicion del indice de empleado
 *
 */
int encontrarEmpleadoPorId(empleado lista[], int len, int id)
{
    int idIngresado;
    int indiceId;
    int i;

    printf("Ingrese id.\n");
    scanf("%d", idIngresado);

    for(i=0; i<len; i++)
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

/** \brief remover un empleado por id
 *
 * \param lista[] Empleados
 * \param len int
 * \param id int
 * \return int retorna -1 si da error
 *
 */
int eliminarEmpleado(empleado lista[], int len, int id)
{
    int idIngresado;
    int i;

    printf("Ingrese el id");
    scanf("%d", idIngresado);

    for(i=0; i<len; i++)
    {
        if(lista[i].id==idIngresado)
        {
            lista[i].isEmpty=empty;
        }
    }
    return -1;
}

/** \brief muestra el contenido del array empleados
 *
 * \param len Empleados lista[];int
 * \return int
 *
 */
int mostrarEmpleados(empleado lista[]; int len, int largo)
{
    printf("Lista de empleados\n");
    printf("%8s|%20s|%20s|%8s|%8s\n", "id", "nombre", "apellido", "salario", "sector");
    int i;
    for(i=0; i<len; i++)
    {
        if(lista[i].isEmpty!=0)
        {
            printf("%8d|%20s|%20s|%8f|%8d\n", lista[i].id, lista[i].nombre, lista[i].apellido, lista[i].salario,lista[i].sector);
        }
    }
    return 0;
}

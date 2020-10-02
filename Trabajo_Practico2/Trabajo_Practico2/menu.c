#include <stdio.h>
#include "menu.h"
#include "pedirDatos.h"

/** \brief
 *
 * \return int
 *
 */
int menu()
{
    /*int opcion;
    printf("Bienvenido, elija la que desee\n");
    printf("Opcion 1: Alta\n");
    printf("Opcion 2: Modificar\n");
    printf("Opcion 3: Baja\n");
    printf("Opcion 4: Informes\n");
    printf("Opcion 5: Salir\n");
    scanf("%d", opcion);
    return opcion;*/

    int opcion;
    printf("Plantilla de empleados\nElija la una opcion\n");
    opcion=pedirNumeroEntero(%opcion, "1.Alta\n2.Baja\3.Modificar\n4.Informar\n5.Salir\n", "Opcion incorrecta\n",1,2,5);
    return opcion;
}

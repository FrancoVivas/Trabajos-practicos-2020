#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
    LinkedList* listaEmployee;
    int selectedOption;
    int len;


    listaEmployee=ll_newLinkedList();

    if(listaEmployee!=NULL)
    {

        do
        {
            controller_showCounterOfEmployees(listaEmployee);
            if(!controller_Menu(&selectedOption))
            {
                switch(selectedOption)
                {
                    case 1:
                        if(controller_loadFromText("data.csv",listaEmployee)==0)
                        {
                            printf("\nSe cargaron correctamente los empleados de la lista txt\n\n");
                        }
                        else
                        {
                            printf("\nNO se cargaron correctamente los empleados de la lista txt\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        if(controller_loadFromBinary("data.bin",listaEmployee)==0)
                        {
                            printf("\nSe cargaron correctamente los empleados de la lista bin\n\n");
                        }
                        else
                        {
                            printf("\nNO se cargaron correctamente los empleados de la lista bin\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        if(controller_addEmployee(listaEmployee)==0)
                        {
                            printf("\nEl empleado se ha agregado correctamente a la lista\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido agregar al empleado\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        if(controller_editEmployee(listaEmployee)==0)
                        {
                            printf("\nSe ha modificado correctamente al empleado\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido modificar al empleado\n\n");
                        }
                        system("pause");
                        system("cls");
                            break;
                    case 5:
                        controller_ListEmployee(listaEmployee);
                        if(controller_removeEmployee(listaEmployee)==0)
                        {
                            printf("\nSe ha eliminado correctamente al empleado\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido eliminar al empleado\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 6:
                        if(controller_ListEmployee(listaEmployee)!=0)
                        {
                            printf("\nNo se ha podido listar a los empleados\n\n");
                        }
                        else
                        {
                            printf("\n");
                        }

                        system("pause");
                        system("cls");
                        break;
                    case 7:
                        if(controller_sortEmployee(listaEmployee)==0)
                        {
                            printf("\nSe ha ordenado la lista de empleados\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido ordenar la lista de empleados\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 8:
                        if(controller_saveAsText("data.csv",listaEmployee)!=-1)
                        {
                            printf("\nSe ha guardado la lista de empleados en modo texto.\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido guardar la lista de empleados en modo texto.\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 9:
                        if(controller_saveAsBinary("data.bin",listaEmployee)!=-1)
                        {
                            printf("\nSe ha guardado la lista de empleados en modo binario.\n\n");
                        }
                        else
                        {
                            printf("\nNo se ha podido guardar la lista de empleados en modo binario.\n\n");
                        }
                        system("pause");
                        system("cls");
                        break;

                }

            }
            else
            {
                printf("\nError! Opcion de menu invalida.");
            }
        }while(selectedOption!=10);
    }

    return 0;
}

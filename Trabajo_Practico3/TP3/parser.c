#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ifError=-1;
    int r;
    char id[50];
    char nombre[50];
    char HorasTrabajadas[50];
    char sueldo[50];
    Employee* anEmployee;

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,HorasTrabajadas,sueldo);
        if(esNumerico(id))
        {
            rewind(pFile);
        }
        while(!feof(pFile))
        {

            r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,HorasTrabajadas,sueldo);
            if(r==4)
            {
                anEmployee=employee_newParametros(id,nombre,HorasTrabajadas,sueldo);
                if(anEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,anEmployee);
                }
            }

        }
        fclose(pFile);
        ifError=0;
    }

    return ifError;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ifError=-1;
    int r;
    Employee* anEmployee;

    if(pFile != NULL && anEmployee!=NULL)
    {
        while(!feof(pFile))
        {
            anEmployee=employee_new();
            if(anEmployee!=NULL)
            {
                r=fread(anEmployee,sizeof(Employee),1,pFile);

                if(r==1)
                {
                    ll_add(pArrayListEmployee,anEmployee);
                }
            }
        }
        fclose(pFile);
        ifError=0;
    }

    return ifError;
}

int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            aux=(Employee*) ll_get(pArrayListEmployee,i);
            if(aux!=NULL)
            {

                fwrite(aux,sizeof(Employee),1,pFile);
            }
        }
    }
    return i;
}

int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int i;
    int id;
    char nombre[128];
    int hs;
    int sueldo;
    int len;
    Employee* aux;

    if(pFile!=NULL && pArrayListEmployee!=NULL && aux!=NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            aux=(Employee*)ll_get(pArrayListEmployee,i);

            if(aux!=NULL)
            {
                if(!employee_getId(aux,&id) &&
                !employee_getNombre(aux,nombre) &&
                !employee_getHorasTrabajadas(aux,&hs) &&
                !employee_getSueldo(aux,&sueldo))
                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,hs,sueldo);
            }
        }
    }
    return i;
}


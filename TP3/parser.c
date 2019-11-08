#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *emp;
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];
    int retorno=-1;
    int r;



    if(pFile!=NULL)
    {
    r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
    do
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        if(r==4)
        {

            emp=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

            if(emp!=NULL)
                {
                    ll_add(pArrayListEmployee,emp);
                    retorno=0;
                }

        }
        else
            break;


    }while(!feof(pFile));
    }
    else
    {
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* emp;
    int retorno=0;
    int r;

        do

        {
            emp=employee_new();
            if(emp!=NULL && pFile!=NULL)
            {
                r=fread(emp,sizeof(Employee),1,pFile);

                if(r==1)
                {
                ll_add(pArrayListEmployee,emp);
                retorno=1;
                }
            }
            else
                break;


        }while(!feof(pFile));


    return retorno;
}

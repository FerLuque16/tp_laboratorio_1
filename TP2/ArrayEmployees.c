#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayEmployees.h"

int initEmployees(eEmployee *emp, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        emp[i].isEmpty=1;
    }

    return 0;
}

int addEmployee(eEmployee *emp, int len,eSector *auxSector, int lenSector)//, int id, char name[],char lastName[],float salary,int sector)

{
    int index;
    char rta;
    int retorno=-1;

    index=findEmptyPlace(emp,len);

    if(index!=-1)
    {
        emp[index].id=getRandomNumber(1,1000,1);
        getString(emp[index].name,"\nIngrese nombre: \n","\nERROR\n",1,51);
        getString(emp[index].lastName,"\nIngrese apellido : \n","\nERROR\n",1,51);
        getFloat(&emp[index].salary,"\nIngrese salario : \n","\nERROR\n",1,200000);
        system("cls");

        printSector(auxSector,lenSector);
        getInt(&emp[index].sector,"\nIngrese id del sector: \n","\nERROR\n",1,4);

        emp[index].id=getRandomNumber(1,1000,1);

        getChar(&rta,"\nIngrese s para confirmar el alta\n","\nERROR\n",'a','z');


        if(rta == 's' || rta == 'S')
        {
            emp[index].isEmpty=0;
            retorno=0;
        }
        else
        {
            printf("\nNo se ha dado de alta el empleado\n");
            system("pause");
        }

    }
    else
    {
           printf("\nNo hay mas espacio libre\n");
    }

    return retorno;
    }

int removeEmployee(eEmployee *emp,int len ,eSector *sec, int lenSec )
{
    char rta;
    int auxId;
    int index;
    int retorno=-1;

    getInt(&auxId,"\nIngrese ID del empleado: \n","\nERROR\n",1,1000);

    index=findEmployeeById(emp,len,auxId);

            if(index != -1)
            {

               do
               {
                   system("cls");

                   getChar(&rta,"\n¿Confirma la baja del empleado? Ingrese s o n: \n","\nERROR\n",'n','s');
                   system("pause");

               }while(rta != 's' &&  rta != 'n');

               if(rta=='s')
                {
                    emp[index].isEmpty=1;
                    retorno=0;

                }
               else
                {
                    printf("\nNo se ha dado de baja\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo se ha encontrado al empleado\n");
            }

    return retorno;

}

void modifyEmployee(eEmployee *emp,int len,eSector *sec , int lenSector)
{
    char rta;
    int auxId,index;
    int opcMod;

    sortEmployee(emp,len,1);
    printAllEmployees(emp,len,sec,lenSector);
    getInt(&auxId,"\nIngrese ID del empleado: ","\nERROR\n",1,1000);

    index=findEmployeeById(emp,len,auxId);


            if(index!=-1)
            {
                getChar(&rta,"\n¿Desea modificar? Ingrese s o n\n","\nERROR\n",'n','s');

               if(rta=='s')
                {
                    do
                    {
                        system("cls");


                        getInt(&opcMod,"1. Modificar nombre.\n2. Modificar apellido.\n3. Modificar salario.\n4. Modificar sector.\n5. Atras.\n\nIngrese la opcion a realizar: \n","OPCION NO VALIDA",1,5);

                        switch(opcMod)
                        {
                            case 1:
                                getString(emp[index].name,"\nIngrese nombre\n","\nERROR\n",1,51);

                                break;

                            case 2:
                                getString(emp[index].lastName,"\nIngrese apellido\n","ERROR",1,51);

                                break;

                            case 3:
                                getFloat(&emp[index].salary,"\nIngrese salario\n: ","ERROR",1,200000);

                                break;


                            case 4:
                                printSector(sec,lenSector);
                                getInt(&emp[index].sector,"Ingrese sector: ","\nERROR\n",1,4);
                                break;

                            case 5:
                                printf("\nNo se ha modificado al empleado\n");
                                opcMod=5;


                        }
                    }while(opcMod!=5);
                }
               else
                {
                    printf("\nNo se ha modificado al empleado\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo se ha encontrado al empleado\n");
                system("pause");
            }
    }


void printSector(eSector *sec, int len)
{
    setbuf(stdin,NULL);
    int i;

        for(i=0;i<len;i++)
            {
                    printf("%d\t%s\n" ,sec[i].id,sec[i].desc);
            }
}

int findEmployeeById(eEmployee *emp, int len, int id)
{
    int i;
    int  index = -1;

    for(i=0; i<len; i++)
    {
        if(emp[i].id == id && emp[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int findEmptyPlace (eEmployee emp[], int len)
{
    int i;
    int index=-1;

    for(i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}



void printEmployee(eEmployee emp,eSector sec[], int lenSec, int formato)
{
    int i=0;
    char auxSec[51];

    for(i=0;i<lenSec;i++)
    {
        if(emp.sector==sec[i].id)
            {
                strcpy(auxSec,sec[i].desc);
                break;
            }

    }
        if(formato==0)
        {
            printf("\n%10d %10s %10s %10.2f %15s\n", emp.id, emp.name, emp.lastName, emp.salary, auxSec);

        }

        else
        {
        printf("\nLegajo: %d | Nombre: %s | Apellido: %s | Salario: %.2f | Sector: %s\n", emp.id, emp.name, emp.lastName, emp.salary, auxSec);
        system("pause");
        }

}

void printAllEmployees(eEmployee emp[], int len, eSector sec[], int lenSector)
{
    int i, j;
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("%10s %10s %10s %10s %10s", "Legajo", "Nombre", "Apellido", "Salario", "Sector");
    for(j=0; j<lenSector; j++)
    {

        for(i=0; i<lenSector; i++)
        {
            if(emp[i].sector == sec[j].id && emp[i].isEmpty == 0)
            {
                printEmployee(emp[i], sec, lenSector,0);
                printf("\n--------------------------------------------------------------------------------------------------\n");
            }
        }
    }
}




void sortEmployee(eEmployee emp[], int len, int order)
{
    int i, j;
    eEmployee auxEmp;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(order == 1)
            {
                if(strcmp(emp[i].lastName, emp[j].lastName) > 0)
                {
                    auxEmp = emp[i];
                    emp[i] = emp[j];
                    emp[j] = auxEmp;
                }
            }
            else{
                if(strcmp(emp[j].lastName, emp[i].lastName) > 0)
                {
                    auxEmp = emp[j];
                    emp[j] = emp[i];
                    emp[i] = auxEmp;
                }
            }
        }
    }
}

void calculateSalaryInfo(eEmployee emp[], int len)
{
    int i;
    int employeeCounter = 0;
    int employeeExceedCounter = 0;
    float salaryAcumulator = 0;
    float averageSalary;
    for(i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            salaryAcumulator += emp[i].salary;
            employeeCounter++;
        }
    }
    averageSalary = salaryAcumulator / employeeCounter;
    for(i=0; i<len; i++)
    {
        if(emp[i].salary > averageSalary && emp[i].isEmpty == 0)
        {
            employeeExceedCounter++;
        }
    }
    printf("Total de salarios: $%.2f | Promedio de salarios: $%.2f | Empleados que superan el promedio: %d\n\n", salaryAcumulator, averageSalary, employeeExceedCounter);
    system("pause");
}



#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayEmployees.h"

#define CANT_EMPLOYEES 1000
#define CANT_SECTOR 4


int main()
{
    eEmployee emp[CANT_EMPLOYEES];
    int opc;
    int status,removed;
    int contadorEmp=0;


    initEmployees(emp,CANT_EMPLOYEES);
    eSector sector [CANT_SECTOR] = {{1,"Contabilidad"},{2,"Sistemas"},{3, "RRHH"},{4, "Mantenimiento"}};
    do
    {
        system("cls");

        getInt(&opc,"1. Altas\n2. Modificar\n3. Baja\n4. Listar\n5. Salir\n","Opcion no valida",1,5);

        switch(opc)
        {
            case 1:
                status=addEmployee(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                if(status==0)
                {
                    contadorEmp++;
                    system("cls");
                    printf("\nSe ha dado de alta al empleado\n");
                    system("pause");
                }

                break;

            case 2:

                if(contadorEmp>0)
                {
                    modifyEmployee(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                }
                else
                {
                    printf("\nNo hay empleados cargados\n ");
                    system("pause");
                }

                break;

            case 3:
                if(contadorEmp>0)
                {
                    sortEmployee(emp,CANT_EMPLOYEES,1);
                    printAllEmployees(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                    removed=removeEmployee(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                    if(removed==0)
                    {
                    contadorEmp--;
                    }
                }
                else
                {
                    printf("\nNo hay empleados cargados\n ");
                    system("pause");
                }
                break;

            case 4:

                if(contadorEmp>0)
                {
                    sortEmployee(emp,CANT_EMPLOYEES,1);
                    printAllEmployees(emp,CANT_EMPLOYEES,sector,CANT_SECTOR);
                    calculateSalaryInfo(emp,CANT_EMPLOYEES);

                }
                else
                {
                    printf("\nNo hay empleados cargados\n ");
                    system("pause");
                }

                break;

            case 5:
                opc=5;

                break;


        }

    }while(opc!=5);
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "string.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{


    FILE *archivo;
    int retorno=0;

    archivo=fopen(path,"r");

    if(archivo!=NULL)
    {
        retorno=parser_EmployeeFromText(archivo,pArrayListEmployee);
    }


    fclose(archivo);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *archivo;
    archivo=fopen(path,"rb");
    int retorno=0;

    if(archivo!=NULL)
    {
        retorno=parser_EmployeeFromBinary(archivo,pArrayListEmployee);
    }

    fclose(archivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee *emp;

    char auxId[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];
    int retorno=0;
    int flag=0;
    int confirm;
    char rta[21];


    if(getString(nombre,"Ingresar nombre: ","DATOS NO VALIDOS",1,128,3)==0)
                {
                    system("cls");
                    printf("Se ha registrado el nombre correctamente\n\n");
                    system("pause");
                    flag++;

                }
                else
                {
                    system("cls");
                    printf("No se ha podido agregar al empleado\n\n");
                    system("pause");
                }
    if(flag==1)
    {


        if(getStringNumeros(horasTrabajadas,"Ingrese las horas trabajadas: ","DATOS NO VALIDOS",1,128,3)==0)
                {
                    system("cls");
                    printf("Se han registrado las horas correctamente\n\n");
                    system("pause");
                    flag++;
                }
                else
                {
                    system("cls");
                    printf("No se ha podido agregar al empleado\n\n");
                    system("pause");
                }
    }

    if(flag==2)
    {
        if(getStringNumeros(sueldo,"Ingrese el sueldo: ","DATOS NO VALIDOS",1,128,3)==0)
                {
                    system("cls");
                    printf("Se ha registrado el sueldo correctamente\n\n");
                    system("pause");
                    flag++;
                }
                else
                {
                    system("cls");
                    printf("No se ha podido agregar al empleado\n\n");
                    system("pause");

                }
    }


    if(flag==3)
    {

    id++;
    sprintf(auxId,"%d",id);

    system("cls");
    printf("%5s %10s %10s %10s\n" ,"ID","NOMBRE","HORAS","SUELDO");
    printf("\n%5d %10s %10s %10s\n" ,id,nombre,horasTrabajadas,sueldo);
    system("pause");

    confirm=employee_confirmation(rta,"Desea dar de alta al empleado? Ingrese si o no: ","Respuesta no valida",3);


    if(confirm==0 && strcmp(rta,"si")==0)
    {
        emp=employee_newParametros(auxId,nombre,horasTrabajadas,sueldo);

        if(emp!=NULL)
        {
            ll_add(pArrayListEmployee,emp);
            system("cls");
            printf("Se ha dado de alta al empleado correctamente\n\n");
            system("pause");
            retorno=1;
        }
        else
        {
            system("cls");
            printf("No se ha dado de alta al empleado porque ha ocurrido un error\n\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("No se ha dado de alta al empleado\n\n");
        system("pause");
    }

    }




    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp;
    int auxID;
    char rta[21];


    system("cls");
    auxID=employee_findEmployeeById(pArrayListEmployee);
    if(auxID!=-1)
    {

    emp=ll_get(pArrayListEmployee,auxID);

    employee_printEmployee(emp);

    if(employee_confirmation(rta,"Desea modificar a este empleado? Ingrese si o no: ","DATOS NO VALIDOS",3)==0 && strcmp(rta,"si")==0)
    {
        if(!employee_menuEdit(emp))
        {
            system("cls");
            printf("No se ha editado al empleado\n\n");
            system("pause");
        }
    }
    else
    {
        system("cls");
        printf("No se ha editado\n\n");
        system("pause");
    }



    }


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp;
    int auxID;
    char rta[21];

    auxID=employee_findEmployeeById(pArrayListEmployee);
    if(auxID!=-1)
    {
        emp=ll_get(pArrayListEmployee,auxID);
        if(emp!=NULL)
        {
            employee_printEmployee(emp);

            if(employee_confirmation(rta,"Desea dar de baja al empleado? Ingrese si o no: ","Respuesta incorrecta",3)==0 && strcmp(rta,"si")==0)
            {
                ll_remove(pArrayListEmployee,auxID);
                system("cls");
                printf("Se ha dado de baja al empleado correctamente\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("No se ha dado de baja\n\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("No se ha dado de baja porque ocurrio un error\n\n");
            system("pause");
        }



    }
    else
    {
        system("cls");
        printf("No se  ha dado de baja ya que no se ha encontrado al empleado\n\n");
        system("pause");
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{


    Employee *emp;
    int len;
    int i;
    int id;
    char nombre[4096];
    int horasT;
    int sueldo;

    len=ll_len(pArrayListEmployee);

    system("cls");
    printf("%5s %10s %10s %10s\n" ,"ID","NOMBRE","HORAS","SUELDO");

    for(i=0;i<len;i++)
    {

        if(i%50==0 && i!=0)
        {
            system("pause");
        }

        emp=ll_get(pArrayListEmployee,i);

        employee_getId(emp,&id);
        employee_getNombre(emp,nombre);
        employee_getHorasTrabajadas(emp,&horasT);
        employee_getSueldo(emp,&sueldo);

        printf("\n%5d %10s %10d %10d\n" ,id,nombre,horasT,sueldo);



    }


    return 1;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    employee_SortMenu(pArrayListEmployee);


    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee *emp=NULL;
    int i;
    int len;
    int id;
    char nombre[21];
    int horastTrabajadas;
    int sueldo;
    int retorno=0;

    pFile=fopen(path,"w");

    if(pFile!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        fprintf(pFile,"%s %s %s %s\n\n" ,"id","nombre","horasTrabajadas","sueldo");

        for(i=0;i<len;i++)
        {
            emp=ll_get(pArrayListEmployee,i);

            if(emp!=NULL)
            {
                employee_getId(emp,&id);
                employee_getNombre(emp,nombre);
                employee_getHorasTrabajadas(emp,&horastTrabajadas);
                employee_getSueldo(emp,&sueldo);

                fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horastTrabajadas,sueldo);
                retorno=1;
            }

        }
    }


    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* emp=NULL;
    int len;
    int i;
    int retorno=0;

    pFile=fopen(path,"wb");

    if(pFile!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            emp=ll_get(pArrayListEmployee,i);

            if(emp!=NULL)
            {
                fwrite(emp,sizeof(Employee),1,pFile);
                retorno=1;
            }
        }
    }



    fclose(pFile);
    return retorno;
}


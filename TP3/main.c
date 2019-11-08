#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "string.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int id=1000;
    int added;
    int binario=0;
    int texto=0;
    int loaded=0;

    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista en memoria


    do{
            system("cls");

            getInt(&option,"----------------------------------MENU------------------------------------\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                   "3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
                   "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                   "10. Salir\n\nIngrese la accion a realizar: ","\n\nOpcion no valida\n",1,10,100000);
        switch(option)
        {
            case 1:
                if(!binario && loaded==0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    if(ll_len(listaEmpleados)!=0)
                    {
                        system("cls");
                        printf("Se han cargado los empleados correctamente\n\n");
                        system("pause");
                        texto=1;
                        loaded=1;

                        break;
                    }

                    system("cls");
                    printf("Ha ocurrido un error y no se han podido cargar los empleados\n\n");
                    system("pause");
                    break;
                }

                system("cls");
                printf("No puede cargar en modo texto porque ya los ha cargado o los ha cargado en modo binario\n\n");
                system("pause");



                break;

            case 2:
                if(!texto && loaded==0)
                {
                    controller_loadFromBinary("data.csv",listaEmpleados);
                    if(ll_len(listaEmpleados)!=0)
                    {
                        system("cls");
                        printf("Se han cargado los empleados correctamente\n\n");
                        system("pause");
                        binario=1;
                        loaded=1;
                        break;
                    }

                    system("cls");
                    printf("Ha ocurrido un error y no se han podido cargar los empleados");
                    system("pause");
                    break;
                }

                system("cls");
                printf("No puede cargar en modo binario porque ya los ha cargado o los ha cargado en modo texto\n\n");
                system("pause");
                break;


            case 3:
                if(ll_len(listaEmpleados)!=0)
                {
                    if(binario)
                    {
                        system("cls");
                        printf("No es posible dar de alta empleados porque los ha cargado de manera bianaria\n\n");
                        system("pause");
                        break;
                    }
                    added=controller_addEmployee(listaEmpleados,id);

                    if(added)
                    {
                        id++;
                        break;
                    }
                }
                else
                {
                    system("cls");
                    printf("Debe cargar a los empleados en modo texto para poder dar de alta a un nuevo empleado\n\n");
                    system("pause");
                }


                break;

            case 4:
                if(ll_len(listaEmpleados)!=0)
                {
                    if(binario)
                    {
                        system("cls");
                        printf("No es posible editar a los empleados porque los ha cargado de manera bianaria\n\n");
                        system("pause");
                        break;
                    }
                    controller_editEmployee(listaEmpleados);
                    break;
                }

                system("cls");
                printf("No es posible editar porque no hay empleados cargados o porque los ha cargado en modo binario\n\n");
                system("pause");

                break;

            case 5:
                if(ll_len(listaEmpleados)!=0)
                {
                    if(binario)
                    {
                        system("cls");
                        printf("No es posible remover empleados porque los ha cargado de manera bianaria\n\n");
                        system("pause");
                        break;
                    }
                    controller_removeEmployee(listaEmpleados);
                    break;
                }

                system("cls");
                printf("No es posible eliminar porque no hay empleados cargados\n\n");
                system("pause");


                break;

            case 6:
                if(ll_len(listaEmpleados)!=0)
                {
                    if(binario)
                    {
                        system("cls");
                        printf("No es posible listar a los empleados porque los ha cargado de manera binaria\n\n");
                        system("pause");
                        break;
                    }
                    controller_ListEmployee(listaEmpleados);
                    break;

                }
                system("cls");
                printf("No es posible ordenar porque no hay empleados cargados\n\n");
                system("pause");

                break;

            case 7:
                if(ll_len(listaEmpleados)!=0)
                {
                    if(binario)
                    {
                        system("cls");
                        printf("No es posible ordenar a los empleados porque los ha cargado de manera bianaria\n\n");
                        system("pause");
                        break;
                    }
                    controller_sortEmployee(listaEmpleados);
                    break;
                }

                system("cls");
                printf("No es posible listar porque no hay empleados cargados\n\n");
                system("pause");


                break;

            case 8:
                if(ll_len(listaEmpleados)!=0)
                {
                    if(binario)
                    {
                        system("cls");
                        printf("No es posible guardar a los empleados en modo texto porque los ha cargado de manera bianaria\n\n");
                        system("pause");
                        break;
                    }


                    if(controller_saveAsText("data.csv",listaEmpleados))
                    {
                        system("cls");
                        printf("Los datos se han guardado correctamente\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("No se han guardado los datos\n\n");
                        system("pause");
                        break;
                    }
                }

                system("cls");
                printf("No se puede guardar porque no hay empleados cargados\n\n");
                system("pause");
                break;

            case 9:
                if(controller_saveAsBinary("data.csv",listaEmpleados))
                {
                    system("cls");
                    printf("Los datos se han guardado correctamente\n\n");
                    system("pause");
                    break;
                }
                system("cls");
                printf("No se han guardado los datos\n\n");
                system("pause");

                break;

            case 10:
                break;


        }
    }while(option != 10);
    return 0;
}

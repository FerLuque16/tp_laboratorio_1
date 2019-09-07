#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "calcu.h"

int main()
{
    float op1=0;
    float op2=0;
    int opcion;
    int seguir;
    float resSuma;
    float resResta;
    float resProducto;
    float resDivision;
    float resFactorial1;
    float resFactorial2;
    int flag1=0;
    int flag2=0;
    int flag3=0;


    do
    {

        system ("cls");

        printf("---MENU DE OPCIONES---\n\n");

        printf("1.  Ingresar primer operando (A=%.2f)\n" ,op1);
        printf("2.  Ingresar segundo operando (B=%.2f)\n" ,op2);
        printf("3.  Calcular todas las operaciones\n");
        printf("4.  Informar resultados\n");
        printf("5.  Salir\n");

        printf("Ingrese la accion a realizar :");
        scanf("%d",&opcion);

        switch(opcion)
        {

        case 1 :
            system("cls");
            printf("Ingrese el primer operando\n");
            scanf("%f" ,&op1);
            flag1=1;
            break;

        case 2 :
            system ("cls");
            printf("Ingrese el segundo operando\n");
            scanf("%f" ,&op2);
            flag2=1;
            break;

        case 3 :

            if(flag1==1 && flag2==1)
            {

            resSuma=suma(op1,op2);
            resResta=resta(op1,op2);

            if(op1<0)
            {
                system("cls");
                printf("No es posible sacar el factorial de %.2f ya que es negativo\n" ,op1);
                system("pause");
            }
            else
            {
                resFactorial1=factorial(op1);
            }

            if(op2<0)
            {
                system("cls");
                printf("No es posible sacar el factorial de %.2f ya que es negativo\n" ,op2);
                system("pause");
            }
            else
            {
                resFactorial2=factorial(op2);
            }

            if(op2==0)
            {
                system("cls");
                printf("No es posible dividir entre 0\n");
                system("pause");

            }
            else
            {
                resDivision=division(op1,op2);
                resProducto=producto(op1,op2);
            }

            flag3=1;
            break;
            }

            else
            {
                system("cls");
                printf("No se puede realizar esta operacion porque no ingreso ambos valores\n");
                system("pause");
                break;

            }

        case 4 :
            if(flag3==1)
            {
                system("cls");

                printf("El resultado de %.2f+%.2f es: %.2f\n" ,op1,op2,resSuma);
                printf("El resultado de %.2f-%.2f es: %.2f\n" ,op1,op2,resResta);
                printf("El resultado de %.2f/%.2f es: %.2f\n" ,op1,op2,resDivision);
                printf("El resultado de %.2f*%.2f es: %.2f\n" ,op1,op2,resProducto);
                printf("El factorial de %.2f es %.2f y el factorial de %.2f es %.2f\n" ,op1,resFactorial1,op2,resFactorial2);
                system("pause");
                op1=0;
                op2=0;
                flag1=0;
                flag2=0;
                flag3=0;


                break;
            }

            if(flag3!=1)
            {
                system("cls");
                printf("No se pueden mostrar los resultados ya que no se realizo ninguna operacion\n");
                system("pause");
                break;
            }

        case 5 :
            seguir=1;
            break;

        default:
            system("cls");
            printf("Esa opcion no es valida\n");
            system("pause");
            break;

        }

    }
    while(seguir != 1);
    return 0;
}

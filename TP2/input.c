#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "input.h"

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    int auxInt;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit)
        {
            printf("%s",message);
            setbuf(stdin,NULL);
            scanf("%d",&auxInt);
			if(auxInt >= lowLimit && auxInt <= hiLimit)
                {
                    retorno = 0;
                    *input = auxInt;

                }
			else
                {
                    printf("%s",eMessage);
                    system("pause");
                }
        }



    return retorno;
}

float getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    float auxInt;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit)
        {
            printf("%s",message);
            setbuf(stdin,NULL);
            scanf("%f",&auxInt);
			if(auxInt >= lowLimit && auxInt <= hiLimit)
                {
                    retorno = 0;
                    *input = auxInt;

                }
			else
                {
                    printf("%s",eMessage);
                    system("pause");
                }
        }


    return retorno;
}

char getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    char auxChar;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit)
    {
            printf("%s",message);
            setbuf(stdin,NULL);

            if(scanf("%c",&auxChar)!=0)
                {
                    if(auxChar >= lowLimit && auxChar <= hiLimit)
                        {
                            retorno = 0;
                            *input=auxChar;
                        }
                    else
                        {
                            printf("%s" ,eMessage);
                            system("pause");
                        }
                }
            else
                {
                    printf("%s" ,eMessage);
                    system("pause");
                }


    }


    return retorno;
}

char getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    setbuf(stdin,NULL);

    int retorno=-1;
    char auxStr[4096];
    int i;
    int flag=0;

    if(input!=NULL && message!=NULL && eMessage!=NULL && lowLimit<hiLimit)
    {
        printf("%s" ,message);
        setbuf(stdin,NULL);
        fgets(auxStr,sizeof(auxStr),stdin);
        auxStr[strlen(auxStr)-1] = '\0';

        for(i=0;i<strlen(auxStr);i++)
            {
                if(isdigit(auxStr[i]))
                {
                    flag=1;
                    break;

                }
            }

        if(strlen(auxStr)>=lowLimit && strlen(auxStr)<=hiLimit && flag==0)
            {
                strcpy(input,auxStr);
                retorno=0;
            }
        else
            {
                printf("%s" ,eMessage);
                system("pause");
            }
    }



    return retorno;
}

int getRandomNumber(int desde, int hasta, int inicio)
{
    int randomNumber;
    if (inicio)
    {
        srand (time(NULL));
    }

    randomNumber = desde + (rand() % (hasta + 1 - desde));

return randomNumber;
}







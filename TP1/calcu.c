/**
* \brief Realiza la suma de ambos operandos ingresados por el usuario
* \param num1 Recibe el primer operando ingresado por el usuario
* \param num2 Recibe el segundo operando ingresado por el usuario
* \return El resultado total de la suma

*
*/
float suma(float num1,float num2)
{
    float res;

    res=num1+num2;

    return res;
}

/**
* \brief Realiza la resta de ambos operandos ingresados por el usuario
* \param num1 Recibe el primer operando ingresado por el usuario
* \param num2 Recibe el segundo operando ingresado por el usuario
* \return El resultado total de la resta

*
*/
float resta (float num1,float num2)
{
    float res;

    res=num1-num2;

    return res;
}

/**
* \brief Realiza el producto de ambos operandos ingresados por el usuario
* \param num1 Recibe el primer operando ingresado por el usuario
* \param num2 Recibe el segundo operando ingresado por el usuario
* \return El resultado total del producto

*
*/

float producto (float num1,float num2)
{
    float res;

    res=num1*num2;

    return res;
}

/**
* \brief Realiza la division de ambos operandos ingresados por el usuario
* \param num1 Recibe el primer operando ingresado por el usuario
* \param num2 Recibe el segundo operando ingresado por el usuario
* \return El resultado total de la division

*
*/

float division (float num1,float num2)
{
    float res;

    res=num1/num2;

    return res;
}

/**
* \brief Realiza el factorial del numero recibido
* \param num1 Recibe el operando ingresado por el usuario, ya sea el primero o el segundo
* \return El resultado del factorial del operando recibido. Si el operando es 0, la funcion retorna el valor 1

*
*/

float factorial (float num1)
{
    float res=1;
    int i;

    i=num1;

    if(num1==0)
    {
        res=1;
    }
    else
    {


    for(i=1;i<=num1;i++)
    {
        res=res*i;

    }
    }
    return res;
}

#include <stdio.h>
#include <stdlib.h>

void cambiarSigno(int *num);
void cambiarValor(int *p, int *q);
void cargarEdad(int *edad);
int validarEdad(int edad);
int division(int divisor, int dividendo, int *res);
float convertirTiempo(int tiempoS, float *tiempo);

int main()
{
//PUNTO 1
    int num=2;
    printf("%i\n", num);
    cambiarSigno(&num);
    printf("%i\n\n", num);

//PUNTO 2
    int a=0, b=0;
    cambiarValor(&a, &b);
    printf("\n%i\n%i\n", a, b);
//PUNTO 3
    int edad;
    cargarEdad(&edad);
//PUNTO 4
    int divisor=7, dividendo=12, resu=0;
    printf("El resto de la division es: %i\n", division(divisor, dividendo, &resu));
    printf("Y el resultado es: %i\n", resu);
//PUNTO 5
    int tiempoSegundos=3600;
    float tiempo=0;
    printf("El tiempo en horas es de: %.2f\n", convertirTiempo(tiempoSegundos, &tiempo));
    printf("Y el tiempo en minutos es de: %.2f", tiempo);

    return 0;
}

/*
Realizar una función que reciba un número positivo entero por parámetro por
referencia, y cambie su signo a negativo.

*/
void cambiarSigno(int *num1)
{
    *num1=*num1*-1;
}

/*
Realizar una función que reciba dos números enteros por parámetro por
referencia, y que dentro de la función el usuario cargue sus valores.
*/

void cambiarValor(int *p, int *q)
{
    printf("Ingrese el primer valor: \n");
    scanf("%i", p);
    printf("Ingrese el segundo valor: \n");
    scanf("%i", q);
 }

/*
Hacer la función “validar edad” que reciba por parámetro un puntero a la
variable edad (un puntero a entero). La función debe permitir que el usuario
del sistema ingrese una edad y luego verificar que la edad sea mayor a 0 y
menor o igual a 18. Si la edad ingresada no respeta esos requisitos, se debe
informar al usuario esta situación (que el valor ingresado es incorrecto y cuál
es el requisito correcto) y se le debe volver a pedir el dato al usuario. Hasta
tanto no lo ingrese correctamente, no debe salirse del bucle. Como resultado
de la función y del uso del puntero, en la variable original en el Main debe
quedar ingresado el dato de manera tal que cumpla con los requisitos.
*/

void cargarEdad(int *edad)
{
    int aux=0;
    while(aux!=1)
    {
        printf("Ingrese una edad: \n");
        scanf("%i", edad);
        aux = validarEdad(*edad);
        if(aux!=1)
        {
            printf("La edad ingresada es invalida, la edad tiene que ser mayor a 0 y menor o igual a 18!!\n");
        }
    }
}

int validarEdad(int edad)
{
    int aux=0;
    if(edad>0 && edad<=18)
    {
        aux=1;
    }
    return aux;
}

/*
Hacer la función “dividir” que reciba por parámetro dos números enteros:
dividendo y divisor. La función debe “retornar” el resultado de la
división y el resto de la misma, ambos como enteros (Ojo, solo puede haber
un return, sólo puede retornarse un valor, pensar bien cómo lograr ese
resultado).
*/

int division(int divisor, int dividendo, int *res)
{
    int aux=0;
    if(dividendo%divisor!=0)
    {
        aux = dividendo%divisor;
        *res = dividendo/divisor;
    }
    else
    {
        *res = dividendo/divisor;
    }
    return aux;
}

/*
Hacer la función “convertirTiempo”, que reciba un tiempo en segundos. La
función debe “retornar” dicho tiempo convertido a minutos y convertido a
horas, ambos resultados como enteros (Ojo, solo puede haber un return, sólo
puede retornarse un valor, pensar bien cómo lograr ese resultado)
*/

float convertirTiempo(int tiempoS, float *tiempo)
{
    float aux=0;
    *tiempo = tiempoS/60;
    aux = *tiempo/60;
    return aux;
}

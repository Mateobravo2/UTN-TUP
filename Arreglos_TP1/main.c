#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void menu();
//PUNTO 1
int valoresValidosInt(int vec1[], int dimension);
//PUNTO 2
void mostrarElementos(int vec1[], int validos);
//PUNTO 3
int calcularSuma(int vec1[], int validos);
//PUNTO 4
void copiarArregloEnPila(int vec1[], int validos, Pila *pilita);
//PUNTO 5
int valoresValidosFloat(float vec2[], int dimension);
void mostrarElementosFloat(float vec2[], int validos);
float sumaArregloFloat(float vec2[], int validos);
//PUNTO 6
int encontrarCaracter(char vec3[], int validos, int car);
//PUNTO 7
int valoresValidosChar(char vec3[], int dimension);
void mostrarElementosChar(char vec3[], int validos);
int insertarCaracter(char vec3[], char car, int validos);
//PUNTO 8
int maximoCaracter(char vec3[], int validos);
//PUNTO 9
int verificarCapicuaInt();


int main()
{
    menu();
    return 0;
}

void menu()
{
    int op=0, vec1[100], validos=0, aux=0;
    float vec2[100], aux2=0;
    char vec3[100], car, aux3;
    do
    {
        printf("_____________________________________\n");
        printf("|[1]  CARGAR ARREGLO                |\n");
        printf("|[2]  MOSTRAR ARREGLO               |\n");
        printf("|[3]  CALCULAR SUMA                 |\n");
        printf("|[4]  COPIAR ARREGLO A PILA         |\n");
        printf("|[5]  CARGAR, MOSTRAR Y SUMAR FLOAT |\n");
        printf("|[6]  BUSCAR ELEMENTO               |\n");
        printf("|[7]  INSERTAR CARACTER EN ARREGLO  |\n");
        printf("|[8]  |\n");
        printf("|[9]  |\n");
        printf("|[10] |\n");
        printf("|[11] |\n");
        printf("|[12] |\n");
        printf("|[13] |\n");
        printf("-------------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
            default:
                {
                    printf("~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~");
                }break;
            case 0:
                {
                    printf("- - - FINALIZANDO EL PROGRAMA - - -");
                }break;
            case 1:
                {
                    validos = valoresValidosInt(vec1, 3);
                    printf("\nSe cargaron %i elementos en el arreglo\n", validos);
                    system("pause");
                    system("cls");
                }break;
            case 2:
                {
                    mostrarElementos(vec1, validos);
                    system("pause");
                    system("cls");
                }break;
            case 3:
                {
                    aux = calcularSuma(vec1, validos);
                    printf("\nLa suma de todos los valores del arreglo es: %i\n", aux);
                    system("pause");
                    system("cls");
                }break;
            case 4:
                {
                    Pila pilita;
                    inicpila(&pilita);
                    copiarArregloEnPila(vec1, validos, &pilita);
                    mostrar(&pilita);
                    system("pause");
                    system("cls");
                }break;
            case 5:
                {
                    validos = valoresValidosFloat(vec2, 100);
                    mostrarElementosFloat(vec2, validos);
                    aux2=sumaArregloFloat(vec2, validos);
                    printf("La suma de todos los elementos del arreglo es: %.2f\n", aux2);
                    system("pause");
                    system("cls");
                }break;
            case 6:
                {
                    int flag=0;
                    printf("Que elemento desea encontrar en el arreglo?: ");
//                    fflush(stdin);
                    scanf(" %c", &car);
                    aux = car;
                    flag = encontrarCaracter(vec3, 5, aux);
                    if(flag == 1)
                    {
                        printf("\nEl elemento "" %c ""  se encuentra en el arreglo\n", car);
                    }else
                    {
                        printf("\nEl elemento "" %c ""  NO se encuentra en el arreglo\n", car);
                    }
                    system("pause");
                    system("cls");
                }break;
            case 7:
                {
                    validos = valoresValidosChar(vec3, 20);
                    printf("\nQue elemento desea insertar en el arreglo?: ");
//                    fflush(stdin);
                    scanf(" %c", &car);
                    mostrarElementosChar(vec3, validos);
                    validos = insertarCaracter(vec3, car, validos);
                    mostrarElementosChar(vec3, validos);
                    system("pause");
                    system("cls");
                }break;
            case 8:
                {
                    validos = valoresValidosChar(vec3, 20);
                    aux3 = maximoCaracter(vec3, validos);
                    printf("El maximo caracter del arreglo es: %c (%i)\n", aux3, aux3);
                    system("pause");
                    system("cls");
                }break;
            case 9:
                {
                    printf("Que tipo de arreglo desea ingresar?:\n");
                    printf("(Enteros / 1  |  Flotantes / 2  |  Caracteres / 3)\n");
                    scanf("%i", &aux);
                    if(aux == 1)
                    {
                        validos = valoresValidosInt(vec1, 100);
                        aux = verificarCapicuaInt(vec1, validos);
                    }
                    else if(aux == 2)
                    {

                    }
                    else if(aux == 3)
                    {

                    }
                    else
                    {
                        printf("~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~");
                    }break;
                }
            case 10:
                {

                }break;
            case 11:
                {

                }break;
            case 12:
                {

                }break;
            case 13:
                {

                }break;

        }
    }while(op!=0);

}

/*
PUNTO 1
Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
*/

int valoresValidosInt(int vec1[], int dimension)
{
    int i=0;
    char aux2;
    do
    {
        printf("Ingrese el valor que quiere ingresar: ");
        scanf("%i", &vec1[i]);
        i++;
        if(i < dimension)
        {
        printf("\nQuiere seguir ingresando valores? s/n: ");
        fflush(stdin);
        scanf("%c", &aux2);
        }
        if(aux2!='s' && aux2!='n')
        {
            printf("\n~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~\n");
        }
    }while(aux2 != 'n' && i < dimension);
    return i;
}

/*
PUNTO 2
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y los muestre por pantalla.
*/

void mostrarElementos(int vec1[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("ELEMENTO %i    ", i);
    }
    printf("\n");
    for(int i=0; i<validos; i++)
    {
        printf("   | %i |      ", vec1[i]);
    }
    printf("\n");
}

/*
PUNTO 3
Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y calcule la suma de sus elementos.
*/

int calcularSuma(int vec1[], int validos)
{
    int suma=0;
    for(int i=0; i < validos; i++)
    {
        suma += vec1[i];
    }
    return suma;
}

/*
PUNTO 4
Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
*/
void copiarArregloEnPila(int vec1[], int validos, Pila *pilita)
{
    for(int i=0; i < validos; i++)
    {
        apilar(pilita, vec1[i]);
    }
}

/*
PUNTO 5
Realizar una función que sume los elementos de un arreglo de números reales (float) de
dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
tipo de dato asociado al arreglo)
*/

int valoresValidosFloat(float vec2[], int dimension)
{
    int i=0;
    char aux2;
    do
    {
        printf("Ingrese el valor que quiere ingresar: ");
        scanf("%f", &vec2[i]);
        i++;
        if(i < dimension)
        {
        printf("\nQuiere seguir ingresando valores? s/n: ");
        fflush(stdin);
        scanf("%c", &aux2);
        }
        if(aux2!='s' && aux2!='n')
        {
            printf("\n~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~\n");
        }
    }while(aux2!='n' && i < dimension);
    return i;
}

void mostrarElementosFloat(float vec2[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("  - %.2f -  ", vec2[i]);
    }
    printf("\n");
}

float sumaArregloFloat(float vec2[], int validos)
{
    float suma=0;
    for(int i=0; i < validos; i++)
    {
        suma = suma + vec2[i];
    }
    return suma;
}

/*
PUNTO 6
Realizar una función que indique si un elemento dado se encuentra en un arreglo de
caracteres.
*/

int encontrarCaracter(char vec3[], int validos, int car)
{
    int flag=0, i=0;
    while(i < validos && flag ==0)
    {
        if(vec3[i] == car)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}

/*
PUNTO 7
Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
conservando el orden.
*/

int valoresValidosChar(char vec3[], int lim)
{
    int i=0;
    char aux2;
    do
    {
        printf("Ingrese el valor que quiere ingresar: ");
//      fflush(stdin);
        scanf(" %c", &vec3[i]);
        i++;
        if(i<lim)
        {
            printf("\nQuiere seguir ingresando valores? s/n: ");
    //      fflush(stdin);
            scanf(" %c", &aux2);

            while(aux2!='s' && aux2!='n')
            {
                printf("\n~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~\n");
                printf("\nQuiere seguir ingresando valores? s/n: ");
    //          fflush(stdin);
                scanf(" %c", &aux2);
            }
        }

    }while(aux2!='n' && i<lim);
    return i;
}

void mostrarElementosChar(char vec3[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("  - %c -  ", vec3[i]);
    }
    printf("\n");
}

int insertarCaracter(char vec3[], char car, int validos)
{
    char aux;
    for(int i=0; i < validos; i++)
    {
        if(car <= vec3[i])
        {
            aux = vec3[i];
            vec3[i] = car;
            car = aux;
        }
    }
    vec3[validos] = car;
    validos++;
    return validos;
}

/*
PUNTO 8
Realizar una función que obtenga el máximo carácter de un arreglo dado.
*/

int maximoCaracter(char vec3[], int validos)
{
    int i=0;
    char maximo = 'a';
    do
    {
        if(maximo <= vec3[i])
        {
            maximo = vec3[i];
        }
        i++;
    }while(i < validos);
    return maximo;
}

/*
PUNTO 9
Realizar una función que determine si un arreglo es capicúa.
*/

int verificarCapicuaInt(int vec1[], int validos)
{
    int aux=0;



    return aux;
}


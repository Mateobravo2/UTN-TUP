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
int verificarCapicuaInt(int vec1[], int validos);
//PUNTO 10
void invertirArreglo(int vec1[], int validos);
//PUNTO 11
void ordenPorSeleccion(int vec1[], int validos);
int buscarMenor(int vec1[], int i, int validos);
void ordenPorInsercion(int vec1[], int validos);
void insertar(int vec1[], int posInic, int dato);
//PUNTO 12
int juntarArreglos(char vecChar1[], char vecChar2[], char vec3[], int validos, int aux);
//PUNTO 13
int sumarAnteriores(int vec1[], int validos);
void insertarSumaAnteriores(int vecInt[], int vecSuma[], int validos);

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
        printf("                                                _____________________________________\n");
        printf("                                                |[1]  CARGAR ARREGLO                |\n");
        printf("                                                |[2]  MOSTRAR ARREGLO               |\n");
        printf("                                                |[3]  CALCULAR SUMA                 |\n");
        printf("                                                |[4]  COPIAR ARREGLO A PILA         |\n");
        printf("                                                |[5]  CARGAR, MOSTRAR Y SUMAR FLOAT |\n");
        printf("                                                |[6]  BUSCAR ELEMENTO               |\n");
        printf("                                                |[7]  INSERTAR CARACTER EN ARREGLO  |\n");
        printf("                                                |[8]  VER MAXIMO CARACTER           |\n");
        printf("                                                |[9]  VERIFICAR CAPICUA             |\n");
        printf("                                                |[10] INVERTIR ARREGLO              |\n");
        printf("                                                |[11] ORDENAR ARREGLOS              |\n");
        printf("                                                |[12] JUNTAR ARREGLOS               |\n");
        printf("                                                |[13] SUMAR ANTERIORES              |\n");
        printf("                                                |[0]           SALIR                |\n");
        printf("                                                -------------------------------------\n");
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
                }
                else
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
                int auxiliar=0;
                validos = valoresValidosInt(vec1, 100);
                auxiliar = verificarCapicuaInt(vec1, validos);
                if(auxiliar == 1)
                {
                    printf("\nEl arreglo es capicua !!!\n");
                    mostrarElementos(vec1, validos);
                }
                else
                {
                    printf("\n- El arreglo no es capicua -\n");
                    mostrarElementos(vec1, validos);
                }
                system("pause");
                system("cls");
            }break;
            case 10:
            {
                validos = valoresValidosInt(vec1, 100);
                mostrarElementos(vec1, validos);
                invertirArreglo(vec1, validos);
                mostrarElementos(vec1, validos);
                system("pause");
                system("cls");
            }break;
            case 11:
            {
                validos = valoresValidosInt(vec1, 100);
                system("cls");
                printf("Como desea ordenar su arreglo? ");
                printf("\nSELECCION (1)      INSERCION (2):\n");
                scanf("%i", &aux);
                if(aux == 1)
                {
                    ordenPorSeleccion(vec1, validos);
                    mostrarElementos(vec1, validos);
                }
                else if(aux == 2)
                {
                    ordenPorInsercion(vec1, validos);
                    mostrarElementos(vec1, validos);
                }
                else
                {
                    printf("\n~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~\n");
                }
                system("pause");
                system("cls");
            }break;
            case 12:
            {
                int validos2=0;
                char vecChar1[100], vecChar2[100];
                validos = valoresValidosChar(vecChar1, 100);
                aux = valoresValidosChar(vecChar2, 100);
                mostrarElementosChar(vecChar1, validos);
                mostrarElementosChar(vecChar2, aux);
                validos2 = juntarArreglos(vecChar1, vecChar2, vec3, validos, aux);
                mostrarElementosChar(vec3, validos2);
                system("pause");
                system("cls");
            }break;
            case 13:
            {
                int vecInt1[100] = {1,5,6,7,8};
                int vecSuma[100];
                insertarSumaAnteriores(vecInt1, vecSuma, 5);
                printf("\nARREGLO\n");
                mostrarElementos(vecInt1, 5);
                printf("\nSUMA DE ANTERIORES\n");
                mostrarElementos(vecSuma, 5);
                system("pause");
                system("cls");
            }break;
        }
    }
    while(op!=0);
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
//        fflush(stdin);
            scanf(" %c", &aux2);
        }
        if(aux2!='s' && aux2!='n')
        {
            printf("\n~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~\n");
        }
    }
    while(aux2 != 'n' && i < dimension);
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
    }
    while(aux2!='n' && i < dimension);
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
        fflush(stdin);
        scanf("%c", &vec3[i]);
        i++;
        if(i<lim)
        {
            printf("\nQuiere seguir ingresando valores? s/n: ");
            fflush(stdin);
            scanf("%c", &aux2);

            while(aux2!='s' && aux2!='n')
            {
                printf("\n~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~\n");
                printf("\nQuiere seguir ingresando valores? s/n: ");
                fflush(stdin);
                scanf("%c", &aux2);
            }
        }

    }
    while(aux2!='n' && i<lim);
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
    }
    while(i < validos);
    return maximo;
}

/*
PUNTO 9
Realizar una función que determine si un arreglo es capicúa.
PREGUNTAR QUE TIPOS DE ARREGLOS (INT FLOAT CHAR O TODOS)
*/

int verificarCapicuaInt(int vec1[], int validos)
{
    int aux=1, i=0, i2=validos-1;
    while(i < validos && aux != 0)
    {
        if(vec1[i] == vec1[i2])
        {
            aux = 1;
        }
        else
        {
            aux = 0;
        }
        i2--;
        i++;
    }
    return aux;
}

/*
PUNTO 10
Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)
PREGUNTAR QUE TIPOS DE ARREGLOS (INT FLOAT CHAR O TODOS)
*/

void invertirArreglo(int vec1[], int validos)
{
    int aux = 0, aux2 = 0;
    for(int i = 0; i < validos; i++)
    {
        aux = vec1[i];
        aux2 = vec1[validos-1];
        vec1[validos-1] = aux;
        vec1[i] = aux2;
        validos--;
    }
}

/*
PUNTO 11
Ordenar un arreglo según los siguientes métodos:
a. Seleccion
b. Inserción
*/

void ordenPorSeleccion(int vec1[], int validos)
{
    int men, aux, i=0;
    while(i < validos-1)
    {
        men = buscarMenor(vec1, i, validos);
        aux = vec1[men];
        vec1[men] = vec1[i];
        vec1[i] = aux;
        i++;
    }
}

int buscarMenor(int vec1[], int inic, int validos)
{
    int men = vec1[inic];
    int posMenor = inic;
    int i = inic+1;
    while(i < validos)
    {
        if(men > vec1[i])
        {
            men = vec1[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenPorInsercion(int vec1[], int validos)
{
    int i = 0;
    while(i < validos-1)
    {
        insertar(vec1, i, vec1[i+1]);
        i++;
    }
}

void insertar(int vec1[], int posInic, int dato)
{
    int i = posInic;
    while(i >= 0 && dato < vec1[i])
    {
        vec1[i+1] = vec1[i];
        i--;
    }
    vec1[i+1] = dato;
}

/*
PUNTO 12
Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
los dos primeros intercalados, de manera que quede un arreglo también ordenado
alfabéticamente.
*/

int juntarArreglos(char vecChar1[], char vecChar2[], char vec3[], int val1, int val2)
{
    int i = 0, j = 0, k = 0;
    do
    {
        if(vecChar1[i] <= vecChar2[j])
        {
            vec3[k] = vecChar1[i];
            i++;
        }
        else
        {
            vec3[k] = vecChar2[j];
            j++;
        }
        k++;
    }
    while(k < (val1+val2) && i < val1 && j < val2);

    while(i < val1)
    {
        printf("\nA\n");
        vec3[k] = vecChar1[i];
        i++;
        k++;
    }

    while(j < val2)
    {
        vec3[k] = vecChar2[j];
        j++;
        k++;
    }
    return k;
}

/*
PUNTO 13
Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del
contenido de todo los elementos anteriores al índice actual: {1,6,12,19,27}.
*/

int sumarAnteriores(int vec1[], int limite)
{
    int i = 0, suma = 0 ;
    while(i <= limite)
    {
        suma = suma + vec1[i];
        i++;
    }
    return suma;
}

void insertarSumaAnteriores(int vecInt[], int vecSuma[], int validos)
{
    int i=0, suma=0;
    while(i < validos)
    {
        suma = sumarAnteriores(vecInt, i);
        vecSuma[i] = suma;
        i++;
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 5

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
}Alumno;


void menu();
//PUNTO 1
void aumentarDimDeArregloDinamico(int** arr, int cant);
int* crearArregloDin(int** arr, int arrInt[], int validos);
int contarPares(int arrInt[], int validos);
void pasarParesArregloDin(int arrDin[], int arrInt[], int validos);
void mostrarArr(int arr[], int validos);
//PUNTO 2


int main()
{
    menu();
    return 0;
}

void menu()
{
    int arrInt[DIM] = {2, 13, 24, 33, 52};
    int *arrDin;
    int op, aux = 0;
    do
    {
        printf("Ingrese el ejercicio que quiere probar: \n");
        printf("______________________________________________\n");
        printf("|[1] PASAR PARES A ARREGLO DE TAMANIO JUSTO  |\n");
        printf("|[2]|\n");
        printf("|[3]|\n");
        printf("|[4]|\n");
        printf("|[5]|\n");
        printf("|[6]|\n");
        printf("|[0] FINALIZAR PROGRAMA |\n");
        printf("----------------------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
        default:
            {
                printf("~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~");
                system("pause");
                system("cls");
            }break;
        case 1:
            {
                arrDin = crearArregloDin(&arrDin, arrInt, DIM);
                mostrarArr(arrInt, DIM);
                aux = contarPares(arrInt, DIM);
                printf("\n");
                mostrarArr(arrDin, aux);
                system("pause");
                system("cls");
            }break;
        case 2:
            {

            }break;
        case 0:
            {
                printf("- - - FINALIZANDO EL PROGRAMA - - -");
            }break;
        }
    }while(op != 0);
}

//PUNTO 1
int* crearArregloDin(int** arr, int arrInt[], int validos)
{
    int cant = 0;
    int* arreglo2 = (int*) malloc(sizeof(int));
    cant = contarPares(arrInt, validos);
    aumentarDimDeArregloDinamico(&arreglo2, cant);
    pasarParesArregloDin(arreglo2, arrInt, validos);
    if(arreglo2 != NULL)
    {
        (*arr) = arreglo2;
    }
    return *arr;
}

void aumentarDimDeArregloDinamico(int** arr, int cant)
{
    int* arreglo2 = (int*) realloc((*arr), sizeof(int)*cant);
    if(arreglo2 != NULL)
    {
        (*arr) = arreglo2;
    }
}

int contarPares(int arrInt[], int validos)
{
    int i = 0, cant = 0;
    while(i < validos)
    {
        if(arrInt[i]%2==0)
        {
            cant++;
        }
        i++;
    }
    return cant;
}

void pasarParesArregloDin(int arrDin[], int arrInt[], int validos)
{
    int i = 0, j = 0;
    while(i < validos)
    {
        if(arrInt[i]%2==0)
        {
            arrDin[j] = arrInt[i];
            j++;
        }
        i++;
    }
}

void mostrarArr(int arr[], int validos)
{
    int i = 0;
    while(i < validos)
    {
        printf("Elemento %i: | %i |\n", i, arr[i]);
        i++;
    }
}

//PUNTO 2

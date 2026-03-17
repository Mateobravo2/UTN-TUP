#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void menu();
void cargarValores(int aux, Pila* pilita);
void pasarValores(Pila *pilita, Pila *pilaux);
void conservarOrden(Pila *pilita, Pila *pilaux, Pila *pila2);
void invertirPila(Pila *pilita, Pila *pilaux, Pila *pila2);

int main()
{

    menu();
    return 0;
}

void menu()
{
    int op;
    int aux=0;
    Pila pilita;
    inicpila(&pilita);
    Pila pilaux;
    inicpila(&pilaux);
    Pila pila2;
    inicpila(&pila2);
    do
    {
        printf("________________________________\n");
        printf("[1] FUNCION DE CARGA            \n");
        printf("[2] PASAR DE UNA PILA A OTRA    \n");
        printf("[3] PASAR CONSERVANDO VALORES   \n");
        printf("[4] INVERTIR PILA               \n");
        printf("[5]                             \n");
        printf("[6]                             \n");
        printf("--------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
            case 0:
            {
                printf("~ ~ ~ FINALIZANDO PROGRAMA ~ ~ ~");
            }break;
            case 1:
            {
                printf("Cuantos valores desea ingresar en la pila?\n");
                scanf("%i", &aux);
                cargarValores(aux, &pilita);
                system("cls");
            }break;

            case 2:
            {
                pasarValores(&pilita, &pilaux);
            }break;

            case 3:
            {
                conservarOrden(&pilita, &pilaux, &pila2);
            }break;

            case 4:
            {
                invertirPila(&pilita, &pilaux, &pila2);
            }break;

            case 5:
            {

            }break;
        }
    }while(op!=0);
}

void cargarValores(int aux, Pila* pilita)
{
    while(aux>0)
    {
        leer(pilita);
        aux--;
    }
}

void pasarValores(Pila *pilita, Pila *pilaux)
{
    while(pilavacia(pilita)==0)
    {
        apilar(pilaux, desapilar(pilita));
    }
}

void conservarOrden(Pila *pilita, Pila *pilaux, Pila *pila2)
{
    pasarValores(pilita, pilaux);
    pasarValores(pilaux, pila2);
}

void invertirPila(Pila *pilita, Pila *pilaux, Pila *pila2)
{
    conservarOrden(pilita, pilaux, pila2);
    pasarValores(pila2, pilita);
}


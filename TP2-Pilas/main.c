#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void menu();
void cargarValores(int aux, Pila* pilita);
void pasarValores(Pila *pilita, Pila *pila2);
void conservarOrden(Pila *pilita, Pila *pila2);
void invertirPila(Pila *pilita);
int busqueda(Pila pilita, int aux);
void eliminar(Pila *pilita, int aux);


int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    int aux=0, aux2=0;
    Pila pilita;
    inicpila(&pilita);
    Pila pila2;
    inicpila(&pila2);
    do
    {
        printf("________________________________\n");
        printf("[1] FUNCION DE CARGA            \n");
        printf("[2] PASAR DE UNA PILA A OTRA    \n");
        printf("[3] PASAR CONSERVANDO VALORES   \n");
        printf("[4] INVERTIR PILA               \n");
        printf("[5] FUNCION DE BUSQUEDA         \n");
        printf("[6] FUNCION DE ELIMINACION      \n");
        printf("[7] ELIMINAR MENOR              \n");
        printf("[8] PILA ORDENADA               \n");
        printf("[9] PROMEDIO PILA               \n");
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
                mostrar(&pilita);
            }break;

            case 2:
            {
                pasarValores(&pilita, &pila2);
                mostrar(&pilita);
                mostrar(&pila2);
            }break;

            case 3:
            {
                conservarOrden(&pilita, &pila2);
                mostrar(&pilita);
                mostrar(&pila2);
            }break;

            case 4:
            {
                invertirPila(&pilita);
                mostrar(&pilita);
            }break;

            case 5:
            {
                printf("Que elemento desea buscar?: \n");
                scanf("%i", &aux);
                aux2 = busqueda(pilita, aux);
                if(aux2==1)
                {
                    printf("Se encontro el valor %i\n", aux);
                    mostrar(&pilita);
                }else
                {
                    printf("No se encontro el valor %i\n", aux);
                    mostrar(&pilita);
                }
            }break;
            case 6:
            {
                printf("Ingrese el elemento que desea eliminar: \n");
                scanf("%i", &aux);
                mostrar(&pilita);
                eliminar(&pilita, aux);
                mostrar(&pilita);
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

void pasarValores(Pila *pilita, Pila *pila2)
{
    while(pilavacia(pilita)==0)
    {
        apilar(pila2, desapilar(pilita));
    }
}

void conservarOrden(Pila *pilita, Pila *pila2)
{
    Pila pilaux;
    inicpila(&pilaux);
    pasarValores(pilita, &pilaux);
    pasarValores(&pilaux, pilita);
}

void invertirPila(Pila *pilita)
{
    Pila pila2;
    inicpila(&pila2);
    conservarOrden(pilita, &pila2);
    pasarValores(&pila2, pilita);
}

int busqueda(Pila pilita, int aux)
{
    Pila pilaux;
    inicpila(&pilaux);
    int i=0;
    while(pilavacia(&pilita) == 0 && i==0)
    {
        if(tope(&pilita)==aux)
        {
            i=1;
        }
        apilar(&pilaux, desapilar(&pilita));
    }
    return i;
}

void eliminar(Pila *pilita, int aux)
{
    Pila pilaux;
    inicpila(&pilaux);
    while(pilavacia(pilita) == 0)
    {
        if(tope(pilita)==aux)
        {
            desapilar(pilita);
        }
        else
        {
         apilar(&pilaux, desapilar(pilita));
        }
    }
    while(pilavacia(&pilaux) == 0)
    {
        apilar(pilita, desapilar(&pilaux));
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void menu();
void pasarTopeABase(Pila *pilita);
void repartirAlternado(Pila mazo, Pila *jugador1, Pila *jugador2);

void eliminarElementos(Pila *pilita);
void eliminarTodos(Pila *modelo);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    Pila pilita;
    inicpila(&pilita);
    apilar(&pilita, 2);
    apilar(&pilita, 7);
    apilar(&pilita, 6);
    apilar(&pilita, 7);
    apilar(&pilita, 15);
    apilar(&pilita, 21);
    apilar(&pilita, 32);
    do
    {
        printf("__________________________________\n");
        printf("|[1] DE TOPE A BASE                 |\n");
        printf("|[2] REPARTIR MAZO                  |\n");
        printf("|[3] COMPRAR CANTIDAD DE ELEMENTOS  |\n");
        printf("|[4]                                |\n");
        printf("|[5] ELIMINAR ELEMENTO              |\n");
        printf("|[6] ELIMINAR TODOS LOS ELEMENTOS   |\n");
        printf("|[7]                                |\n");
        printf("|[8]                                |\n");
        printf("|[9]                                |\n");
        printf("----------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
        default:
            {
                printf("~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~\n");
            }break;
            case 0:
                {
                    printf("~ ~ ~ FINALIZANDO PROGRAMA ~ ~ ~\n");
                }break;
            case 1:
                {
                    mostrar(&pilita);
                    pasarTopeABase(&pilita);
                    mostrar(&pilita);
                    system("pause");
                    system("cls");
                }break;
            case 2:
                {
                    Pila pila1;
                    inicpila(&pila1);
                    Pila pila2;
                    inicpila(&pila2);
                    repartirAlternado(pilita, &pila1, &pila2);
                    printf("MAZO\n");
                    mostrar(&pilita);
                    printf("JUGADOR 1\n");
                    mostrar(&pila1);
                    printf("JUGADOR 2\n");
                    mostrar(&pila2);
                    system("pause");
                    system("cls");
                }break;
            case 3:
                {

                }break;
            case 4:
                {

                }break;
            case 5:
                {
                    mostrar(&pilita);
                    if(!pilavacia(&pilita))
                    {
                    eliminarElementos(&pilita);
                    mostrar(&pilita);
                    system("pause");
                    system("cls");
                    }else
                    {
                        printf("~ ~ ~ LA PILA ESTÁ VACIA ~ ~ ~");
                    }
                }break;
            case 6:
                {
                    mostrar(&pilita);
                    if(!pilavacia(&pilita))
                    {
                    eliminarTodos(&pilita);
                    mostrar(&pilita);
                    system("pause");
                    system("cls");
                    }else
                    {
                        printf("~ ~ ~ LA PILA ESTÁ VACIA ~ ~ ~");
                    }
                }break;
        }
    }while(op!=0);
}

/*
Hacer una función que pase el primer elemento (tope) de una pila a su última
posición (base), dejando los restantes elementos en el mismo orden. Retornar la
Pila o usar puntero para modificar la misma.
*/
void pasarTopeABase(Pila *pilita)
{
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilaux2;
    inicpila(&pilaux2);
    apilar(&pilaux, desapilar(pilita));
    while(!pilavacia(pilita))
    {
        apilar(&pilaux2, desapilar(pilita));
    }
    apilar(pilita, desapilar(&pilaux));
    while(!pilavacia(&pilaux2))
    {
        apilar(pilita, desapilar(&pilaux2));
    }
}

/*
Hacer una función que reparta los elementos de la pila MAZO en las pilas
JUGADOR1 y JUGADOR2 en forma alternada. Como el retorno de la función es
único, las Pilas correspondientes a los Jugadores deberán ser ingresadas como
parámetros por referencia, o una de las Pilas deberá ser retornada y la otra
modificada por medio de puntero.
*/
void repartirAlternado(Pila mazo, Pila *jugador1, Pila *jugador2)
{
    while(!pilavacia(&mazo))
    {
        apilar(jugador1, desapilar(&mazo));
        apilar(jugador2, desapilar(&mazo));
    }
}

/*
Hacer una función que compare la cantidad de elementos de dos pilas A y B. La
función deberá retornar -1 si la Pila A tiene más elementos, 0 si ambas pilas
tienen la misma cantidad de elementos o 1 si la Pila B tiene más elementos. En el
Main se evaluará este resultado para informar al usuario cuál Pila tiene más
elementos. El ejercicio debe resolverse SIN CONTAR los elementos de las
Pilas.
*/
void compararCantidad()
{

}

/*
Hacer una función que compare dos pilas A y B para ver si son completamente
iguales (en cantidad de elementos, valores que contienen y posición de los
mismos). La función deberá retornar 0 o 1, y en el Main se evaluará este
resultado para informar al usuario si las pilas son exáctamente iguales o no. El
ejercicio debe resolverse SIN CONTAR los elementos de las Pilas.
*/
void pilasIguales()
{

}

/*
Hacer una función que reciba una pila MODELO (vacía o no), y elimine de la pila
DADA todos los elementos que sean iguales al TOPE de la pila MODELO.
*/
void eliminarElementos(Pila *modelo)
{
    Pila dada;
    inicpila(&dada);
    Pila pilaux;
    inicpila(&pilaux);
    apilar(&dada, 5);
    apilar(&dada, 1);
    apilar(&dada, 12);
    apilar(&dada, 34);
    apilar(&dada, 2);
    apilar(&dada, 7);
    while(!pilavacia(modelo))
    {
        if(tope(modelo)==tope(&dada))
        {
            desapilar(modelo);
        }else
        {
            apilar(&pilaux, desapilar(modelo));
        }
    }
    while(!pilavacia(&pilaux))
    {
        apilar(modelo, desapilar(&pilaux));
    }
    printf("Elemento eliminado: %i\n", tope(&dada));
}

/*
Hacer una función que reciba una pila MODELO (vacía o no), y elimine de la pila
DADA todos los elementos que existan en la pila MODELO.
*/
void eliminarTodos(Pila *modelo)
{
    Pila dada;
    inicpila(&dada);
    apilar(&dada, 7);
    apilar(&dada, 32);
    apilar(&dada, 2);
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilaux2;
    inicpila(&pilaux2);
    while(!pilavacia(modelo))
    {
        int flag=0;

        while(!pilavacia(&dada))
        {
                if(tope(modelo)==tope(&dada))
                {
                    desapilar(modelo);
                    flag=1;
                }
                    apilar(&pilaux2, desapilar(&dada));
        }

        while(!pilavacia(&pilaux2))
        {
        apilar(&dada, desapilar(&pilaux2));
        }

        if(flag==0)
        {
        apilar(&pilaux, desapilar(modelo));
        }
    }

    while(!pilavacia(&pilaux))
    {
        apilar(modelo, desapilar(&pilaux));
    }
}

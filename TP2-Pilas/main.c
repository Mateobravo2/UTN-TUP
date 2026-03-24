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
int eliminarMenor(Pila *pilita);
void agregarElemento(int aux);
float calcularPromedioPila(Pila pilita);
int sumaPila(Pila pilita);
int cantidadValores(Pila pilita);
float division(int suma, int i);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int aux=0, aux2=0, op=0;
    Pila pilita;
    inicpila(&pilita);
    Pila pila2;
    inicpila(&pila2);
    do
    {
        printf("__________________________________\n");
        printf("|[1] FUNCION DE CARGA            |\n");
        printf("|[2] PASAR DE UNA PILA A OTRA    |\n");
        printf("|[3] PASAR CONSERVANDO VALORES   |\n");
        printf("|[4] INVERTIR PILA               |\n");
        printf("|[5] FUNCION DE BUSQUEDA         |\n");
        printf("|[6] FUNCION DE ELIMINACION      |\n");
        printf("|[7] ELIMINAR MENOR              |\n");
        printf("|[8] PILA ORDENADA               |\n");
        printf("|[9] PROMEDIO PILA               |\n");
        printf("----------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
        default:
            {

            }break;
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
                mostrar(&pilita);
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
            case 7:
            {
                mostrar(&pilita);
                aux=eliminarMenor(&pilita);
                if(aux==-1)
                {
                    printf("~ ~ ~ LA PILA ESTA VACIA ~ ~ ~");
                }else
                {
                    printf("Se elimino %i", aux);
                    mostrar(&pilita);
                }
            }break;
            case 8:
                {
                    printf("Coloque el numero que desea agregar a la pila: \n");
                    scanf("%i", &aux);
                    agregarElemento(aux);
                }break;
            case 9:
                {
                    printf("El promedio de la pila es de: %.2f\n", calcularPromedioPila(pilita));
                }break;
        }
    }while(op!=0);
}

/*
Hacer una función que permita al usuario del sistema ingresar a una pila todos
los datos que desee (a esto lo llamamos “FUNCION DE CARGA”).
*/
void cargarValores(int aux, Pila* pilita)
{
    while(aux>0)
    {
        leer(pilita);
        aux--;
    }
}

/*
Hacer una función que pase todos los elementos de una pila a otra.
*/
void pasarValores(Pila *pilita, Pila *pila2)
{
    while(pilavacia(pilita)==0)
    {
        apilar(pila2, desapilar(pilita));
    }
}

/*
Hacer una función que pase todos los elementos de una pila a otra, pero
conservando el orden.
*/
void conservarOrden(Pila *pilita, Pila *pila2)
{
    Pila pilaux;
    inicpila(&pilaux);
    pasarValores(pilita, &pilaux);
    pasarValores(&pilaux, pilita);
}

/*
Hacer una función que invierta una pila (que contenga los elementos cargados
originalmente en ella, pero en orden inverso).
*/
void invertirPila(Pila *pilita)
{
    Pila pila2;
    inicpila(&pila2);
    conservarOrden(pilita, &pila2);
    pasarValores(&pila2, pilita);
}

/*
Hacer una función que determine si un elemento buscado está o no dentro
de una pila. Al encontrarlo, finalizar la búsqueda. (a esto lo llamamos
“FUNCION DE BUSQUEDA”)
*/
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

/*
Hacer una función que elimine de una pila TODOS los elementos que
coincidan con un valor ingresado por parámetro a la función. Al eliminarlo/s,
el resto de los elementos de la pila deben quedar en el mismo orden. (a esto
lo llamamos “FUNCION DE ELIMINACION”).
*/
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

/*
Hacer una función que encuentre el menor elemento de una pila y lo retorne.
La misma debe eliminar ese dato de la pila.
*/

int eliminarMenor(Pila *pilita)
{
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilamenor;
    inicpila(&pilamenor);
    if(!pilavacia(pilita))
    {
        apilar(&pilamenor, desapilar(pilita));
    }else
    {
        apilar(&pilamenor, -1);
    }
        while(!pilavacia(pilita))
        {
            if(tope(pilita)<tope(&pilamenor))
            {
                apilar(&pilaux, desapilar(&pilamenor));
                apilar(&pilamenor, desapilar(pilita));
            }
            else
            {
                apilar(&pilaux, desapilar(pilita));
            }
        }
        while(!pilavacia(&pilaux))
        {
            apilar(pilita, desapilar(&pilaux));
        }
    return tope(&pilamenor);
}

/*
Hacer una función que inserte en una pila ordenada un nuevo elemento,
conservando el orden de ésta
*/
void agregarElemento(int aux)
{
    int flag=0;
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilaOrdenada;
    inicpila(&pilaOrdenada);
    apilar(&pilaOrdenada, 1);
    apilar(&pilaOrdenada, 5);
    apilar(&pilaOrdenada, 10);
    apilar(&pilaOrdenada, 15);
    apilar(&pilaOrdenada, 20);
    mostrar(&pilaOrdenada);
    while(flag==0 && !pilavacia(&pilaOrdenada))
    {
        if(tope(&pilaOrdenada) <= aux)
        {
            flag=1;
            apilar(&pilaux, aux);
        }else{
                apilar(&pilaux, desapilar(&pilaOrdenada));
        }
    }
    if(pilavacia(&pilaOrdenada))
    {
        apilar(&pilaux, aux);
    }
    while(!pilavacia(&pilaux))
    {
        apilar(&pilaOrdenada, desapilar(&pilaux));
    }
    mostrar(&pilaOrdenada);
}

/*
Hacer una función que calcule el promedio de los elementos de una pila, para
ello hacer también una función que calcule la suma, otra para la cuenta y otra
que divida. En total son cuatro funciones, y la función que calcula el promedio
invoca a las otras 3.
*/
float calcularPromedioPila(Pila pilita)
{
    int suma=0, i=0;
    suma=sumaPila(pilita);
    i=cantidadValores(pilita);
    return division(suma, i);
}

int sumaPila(Pila pilita)
{
    Pila pilaux;
    inicpila(&pilaux);
    int suma=0;
    while(!pilavacia(&pilita))
    {
        apilar(&pilaux, desapilar(&pilita));
        suma = suma + tope(&pilaux);
    }
    return suma;
}

int cantidadValores(Pila pilita)
{
    Pila pilaux;
    inicpila(&pilaux);
    int i=0;
    while(!pilavacia(&pilita))
    {
        apilar(&pilaux, desapilar(&pilita));
        i++;
    }
    return i;
}

float division(int suma, int i)
{
    return suma/i;
}

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <math.h>

void menu();
void cargarValores(Pila* pilita);
//PUNTO 1
void pasarTopeABase(Pila *pilita);
//PUNTO 2
void repartirAlternado(Pila mazo, Pila *jugador1, Pila *jugador2);
//PUNTO 3

//PUNTO 4

//PUNTO 5
void eliminarElementos(Pila *pilita);
//PUNTO 6
void eliminarTodos(Pila *modelo);
//PUNTO 7
Pila mayoresMenores(Pila original, Pila *mayores, int val);
//PUNTO 8

//PUNTO 9
int transformarADecimal(Pila soloDigito);
//PUNTO 10
int sumaTopeYAnterior(Pila pilita);
//PUNTO 11
int capicua(Pila dada);
//punto 12
Pila operacionUnion(Pila pilitaa, Pila pilitab);
int elementoRepetido(int num, Pila pila2);
void verificarElementoRepetido(int val, Pila *pilaux, Pila *pilitac, Pila *pilita);
//PUNTO 13
Pila juntarOrdenadas(Pila pilaa, Pila pilab);
void agregarElemento(int aux, Pila *pilaOrdenada);
//PUNTO 14


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
        printf("_____________________________________\n");
        printf("|[1] DE TOPE A BASE                 |\n");
        printf("|[2] REPARTIR MAZO                  |\n");
        printf("|[3]                                |\n");
        printf("|[4]                                |\n");
        printf("|[5] ELIMINAR ELEMENTO              |\n");
        printf("|[6] ELIMINAR TODOS LOS ELEMENTOS   |\n");
        printf("|[7] SEPARAR MAYORES Y MENORES      |\n");
        printf("|[8]                                |\n");
        printf("|[9] SOLO DIGITO A DECIMAL          |\n");
        printf("|[10] SUMA TOPE Y ANTERIOR          |\n");
        printf("|[11] CAPICUA                       |\n");
        printf("|[12] CONJUNTOS                     |\n");
        printf("|[13]                               |\n");
        printf("|[14]                               |\n");
        printf("|[15]                               |\n");
        printf("-------------------------------------\n");
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
            case 7:
                {
                    int val;
                    Pila mayores;
                    inicpila(&mayores);
                    Pila menores;
                    inicpila(&menores);
                    printf("Que valor desea elegir como divisor?\n");
                    scanf("%i", &val);
                    menores=mayoresMenores(pilita, &mayores, val);
                    printf("\nPila original: ");
                    mostrar(&pilita);
                    printf("Pila MAYORES: ");
                    mostrar(&mayores);
                    printf("Pila MENORES: ");
                    mostrar(&menores);
                    system("pause");
                    system("cls");
                }break;
            case 8:
                {

                }break;
            case 9:
                {
                    int sum=0;
                    Pila soloDigito;
                    inicpila(&soloDigito);
                    cargarValores(&soloDigito);
                    sum=transformarADecimal(soloDigito);
                    printf("Pila original: \n");
                    mostrar(&soloDigito);
                    printf("\nPasado a decimal: \n%i\n", sum);
                    system("pause");
                    system("cls");
                }break;
            case 10:
                {
                    int suma=0;
                    Pila pilon;
                    inicpila(&pilon);
                    cargarValores(&pilon);
                    suma=sumaTopeYAnterior(pilon);
                    system("cls");
                    printf("PILA ORIGINAL: \n");
                    mostrar(&pilon);
                    printf("\nLa suma del tope y el anterior es: %i\n", suma);
                    system("pause");
                    system("cls");
                }break;
            case 11:
                {
                    int aux;
                    Pila dada;
                    inicpila(&dada);
                    apilar(&dada, 1);
                    apilar(&dada, 4);
                    apilar(&dada, 2);
                    apilar(&dada, 6);
                    apilar(&dada, 2);
                    apilar(&dada, 4);
                    apilar(&dada, 1);
                    aux=capicua(dada);
                    printf("--PILA ORIGINAL--\n");
                    mostrar(&dada);
                        if(aux==1)
                        {
                            printf("La pila es capicua!!!\n");
                        }else
                        {
                            printf("La pila NO es capicua :( \n");
                        }
                    system("pause");
                    system("cls");
                }break;
            case 12:
                {
                    Pila pilitaa;
                    inicpila(&pilitaa);
                    apilar(&pilitaa, 1);
                    apilar(&pilitaa, 2);
                    apilar(&pilitaa, 6);
                    apilar(&pilitaa, 9);
                    apilar(&pilitaa, 14);
                    Pila pilitab;
                    inicpila(&pilitab);
                    apilar(&pilitab, 8);
                    apilar(&pilitab, 22);
                    apilar(&pilitab, 6);
                    apilar(&pilitab, 7);
                    apilar(&pilitab, 1);
                    apilar(&pilitab, 12);
                    Pila pilitac;
                    inicpila(&pilitac);
                    pilitac=operacionUnion(pilitaa, pilitab);
                    printf("PILA A:");
                    mostrar(&pilitaa);
                    printf("\nPILA B:");
                    mostrar(&pilitab);
                    printf("\nPILAS UNIDAS:");
                    mostrar(&pilitac);
                    system("pause");
                    system("cls");
                }break;
            case 13:
                {
                    Pila pilaOrd1;
                    inicpila(&pilaOrd1);
                    apilar(&pilaOrd1, 0);
                    apilar(&pilaOrd1, 1);
                    apilar(&pilaOrd1, 8);
                    apilar(&pilaOrd1, 15);
                    apilar(&pilaOrd1, 26);
                    apilar(&pilaOrd1, 35);
                    Pila pilaOrd2;
                    inicpila(&pilaOrd2);
                    apilar(&pilaOrd2, 1);
                    apilar(&pilaOrd2, 7);
                    apilar(&pilaOrd2, 9);
                    apilar(&pilaOrd2, 16);
                    apilar(&pilaOrd2, 25);
                    apilar(&pilaOrd2, 35);
                    apilar(&pilaOrd1, 94);
                    Pila ordenadaFinal;
                    inicpila(&ordenadaFinal);
                    mostrar(&pilaOrd1);
                    mostrar(&pilaOrd2);
                    ordenadaFinal= juntarOrdenadas(pilaOrd1, pilaOrd2);
                    mostrar(&ordenadaFinal);
                    system("pause");
                    system("cls");
                }break;
            case 14:
                {

                }break;
            case 15:
                {

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

/*
Hacer una función que reciba por parámetro una Pila y un valor elegido por el
usuario del sistema. La función debe pasar a la pila MAYORES los elementos de
la pila que sean mayores o iguales a dicho valor elegido, y a la pila MENORES
los elementos que sean menores. Como el retorno de la función es único, las
pilas MAYORES Y MENORES deberán ser ingresadas como parámetros por
referencia, o una de las Pilas deberá ser retornada y la otra modificada por medio
de puntero. La Pila original debe quedar con todos sus elementos.
*/

Pila mayoresMenores(Pila original, Pila *mayores, int val)
{
    Pila menores;
    inicpila(&menores);
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilaux2;
    inicpila(&pilaux2);

    while(!pilavacia(&original))
    {
        if(tope(&original) >= val)
        {
           apilar(mayores, desapilar(&original));
        }else
        {
            apilar(&menores, desapilar(&original));
        }
    }
    return menores;
}



/*
Hacer una función que reciba una pila con números de un solo dígito (ello es
responsabilidad de quien usa el programa) y que transforme esos dígitos en un
número decimal.
*/

void cargarValores(Pila* pilita)
{
    int aux=1;
    printf("(Ingrese -1 para finalizar)\n\n");
    while(aux>=0)
    {
        leer(pilita);
        aux=tope(pilita);
        if(tope(pilita)<0)
        {
            desapilar(pilita);
        }
    }
}

int transformarADecimal(Pila soloDigito)
{
    int suma=0, x=0;
    int i=-1;
    Pila pilaux;
    inicpila(&pilaux);

    while(!pilavacia(&soloDigito))
    {
        i++;
        apilar(&pilaux, desapilar(&soloDigito));
    }

    while(!pilavacia(&pilaux))
    {
        apilar(&soloDigito, desapilar(&pilaux));
    }

    while(!pilavacia(&soloDigito))
    {
        x=pow(10, i);
        suma=suma+(tope(&soloDigito)*x);
        i--;
        apilar(&pilaux, desapilar(&soloDigito));
    }
    return suma;
}

/*
Hacer una función que sume los dos primeros elementos de una pila (tope y
anterior), y retorne la suma, sin alterar el contenido de la pila.
*/

int sumaTopeYAnterior(Pila pilita)
{
    int aux=0, suma=0, aux2=0;
    Pila pilaux;
    inicpila(&pilaux);
        apilar(&pilaux, desapilar(&pilita));
        aux=tope(&pilaux);
        aux2=tope(&pilita);
        suma=aux+aux2;
    return suma;
}

/*
Hacer una función que verifique si una pila DADA es capicúa. La función deberá
retornar 0 o 1, y en el Main se evaluará este resultado para informar al usuario si es
o no capicúa.
*/

int capicua(Pila dada)
{
    int i=6, v=0;
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilaux2;
    inicpila(&pilaux2);
    while(!pilavacia(&dada))
    {
        v=tope(&dada);
        apilar(&pilaux2, v);
        apilar(&pilaux, desapilar(&dada));
    }
    while(!pilavacia(&pilaux))
    {
        apilar(&dada, desapilar(&pilaux));
    }
        while(i!=0 && !pilavacia(&dada))
        {
            if(tope(&pilaux2) == tope(&dada))
            {
                i=1;
            }else
            {
                i=0;
            }
                apilar(&pilaux, desapilar(&pilaux2));
                apilar(&pilaux, desapilar(&dada));
        }
    return i;
}

/*
Hacer una función que reciba por parámetro dos pilas A y B que simulan conjuntos
(cada conjunto no tiene elementos repetidos sobre sí mismo). La función debe
calcular en la pila C la operación de unión (es decir: la Pila C debe contener todos
los elementos que estén en la Pila A o en la Pila B, pero los que se encuentren en
ambas deben apilarse solo una vez). Deberá retornarse la Pila C o usar puntero
para modificar la misma.
*/

Pila operacionUnion(Pila pilitaa, Pila pilitab)
{
    Pila pilaux;
    inicpila(&pilaux);
    Pila pilitac;
    inicpila(&pilitac);
    int val=0, flag=0;
    while(flag==0)
    {
        if(!pilavacia(&pilitaa) && !pilavacia(&pilitab))
        {
            if(!pilavacia(&pilitac))
            {
                val = elementoRepetido(tope(&pilitaa), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitaa);
                val = elementoRepetido(tope(&pilitab), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitab);
            }
            else
            {
                apilar(&pilitac, desapilar(&pilitaa));
                val = elementoRepetido(tope(&pilitab), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitab);
            }
        }
        else if(pilavacia(&pilitaa) && !pilavacia(&pilitab))
        {
            if(!pilavacia(&pilitac))
            {
                val = elementoRepetido(tope(&pilitab), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitab);
            }
            else
            {
                apilar(&pilitac, desapilar(&pilitab));
                val = elementoRepetido(tope(&pilitab), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitab);
            }
        }
        else if(!pilavacia(&pilitaa) && pilavacia(&pilitab))
        {
            if(!pilavacia(&pilitac))
            {
                val = elementoRepetido(tope(&pilitaa), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitaa);
            }
            else
            {
                apilar(&pilitac, desapilar(&pilitaa));
                val = elementoRepetido(tope(&pilitaa), pilitac);
                verificarElementoRepetido(val, &pilaux, &pilitac, &pilitaa);
            }
        }
        else
        {
            flag=1;
        }
    }
    return pilitac;
}

void verificarElementoRepetido(int val, Pila *pilaux, Pila *pilitac, Pila *pilita)
{
    if(val == 1)
    {
        apilar(pilaux, desapilar(pilita));
    }else
    {
        apilar(pilitac, desapilar(pilita));
    }
}

int elementoRepetido(int num, Pila pila2)
{
    Pila pilaux;
    inicpila(&pilaux);
    int aux=0, aux2=0;
    while(!pilavacia(&pila2) && aux2 != 1)
    {
        aux=tope(&pila2);
        if(num == aux)
        {
            aux2=1;
        }
        apilar(&pilaux, desapilar(&pila2));
    }
    return aux2;
}

/*
Hacer una función que reciba dos pilas ordenadas en forma creciente y pase los
elementos de las mismas a otra pila también ordenada en forma creciente
(ORDENADAFINAL). Deberá retornarse la Pila ORDENADAFINAL o usar puntero
para modificar la misma.
*/
Pila juntarOrdenadas(Pila pilaa, Pila pilab)
{
    int aux=0, aux2=0, flag=0;
    Pila pilaux;
    inicpila(&pilaux);
    Pila ordenadaFinal;
    inicpila(&ordenadaFinal);
    while(flag!=1)
    {
        if(!pilavacia(&pilaa) && !pilavacia(&pilab))
        {
            aux=tope(&pilaa);
            agregarElemento(aux, &ordenadaFinal);
            aux2=tope(&pilab);
            agregarElemento(aux2, &ordenadaFinal);
            apilar(&pilaux, desapilar(&pilaa));
            apilar(&pilaux, desapilar(&pilab));
        }
        else if(pilavacia(&pilaa) && !pilavacia(&pilab))
        {
            aux2=tope(&pilab);
            agregarElemento(aux2, &ordenadaFinal);
            apilar(&pilaux, desapilar(&pilab));
        }
        else if(!pilavacia(&pilaa) && pilavacia(&pilab))
        {
            aux=tope(&pilaa);
            agregarElemento(aux, &ordenadaFinal);
            apilar(&pilaux, desapilar(&pilaa));
        }
        else
        {
            flag=1;
        }
    }
    return ordenadaFinal;
}

void agregarElemento(int aux, Pila *pilaOrdenada)
{
    int flag=0;
    Pila pilaux;
    inicpila(&pilaux);
    while(flag!=1 && !pilavacia(pilaOrdenada))
    {
        if(tope(pilaOrdenada) <= aux)
        {
            flag=1;
            apilar(&pilaux, aux);
        }else{
                apilar(&pilaux, desapilar(pilaOrdenada));
        }
    }
    if(pilavacia(pilaOrdenada))
    {
        apilar(&pilaux, aux);
    }
    while(!pilavacia(&pilaux))
    {
        apilar(pilaOrdenada, desapilar(&pilaux));
    }
}


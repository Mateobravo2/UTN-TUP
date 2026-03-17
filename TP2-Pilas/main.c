#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void menu();




int main()
{
    menu();
    return 0;
}


void menu()
{
    int op=0;
    Pila pilita;
    inicpila(&pilita);

    do
    {
        printf("Ingrese la operacion que desea realizar [1-6] \n");
        printf("            _________________________________________\n");
        printf("            | [1] Cargar valores en pila        |\n");
        printf("            | [2] Pasar pila                    |\n");
        printf("            | [3] Pasar pila|\n");
        printf("            | [4] |\n");
        printf("            | [5] |\n");
        printf("            | [6] |\n");
        printf("            -----------------------------------------\n");
        scanf("%i", &op);
        switch(op)
        {
            case 0
            {
                printf("~~~ FINALIZANDO EL PROGRAMA ~~~");
            }break;
            case 1
            {

            }break;
            case 2
            {

            }break;
            case 3
        }
    }while(op!=0)
}


void cargarValores()
{


}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
//PUNTO 1
void cargarStrings(char string1[]);
//PUNTO 5
int contarVocales(char string1[]);
//PUNTO 6
void seleccion(char string1[], int validos);
int buscarMenor(char string1[], int inic, int validos);
//PUNTO 7
void insercionSort(char string1[], int validos);
void insertar(char string1[], int posInic, char dato);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op = 0, rta = 0;
    char string1[100], string2[100], stringaux[100];
    do
    {
        printf("                                    ___________________________________\n");
        printf("                                    |[1]  COMPARAR STRINGS            |\n");
        printf("                                    |[2]  LONGITUD DE STRING          |\n");
        printf("                                    |[3]  COPIAR STRING               |\n");
        printf("                                    |[4]  COPIAR Y CONCATENAR STRINGS |\n");
        printf("                                    |[5]  CONTAR VOCALES              |\n");
        printf("                                    |[6]  ORDENAR POR SELECCION       |\n");
        printf("                                    |[7]  ORDENAR POR INSERCION       |\n");
        printf("                                    |[0]           SALIR              |\n");
        printf("                                    -----------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
            default:
                {
                    printf("\n~ ~ ~ INGRESE UN VALOR VALIDO ~ ~ ~\n");
                    system("pause");
                    system("cls");
                }break;
            case 0:
                {
                    printf("~ ~ ~ FINALIZANDO EL PROGRAMA ~ ~ ~\n");
                }break;
            case 1:
                {
                    cargarStrings(string1);
                    cargarStrings(string2);
                    rta = strcmp(string1, string2);
                    if(rta == 0)
                    {
                        printf("\n- - LAS CADENAS SON IGUALES - -\n");
                    }else
                    {
                        printf("\n- - LAS CADENAS SON DISTINTAS - -\n");
                    }
                    system("pause");
                    system("cls");
                }break;
            case 2:
                {
                    cargarStrings(string1);
                    rta = strlen(string1);
                    printf("\nLa longitud de la cadena es de - %i - caracteres\n", rta);
                    system("pause");
                    system("cls");
                }break;
            case 3:
                {
                    cargarStrings(string1);
                    strcpy(string2, string1);
                    printf("\nPRIMER STRING: %s \n", string1);
                    printf("\nSEGUNDO STRING: %s \n", string2);
                    system("pause");
                    system("cls");
                }break;
            case 4:
                {
                    cargarStrings(string1);
                    strcpy(string2, string1);
                    printf("\nPRIMER STRING: %s \n", string1);
                    printf("\nSEGUNDO STRING: %s \n", string2);
                    cargarStrings(stringaux);
                    strcat(stringaux, string2);
                    printf("STRINGS CONCATENADOS: %s\n", stringaux);
                    system("pause");
                    system("cls");
                }break;
            case 5:
                {
                    cargarStrings(string1);
                    rta = contarVocales(string1);
                    printf("\nLa cadena de caracteres contiene %i vocales\n", rta);
                    system("pause");
                    system("cls");
                }break;
            case 6:
                {
                    cargarStrings(string1);
                    printf("\nABECEDARIO DESORDENADO: %s\n", string1);
                    seleccion(string1, strlen(string1));
                    printf("\nABECEDARIO ORDENADO: %s\n\n", string1);
                    system("pause");
                    system("cls");
                }break;
            case 7:
                {
                    cargarStrings(string1);
                    printf("\nABECEDARIO DESORDENADO: %s\n", string1);
                    seleccion(string1, strlen(string1));
                    insercionSort(string1, strlen(string1));
                    printf("\nABECEDARIO ORDENADO: %s\n", string1);
                    system("pause");
                    system("cls");
                }break;
        }
    }while(op!=0);
}

//PUNTO 1
void cargarStrings(char string1[])
{
    printf("Ingrese la cadena de caracteres: ");
    fflush(stdin);
    gets(string1);
}

//PUNTO 5
int contarVocales(char string1[])
{
    int i = 0, cont = 0;
    char vocales[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    do
    {
        for(int i2 = 0; i2 < strlen(vocales); i2++)
        {
            if(vocales[i2] == string1[i])
            {
                cont++;
            }
        }
        i++;
    }while(i < strlen(string1));
    return cont;
}

//PUNTO 6
void seleccion(char string1[], int validos)
{
    int men=0, aux=0, i=0;
    while(i < validos)
    {
        men = buscarMenor(string1, i, validos);
        aux = string1[men];
        string1[men] = string1[i];
        string1[i] = aux;
        i++;
    }
}

int buscarMenor(char string1[], int inic, int validos)
{
    int men = string1[inic];
    int posMenor = inic;
    int i = inic+1;
    while(i < validos)
    {
        if(men > string1[i])
        {
            men = string1[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

//PUNTO 7
void insercionSort(char string1[], int validos)
{
    int i=0;
    while(i < validos-1)
    {
        insertar(string1, i, string1[i+1]);
        i++;
    }
}

void insertar(char string1[], int posInic, char dato)
{
    int i=posInic;
    while(i>=0 && dato < string1[i])
    {
        string1[i+1] = string1[i];
        i--;
    }
    string1[i+1] = dato;
}

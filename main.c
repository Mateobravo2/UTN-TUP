#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
//PUNTO 1
void cargarStrings(char string1[]);
//PUNTO 5
int contarVocales(char string1[]);

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
        printf("                                      ___________________________________\n");
        printf("                                      |[1]  COMPARAR STRINGS            |\n");
        printf("                                      |[2]  LONGITUD DE STRING          |\n");
        printf("                                      |[3]  COPIAR STRING               |\n");
        printf("                                      |[4]  COPIAR Y CONCATENAR STRINGS |\n");
        printf("                                      |[5]  CONTAR VOCALES              |\n");
        printf("                                      |[6]  |\n");
        printf("                                      |[7]  |\n");
        printf("                                      |[0]           SALIR                |\n");
        printf("                                      -------------------------------------\n");
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


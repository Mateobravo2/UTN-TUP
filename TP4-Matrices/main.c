#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define R 3
#define CLM 3

void menu();
//PUNTO 1
void cargarMatriz(int r, int clm, int matriz1[][clm]);
//PUNTO 2
void mostrarMatriz(int r, int clm, int matriz1[][clm]);
//PUNTO 3
void cargarMatrizRandom(int r, int clm, int matriz1[][clm]);
//PUNTO 4
int sumarContenido(int r, int clm, int matriz1[][clm]);
//PUNTO 5
float calcularPromedioMatriz(int r, int clm, int matriz1[][clm]);
//PUNTO 6
int encontrarNumero(int r, int clm, int matriz1[][clm], int num);
//PUNTO 7
int cargarArregloString(int r, int clm, char matriz2[][clm]);
//PUNTO 8
void mostrarMatrizStrings(int r, int clm, char matriz2[][clm]);
//PUNTO 9
int buscarString(char matriz2[][5], int r, char pal[]);
//PUNTO 10
int buscarStringOrdenada(char matriz3[][7], int val, char pal[]);
//PUNTO 11
void intercambioPalabras(int clm, char matriz2[][clm], int posmenor, int r);
int buscarPosMenor(int r, int clm, char matriz2[][clm], int pos);
void ordenPorSeleccionMatriz(int r, int clm, char matriz2[][clm]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op=0,existe=0, aux;
    int matriz1[R][CLM];
    char matriz2[4][5];
    do
    {
        printf("                                    _____________________________________________\n");
        printf("                                    |[1]  CARGAR MATRIZ                         |\n");
        printf("                                    |[2]  MOSTRAR MATRIZ CARGADA                |\n");
        printf("                                    |[3]  CARGAR MATRIZ RANDOM                  |\n");
        printf("                                    |[4]  SUMAR CONTENIDO DE UNA MATRIZ         |\n");
        printf("                                    |[5]  PROMEDIO DE UNA MATRIZ                |\n");
        printf("                                    |[6]  ENCONTRAR ELEMENTO EN UNA MATRIZ      |\n");
        printf("                                    |[7]  CARGAR ARREGLO DE PALABRAS            |\n");
        printf("                                    |[8]  MOSTRAR ARREGLO DE PALABRAS           |\n");
        printf("                                    |[9]  BUSCAR STRING EN ARREGLO              |\n");
        printf("                                    |[10] BUSCAR STRING EN ARREGLO OREDENADO    |\n");
        printf("                                    |[11] ORDENAR ARREGLO STRINGS               |\n");
        printf("                                    |[0]                SALIR                   |\n");
        printf("                                    ---------------------------------------------\n");
        scanf("%i", &op);;
        system("cls");
        switch(op)
        {
            case 0:
                {
                    printf("- - - FINALIZANDO EL PROGRAMA - - -\n");
                }
                break;
            case 1:
                {
                    int matriz1[R][CLM];
                    cargarMatriz(R, CLM, matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                {
                    int matriz1[R][CLM];
                    mostrarMatriz(R, CLM, matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                {
                    cargarMatrizRandom(R, CLM, matriz1);
                    mostrarMatriz(R, CLM, matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                {
                    int res = 0;
                    cargarMatriz(R, CLM, matriz1);
                    res = sumarContenido(R, CLM, matriz1);
                    mostrarMatriz(R, CLM, matriz1);
                    printf("\nLa suma del contenido de la matriz es: %i\n", res);
                    system("pause");
                    system("cls");
                }
                break;
            case 5:
                {
                    cargarMatriz(R, CLM, matriz1);
                    float res = calcularPromedioMatriz(R, CLM, matriz1);
                    mostrarMatriz(R, CLM, matriz1);
                    printf("\nPromedio de la matriz: %.2f\n", res);
                    system("pause");
                    system("cls");
                }
                break;
            case 6:
                {
                    int num, aux;
                    printf("Que elemento desea buscar?: ");
                    scanf("%i", &num);
                    aux = encontrarNumero(R, CLM, matriz1, num);
                    mostrarMatriz(R, CLM, matriz1);
                    if(aux == 1)
                    {
                        printf("\nEl numero |%i| se encuentra en la matriz\n", num);
                    }
                    else
                    {
                        printf("\nEl numero |%i| NO se encuentra en la matriz\n", num);
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case 7:
                {
                    aux = cargarArregloString(4, 5, matriz2);
                    printf("\nSe ingresaron |%i| palabras\n", aux);
                    system("pause");
                    system("cls");
                }
                break;
            case 8:
                {
                    mostrarMatrizStrings(4, 5, matriz2);
                }
                break;
            case 9:
                {
                    char pal[5];
                    printf("Que palabra de 4 letras quiere buscar: ");
                    scanf(" %s", pal);
                    aux = buscarString(matriz2, 4, pal);
                    if(aux == -1)
                    {
                        printf("\nLa palabra NO se encuentra en la matriz. \n");
                    }
                    else
                    {
                        printf("\nLa palabra se encuentra en la matriz. \n");
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case 10:
                {
                    char matriz3[5][7] = {"Animal", "monos", "patos", "radio", "trompo"};
                    char pal[5];
                    printf("Que palabra de 4 letras quiere buscar: ");
                    scanf(" %s", pal);
                    aux = buscarStringOrdenada(matriz3, 5, pal);
                    if(aux == -1)
                    {
                        printf("\nLa palabra NO se encuentra en la matriz. \n");
                    }
                    else
                    {
                        printf("\nLa palabra se encuentra en la matriz. \n");
                    }
                    system("pause");
                    system("cls");
                }
                break;
            case 11:
                {
                    printf("\Matriz sin ordenar: \n");
                    mostrarMatrizStrings(4, 5, matriz2);
                    ordenPorSeleccionMatriz(4, 5, matriz2);
                    printf("\nMatriz ordenada: \n");
                    mostrarMatrizStrings(4, 5, matriz2);
                }
                break;
            default:
                {
                    printf("~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~\n");
                    system("pause");
                    system("cls");
                }
                break;
        }
    }while(op!=0);
}

//PUNTO 1
void cargarMatriz(int r, int clm, int matriz1[][clm])
{
    int i, j;
    for(i = 0; i < r; i++)
    {
        printf("\nCarga de datos en fila n%i: ", i);
        for(j = 0; j < clm; j++)
        {
            printf("\nCarga de datos en columna n%i: ", j);
            scanf("%i", &matriz1[i][j]);
        }
    }
}

//PUNTO 2
void mostrarMatriz(int r, int clm, int matriz1[][clm])
{
    int i, j;
    printf("\nMATRIZ:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < clm; j++)
        {
            printf(" |%i| ", matriz1[i][j]);
        }
        printf("\n");
    }
}

//PUNTO 3
void cargarMatrizRandom(int r, int clm, int matriz1[][clm])
{
    int i, j;
    srand(time(NULL));
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < clm; j++)
        {
            matriz1[i][j] = rand()%100;
        }
    }
}

//PUNTO 4
int sumarContenido(int r, int clm, int matriz1[][clm])
{
    int i, j, sum = 0;
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < clm; j++)
        {
            sum = sum + matriz1[i][j];
        }
    }
    return sum;
}

//PUNTO 5
float calcularPromedioMatriz(int r, int clm, int matriz1[][clm])
{
    int i, j, k = 0;
    int aux = sumarContenido(r, clm, matriz1);
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < clm; j++)
        {
            k++;
        }
    }
    return aux / k;
}

//PUNTO 6
int encontrarNumero(int r, int clm, int matriz1[][clm], int num)
{
    int i, j, flag = 0;
    for(i = 0; i < r && flag == 0; i++)
    {
        for(j = 0; j < clm && flag == 0; j++)
        {
            if(num == matriz1[i][j])
            {
                flag = 1;
            }
        }
    }
    return flag;
}

//PUNTO 7
int cargarArregloString(int r, int clm, char matriz2[][clm])
{
    int i, cont=0;
    char x = 's';
    while(cont < r-1)
    {
        for(i = 0; i < r && x == 's' ; i++)
        {
            printf("Ingrese una cadena de |%i| caracteres: ", clm-1);
            scanf(" %s", matriz2[i]);
            if(i < r-1)
            {
                printf("Quiere seguir cargando palabras?: ");
                scanf(" %c", &x);
            }
            cont++;
        }
    }
    return cont;
}

//PUNTO 8
void mostrarMatrizStrings(int r, int clm, char matriz2[][clm])
{
    int i;
        for(i = 0; i < r; i++)
        {
            printf(" |%s| \n", matriz2[i]);
        }
}

//PUNTO 9
int buscarString(char matriz2[][5], int r, char pal[])
{
    int i, pos = -1;
    for(i = 0; i < r && pos == -1; i++)
    {
         if(strcmpi(pal, matriz2[i]) == 0)
         {
             pos = i;
         }
    }
    return pos;
}

//PUNTO 10
int buscarStringOrdenada(char matriz3[][7], int val, char pal[])
{
    int i = 0, pos = -1, x;
    while(i < val && pos == -1 && strcmpi(pal, matriz3[i]) >= 0)
    {
        if(strcmpi(pal, matriz3[i]) == 0)
        {
            pos = i;
        }
        printf("%i", i);
        i++;
    }
    return pos;
}

//PUNTO 11
void ordenPorSeleccionMatriz(int r, int clm, char matriz2[][clm])
{
    int i;
    int posmen = 0;
    for(i = 0; i < r; i++)
    {
        posmen = buscarPosMenor(r, clm, matriz2, i);
        intercambioPalabras(clm, matriz2, posmen, r);
    }
}

int buscarPosMenor(int r, int clm, char matriz2[][clm], int pos)
{
    int posmenor = pos;
    char palabraMenor[clm];
    strcpy(palabraMenor, matriz2[pos]);
    int i;
    for(i = pos+1; i < r; i++)
    {
        if(strcmpi(palabraMenor, matriz2[i]) > 0)
        {
            strcpy(palabraMenor, matriz2[i]);
            posmenor = i;
        }
    }
    return posmenor;
}

void intercambioPalabras(int clm, char matriz2[][clm], int posmenor, int r)
{
    char aux[clm];
    strcpy(aux, matriz2[posmenor]);
    strcpy(matriz2[posmenor], matriz2[r]);
    strcpy(matriz2[r], aux);
}

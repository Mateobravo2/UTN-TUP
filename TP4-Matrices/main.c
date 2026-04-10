#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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
void cargarArregloString(int r, int clm, char matriz2[][clm]);
void mostrarMatrizStrings(int r, int clm, char matriz2[][clm]);

int main()
{
    menu();
    return 0;
}
//MATRICES CON NUMEROS SE COMPLETA Y NO SE MODIFICA
//CON STRINGS NO SE PUEDE MODIFICAR PERO SE PUEDE
void menu()
{
    int op=0,existe=0;
    do
    {
        int r = 0, clm = 0;
        int matriz1[r][clm];
        printf("                                    ___________________________________\n");
        printf("                                    |[1]  CARGAR MATRIZ                     |\n");
        printf("                                    |[2]  MOSTRAR MATRIZ CARGADA            |\n");
        printf("                                    |[3]  CARGAR MATRIZ RANDOM              |\n");
        printf("                                    |[4]  SUMAR CONTENIDO DE UNA MATRIZ     |\n");
        printf("                                    |[5]  PROMEDIO DE UNA MATRIZ            |\n");
        printf("                                    |[6]  ENCONTRAR ELEMENTO EN UNA MATRIZ  |\n");
        printf("                                    |[7]  CARGAR ARREGLO DE PALABRAS        |\n");
        printf("                                    |[0]  |\n");
        printf("                                    -----------------------------------\n");
        scanf("%i", &op);
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
                    printf("Que cantidad de filas desea en la matriz?: ");
                    scanf("%i", &r);
                    printf("Que cantidad de columnas desea en la matriz?: ");
                    scanf("%i", &clm);
                    cargarMatriz(r, clm, matriz1);
                    mostrarMatriz(r, clm, matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                {
                    cargarMatriz(r, clm, matriz1);
                    mostrarMatriz(r, clm, matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                {
                    cargarMatrizRandom(r, clm, matriz1);
                    mostrarMatriz(r, clm, matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                {
                    int res = 0;
                    cargarMatriz(r, clm, matriz1);
                    res = sumarContenido(r, clm, matriz1);
                    mostrarMatriz(r, clm, matriz1);
                    printf("\nLa suma del contenido de la matriz es: %i\n", res);
                    system("pause");
                    system("cls");
                }
                break;
            case 5:
                {
                    cargarMatriz(r, clm, matriz1);
                    float res = calcularPromedioMatriz(r, clm, matriz1);
                    mostrarMatriz(r, clm, matriz1);
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
                    aux = encontrarNumero(r, clm, matriz1, num);
                    mostrarMatriz(r, clm, matriz1);
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
                    char matriz2[r][clm];
                    cargarArregloString(r, clm, matriz2);
                    mostrarMatrizStrings(r, clm, matriz2);
                }
                break;
            case 8:
                {

                }
                break;
            case 9:
                {

                }
                break;
            case 10:
                {

                }
                break;
            case 11:
                {

                }
                break;
            case 12:
                {

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
void cargarArregloString(int r, int clm, char matriz2[][clm])
{
    int i;
    for(i = 0; i < r; i++)
    {
        printf("Ingrese una cadena de |%i| caracteres: ", clm);
        fflush(stdin);
        gets(matriz2[i]);
    }
}

void mostrarMatrizStrings(int r, int clm, char matriz2[][clm])
{
    int i;
        for(i = 0; i < r; i++)
        {
            printf(" |%s| \n", matriz2[i]);
        }
}

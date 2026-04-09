#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define fila 3
#define columna 3

void menu();
//PUNTO 1
void cargarMatriz(int matriz1[][columna]);
//PUNTO 2
void mostrarMatriz(int matriz1[][columna]);
//PUNTO 3
void cargarMatrizRandom(int matriz1[][columna]);
//PUNTO 4
int sumarContenido(int matriz1[][columna]);
//PUNTO 5
float calcularPromedioMatriz(int matriz1[][columna]);
//PUNTO 6
int encontrarNumero(int matriz1[][columna], int num);
//PUNTO 7
void cargarArregloString(char matriz2[][columna]);
void mostrarMatrizStrings(char matriz2[][columna]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op=0;
    do
    {
        int matriz1[fila][columna];
        int matrizCargada[fila][columna] = {{1,2,3}, {4,5,6}, {7,8,9}};
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
                    cargarMatriz(matriz1);
                    mostrarMatriz(matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 2:
                {
                    mostrarMatriz(matrizCargada);
                    system("pause");
                    system("cls");
                }
                break;
            case 3:
                {
                    cargarMatrizRandom(matriz1);
                    mostrarMatriz(matriz1);
                    system("pause");
                    system("cls");
                }
                break;
            case 4:
                {
                    int aux = 0;
                    cargarMatriz(matriz1);
                    aux = sumarContenido(matriz1);
                    mostrarMatriz(matriz1);
                    printf("\nLa suma del contenido de la matriz es: %i\n", aux);
                    system("pause");
                    system("cls");
                }
                break;
            case 5:
                {
                    cargarMatriz(matriz1);
                    float res = calcularPromedioMatriz(matriz1);
                    mostrarMatriz(matriz1);
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
                    aux = encontrarNumero(matrizCargada, num);
                    mostrarMatriz(matrizCargada);
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
                    char matriz2[fila][columna];
                    cargarArregloString(matriz2);
                    mostrarMatrizStrings(matriz2);
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
void cargarMatriz(int matriz1[][columna])
{
    int i, j;
    for(i = 0; i < fila; i++)
    {
        printf("\nCarga de datos en fila n%i: ", i);
        for(j = 0; j < columna; j++)
        {
            printf("\nCarga de datos en columna n%i: ", j);
            scanf("%i", &matriz1[i][j]);
        }
    }
}

//PUNTO 2
void mostrarMatriz(int matriz1[][columna])
{
    int i, j;
    printf("\nMATRIZ:\n");
    for(i = 0; i < fila; i++)
    {
        for(j = 0; j < columna; j++)
        {
            printf(" |%i| ", matriz1[i][j]);
        }
        printf("\n");
    }
}

//PUNTO 3
void cargarMatrizRandom(int matriz1[][columna])
{
    int i, j;
    srand(time(NULL));
    for(i = 0; i < fila; i++)
    {
        for(j = 0; j < columna; j++)
        {
            matriz1[i][j] = rand()%100;
        }
    }
}

//PUNTO 4
int sumarContenido(int matriz1[][columna])
{
    int i, j, sum = 0;
    for(i = 0; i < fila; i++)
    {
        for(j = 0; j < columna; j++)
        {
            sum = sum + matriz1[i][j];
        }
    }
    return sum;
}

//PUNTO 5
float calcularPromedioMatriz(int matriz1[][columna])
{
    int i, j, k = 0;
    int aux = sumarContenido(matriz1);
    for(i = 0; i < fila; i++)
    {
        for(j = 0; j < columna; j++)
        {
            k++;
        }
    }
    return aux / k;
}

//PUNTO 6
int encontrarNumero(int matriz1[][columna], int num)
{
    int i, j, flag = 0;
    for(i = 0; i < fila && flag == 0; i++)
    {
        for(j = 0; j < columna && flag == 0; j++)
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
void cargarArregloString(char matriz2[][columna])
{
    int i;
    for(i = 0; i < fila; i++)
    {
        printf("Ingrese una cadena de |%i| caracteres: ", columna);
        fflush(stdin);
        gets(matriz2[i]);
    }
}

void mostrarMatrizStrings(char matriz2[][columna])
{
    int i;
        for(i = 0; i < fila; i++)
        {
            printf(" |%s| \n", matriz2[i]);
        }
}

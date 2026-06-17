#include <stdio.h>
#include <stdlib.h>

#define DIM 6

void menu();
//PUNTO 1
int calcularFactorialRecursivo(int num);
//PUNTO 2
int calcularPotenciaRecursiva(int num, int pot);
//PUNTO 3
void cargarArregloInt(int arr[], int dim);
void recorrerArregloRecursivo(int arr[], int validos);
//PUNTO 4
void recorrerArregloInvertidoRecursivo(int arr[], int validos);
//PUNTO 5
int esCapicua(int arr[], int inicio, int fin);
//PUNTO 6
int sumarElementosArr(int arr[], int validos, int i, int suma);
//PUNTO 7


int main()
{
    menu();
    return 0;
}

void menu()
{
    int arr[DIM];
    int op, num, aux = 0, pot;
    do
    {
        printf("Ingrese el ejercicio que quiere probar: \n");
        printf("_____________________________________\n");
        printf("| [1] Calcular factorial            |\n");
        printf("| [2] Calcular potencia             |\n");
        printf("| [3] Recorrer arreglo              |\n");
        printf("| [4] Recorrer arreglo invertido    |\n");
        printf("| [5] Descubrir si es capicua       |\n");
        printf("| [0] FINALIZAR PROGRAMA            |\n");
        printf("-------------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
            default:
                {
                    printf("~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~\n");
                    system("pause");
                    system("cls");
                }break;
            case 1:
                {
                   printf("Ingrese el numero que desea saber el factorial: ");
                   scanf("%i", &num);
                   aux = calcularFactorialRecursivo(num);
                   printf("%i\n", aux);
                   system("pause");
                   system("cls");
                }break;
            case 2:
                {
                    printf("Ingrese el numero que quiere saber la potencia: ");
                    scanf("%i", &num);
                    printf("Ingrese la potencia: ");
                    scanf("%i", &pot);
                    aux = calcularPotenciaRecursiva(num, pot);
                    printf("| %i | elevado a la | %i | potencia es igual a | %i |: ", num, pot, aux);
                    printf("\n");
                    system("pause");
                    system("cls");
                }break;
            case 3:
                {
                    cargarArregloInt(arr, DIM);
                    recorrerArregloRecursivo(arr, DIM-1);
                    printf("\n");
                    system("pause");
                    system("cls");
                }break;
            case 4:
                {
                    cargarArregloInt(arr, DIM);
                    recorrerArregloInvertidoRecursivo(arr, DIM-1);
                    printf("\n");
                    system("pause");
                    system("cls");
                }break;
            case 5:
                {
                    cargarArregloInt(arr, DIM);
                    if(esCapicua(arr, 0, DIM-1) != 1)
                    {
                        printf("El arreglo: ");
                        recorrerArregloRecursivo(arr, DIM-1);
                        printf(" NO es capicua\n");
                    }
                    else
                    {
                        printf("El arreglo: ");
                        recorrerArregloRecursivo(arr, DIM-1);
                        printf(" es capicua\n");
                    }
                    printf("\n");
                    system("pause");
                    system("cls");
                }break;
            case 6:
                {
                    cargarArregloInt(arr, DIM);
                    aux = sumarElementosArr(arr, DIM-1, 0,0);
                    printf("La suma del arreglo: ");
                    recorrerArregloRecursivo(arr, (DIM-1));
                    printf(" = | %i |", aux);
                    printf("\n");
                    system("pause");
                    system("cls");
                }break;
            case 0:
                {
                   printf("- - - FINALIZANDO PROGRAMA - - -\n");
                }break;
        }
    }while(op != 0);
}

//PUNTO 1
int calcularFactorialRecursivo(int num)
{
    int resu = 0;
    if(num == 0)
    {
        resu = 1;
    }
    else
    {
        resu = num * calcularFactorialRecursivo(num-1);
    }
    return resu;
}

//PUNTO 2
int calcularPotenciaRecursiva(int num, int pot)
{
    int resu = 0;
    if(pot == 0)
    {
        resu = 1;
    }
    else
    {
        resu = num * calcularPotenciaRecursiva(num, pot-1);
    }
    return resu;
}

//PUNTO 3
void cargarArregloInt(int arr[], int dim)
{
    int aux;
    int i = 0;
    while(i < dim)
    {
        printf("Ingrese un numero para ingresar al arreglo: ");
        scanf("%i", &aux);
        arr[i] = aux;
        i++;
    }
}

void recorrerArregloRecursivo(int arr[], int validos)
{
    if(validos == 0)
    {
        printf("| %i |", arr[validos]);
    }
    else
    {
        recorrerArregloRecursivo(arr, validos-1);
        printf("| %i |", arr[validos]);
    }
}

//PUNTO 4
void recorrerArregloInvertidoRecursivo(int arr[], int validos)
{
    if(validos == 0)
    {
        printf("| %i |", arr[validos]);
    }
    else
    {
        printf("| %i |", arr[validos]);
        recorrerArregloInvertidoRecursivo(arr, validos-1);
    }
}

//PUNTO 5
int esCapicua(int arr[], int inicio, int fin)
{
    int flag = 0;
    if(arr[inicio] != arr[fin])
    {
        flag = 0;
    }
    else
    {
        flag = esCapicua(arr, (inicio+1), (fin-1));
    }
    if(inicio >= fin)
    {
        flag = 1;
    }
    return flag;
}

//PUNTO 6
int sumarElementosArr(int arr[], int validos, int i, int suma)
{
    if(i == validos)
    {
        suma += arr[i];
    }
    else
    {
        suma = arr[i] + (sumarElementosArr(arr, validos, (i+1), suma));
    }
    return suma;
}

//PUNTO 7
int buscarMenorRecursivo(int arr[], int validos, int i, int menor)
{

    return i;
}

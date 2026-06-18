#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int buscarMenorRecursivo(int arr[], int validos, int menor, int i);
//PUNTO 8
void nombreDeArchivo(char nombre[]);
void cargarArchivo(char nombre[]);
int buscarMenorEnArchivo(char nombre[]);
int buscarMenorArchivoRecursivo(FILE *archi, int menor, char nombre[]);
void mostrarArchivo(char archivo[]);
//PUNTO 9
void invertirArchivo(char nombre[]);
void invertirElementosArchivo(char nombre[], FILE *archi, int j, int i);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int arr[DIM];
    int op, num, aux = 0, pot, menor;
    char nombre[15];
    do
    {
        printf("Ingrese el ejercicio que quiere probar: \n");
        printf("_____________________________________\n");
        printf("| [1] Calcular factorial            |\n");
        printf("| [2] Calcular potencia             |\n");
        printf("| [3] Recorrer arreglo              |\n");
        printf("| [4] Recorrer arreglo invertido    |\n");
        printf("| [5] Descubrir si es capicua       |\n");
        printf("| [6] Sumar elementos de arreglo    |\n");
        printf("| [7] Buscar menor en arreglo       |\n");
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
            case 7:
                {
                    cargarArregloInt(arr, DIM);
                    menor = buscarMenorRecursivo(arr, DIM, arr[0], 1);
                    recorrerArregloRecursivo(arr, DIM-1);
                    printf("\nEl menor es | %i |\n", menor);
                    system("pause");
                    system("cls");
                }break;
            case 8:
                {
                    nombreDeArchivo(nombre);
                    cargarArchivo(nombre);
                    menor = buscarMenorEnArchivo(nombre);
                    mostrarArchivo(nombre);
                    printf("\nEl menor es | %i |\n", menor);
                    system("pause");
                    system("cls");
                }break;
            case 9:
                {
                    nombreDeArchivo(nombre);
                    printf("\nArchivo normal: \n");
                    mostrarArchivo(nombre);
                    invertirArchivo(nombre);
                    printf("\nArchivo invertido: \n");
                    mostrarArchivo(nombre);
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
int buscarMenorRecursivo(int arr[], int validos, int menor, int i)
{
    if(i != validos)
    {
        if(arr[i] < menor)
        {
            menor = arr[i];
            menor = buscarMenorRecursivo(arr, validos, menor, (i+1));
        }
        else
        {
            menor = buscarMenorRecursivo(arr, validos, menor, (i+1));
        }
    }
    return menor;
}

//PUNTO 8
void nombreDeArchivo(char nombre[])
{
    printf("Ingrese el nombre del archivo al que quiere acceder: ");
    scanf(" %s", nombre);
    strcat(nombre, ".bin");
}

void cargarArchivo(char nombre[])
{
    int aux;
    char op = 's';
    FILE *archi = fopen(nombre, "ab");
    if(archi != NULL)
    {
        while(op != 'n')
        {
            printf("Ingrese un numero: ");
            scanf("%i", &aux);
            fwrite(&aux, sizeof(int), 1, archi);
            printf("Quiere seguir ingresando numeros al arreglo? (s/n): ");
            scanf(" %c", &op);
        }
        fclose(archi);
    }
}

int buscarMenorEnArchivo(char nombre[])
{
    int menor;
    FILE *archi;
    archi = fopen(nombre, "rb");
    if(archi != NULL)
    {
        menor = fread(nombre, sizeof(int), 1, archi);
        menor = buscarMenorArchivoRecursivo(archi, menor, nombre);
        fclose(archi);
    }
    return menor;
}

int buscarMenorArchivoRecursivo(FILE *archi, int menor, char nombre[])
{
    int aux = fread(nombre, sizeof(int), 1, archi);
    if(!feof(archi))
    {
        if(aux < menor)
        {
            menor = aux;
            buscarMenorArchivoRecursivo(archi, menor, nombre);
        }
        else
        {
            buscarMenorArchivoRecursivo(archi, menor, nombre);
        }
    }
    return menor;
}

void mostrarArchivo(char archivo[])
{
    int aux;
    FILE *archi;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(int), 1, archi);
            if(!feof(archi))
            {
                printf(" |%i| ", aux);
            }
        }
        fclose(archi);
    }
}

//PUNTO 9
void invertirArchivo(char nombre[])
{
    int total;
    FILE *archi = fopen(nombre, "r+b");
    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_END);
        total = (ftell(archi) / sizeof(int))-1;
        printf("\n | %i |\n", total);
        invertirElementosArchivo(nombre, archi, total, 0);
        fclose(archi);
    }
}

void invertirElementosArchivo(char nombre[], FILE *archi, int j, int i)
{
    int num1, num2;
    if(i < j)
    {
        fseek(archi, (sizeof(int)*i), SEEK_SET);
        fread(&num1, sizeof(int), 1, archi);
        fseek(archi, sizeof(int)*j, SEEK_SET);
        fread(&num2, sizeof(int), 1, archi);
        fseek(archi, sizeof(int)*j, SEEK_SET);
        fwrite(&num1, sizeof(int), 1, archi);
        fseek(archi, (sizeof(int)*i), SEEK_SET);
        fwrite(&num2, sizeof(int), 1, archi);
        fseek(archi, sizeof(int), SEEK_SET);
        invertirElementosArchivo(nombre, archi, (j-1), (i+1));
    }
}

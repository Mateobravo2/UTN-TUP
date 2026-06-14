#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 5

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio;
}Alumno;


void menu();
int* cargarArregloDinamicoInt(int *validos);
//PUNTO 1
void aumentarDimDeArregloDinamico(int** arr, int cant);
int* crearArregloDin(int** arr, int arrInt[], int validos);
int contarPares(int arrInt[], int validos);
void pasarParesArregloDin(int arrDin[], int arrInt[], int validos);
void mostrarArr(int arr[], int validos);
//PUNTO 2
void nombreDeArchivo(char alumnos[]);
Alumno* arregloDinamicoAlumno();
void aumentarArrDinAlum(Alumno** arr, int cant);
int contarElementosEnArchivo(char nombre[]);
int pasarArchivoAArreglo(Alumno** arr, char nombre[]);
int contarCantidadAlumnos(char archivo[], int edad);
void mostrarAlumno(Alumno alumno);
void mostrarArrAlum(Alumno arr[], int validos);
//PUNTO 3
int pasarAlumnosDeMayores(Alumno arr[], int validos, int edad, Alumno** arrDin);
//PUNTO 4
int combinarArreglosDinamicos(int validos1, int **arr, int validos2, int *arr2);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int arrInt[DIM] = {2, 13, 24, 33, 52};
    int *arrDin;
    int *arrInt1 = (int*) malloc((sizeof(int)*3));
    int *arrInt2 = (int*) malloc((sizeof(int)*3));
    int *arrInt3 = (int*) malloc((sizeof(int)));
    int *arrInt4 = (int*) malloc((sizeof(int)));
    int op, aux = 0, validosArrAlum = 0, validosArrAlum2 = 0, validos = 0;
    char nombre[30];
    Alumno *arrAlum = arregloDinamicoAlumno();
    Alumno *arrAlum2 = arregloDinamicoAlumno();
    do
    {
        printf("Ingrese el ejercicio que quiere probar: \n");
        printf("_______________________________________________\n");
        printf("|[1] PASAR PARES A ARREGLO DE TAMANIO JUSTO   |\n");
        printf("|[2] PASAR DE ARCHIVO A ARREGLO TAMANIO JUSTO |\n");
        printf("|[3] PASAR ALUMNOS MAYORES A X EDAD           |\n");
        printf("|[4] AGREGAR ARREGLO 2 A ARREGLO 1            |\n");
        printf("|[5] DUPLICAR TAMANIO DE ARREGLO              |\n");
        printf("|[6] AGREGAR NUMERO A ARREGLO DINAMICO        |\n");
        printf("|[0] FINALIZAR PROGRAMA |\n");
        printf("----------------------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
        default:
            {
                printf("~ ~ ~ INGRESE UNA OPCION VALIDA ~ ~ ~");
                system("pause");
                system("cls");
            }break;
        case 1:
            {
                arrDin = crearArregloDin(&arrDin, arrInt, DIM);
                mostrarArr(arrInt, DIM);
                aux = contarPares(arrInt, DIM);
                printf("\n");
                mostrarArr(arrDin, aux);
                system("pause");
                system("cls");
            }break;
        case 2:
            {
                nombreDeArchivo(nombre);
                validosArrAlum = pasarArchivoAArreglo(&arrAlum, nombre);
                mostrarArrAlum(arrAlum, validosArrAlum);
                system("pause");
                system("cls");
            }break;
        case 3:
            {
                printf("Ingrese la edad que desea filtrar: ");
                scanf("%i", &aux);
                validosArrAlum2 = pasarAlumnosDeMayores(arrAlum, validosArrAlum, aux, &arrAlum2);
                mostrarArrAlum(arrAlum2, validosArrAlum2);
                system("pause");
                system("cls");
            }break;
        case 4:
            {
                printf("CARGAR ARRELGO 1\n");
                for(int i =0; i < 3;i++)
                {
                    printf("Ingrese un numero: ");
                    scanf("%i", &aux);
                    arrInt1[i] = aux;
                }
                printf("\nCARGAR ARREGLO 2\n");
                for(int i = 0; i < 3; i++)
                {
                    printf("Ingrese un numero: ");
                    scanf("%i", &aux);
                    arrInt2[i] = aux;
                }
                validos = combinarArreglosDinamicos(3, &arrInt1, 3, arrInt2);
                mostrarArr(arrInt1, validos);
                system("pause");
                system("cls");
            }break;
        case 5:
            {
                arrInt3 = cargarArregloDinamicoInt(&aux);
                aumentarDimDeArregloDinamico(&arrInt3, (validos*2));
                mostrarArr(arrInt3, aux);
                system("pause");
                system("cls");
            }break;
        case 0:
            {
                printf("- - - FINALIZANDO EL PROGRAMA - - -");
            }break;
        }
    }while(op != 0);
}

int* cargarArregloDinamicoInt(int *validos)
{
    int aux = 0;
    int *arr = (int*) malloc((sizeof(int)));
    char op = 's';
    for(int i = 0; op != 'n'; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%i", &aux);
        arr[i] = aux;
        printf("Quiere seguir ingresando numeros al arreglo? (s/n): ");
        scanf(" %c", &op);
        validos++;
        int* arr = (int*) realloc((*arr), sizeof(int)* validos);
    }
    return arr;
}

//PUNTO 1
int* crearArregloDin(int** arr, int arrInt[], int validos)
{
    int cant = 0;
    int* arreglo2 = (int*) malloc(sizeof(int));
    cant = contarPares(arrInt, validos);
    aumentarDimDeArregloDinamico(&arreglo2, cant);
    pasarParesArregloDin(arreglo2, arrInt, validos);
    if(arreglo2 != NULL)
    {
        (*arr) = arreglo2;
    }
    return *arr;
}

void aumentarDimDeArregloDinamico(int** arr, int cant)
{
    int* arreglo2 = (int*) realloc((*arr), sizeof(int)*cant);
    if(arreglo2 != NULL)
    {
        (*arr) = arreglo2;
    }
}

int contarPares(int arrInt[], int validos)
{
    int i = 0, cant = 0;
    while(i < validos)
    {
        if(arrInt[i]%2==0)
        {
            cant++;
        }
        i++;
    }
    return cant;
}

void pasarParesArregloDin(int arrDin[], int arrInt[], int validos)
{
    int i = 0, j = 0;
    while(i < validos)
    {
        if(arrInt[i]%2==0)
        {
            arrDin[j] = arrInt[i];
            j++;
        }
        i++;
    }
}

void mostrarArr(int arr[], int validos)
{
    int i = 0;
    while(i < validos)
    {
        printf("Elemento %i: | %i |\n", i, arr[i]);
        i++;
    }
}

//PUNTO 2
void nombreDeArchivo(char alumnos[])
{
    printf("Ingrese el nombre del archivo al que quiere acceder: ");
    scanf(" %s", alumnos);
    strcat(alumnos, ".bin");
}

Alumno* arregloDinamicoAlumno()
{
    Alumno *arr;
    Alumno* arrDin = (Alumno*) malloc(sizeof(Alumno));
    if(arrDin != NULL)
    {
        arr = arrDin;
    }
    return arr;
}

void aumentarArrDinAlum(Alumno** arr, int cant)
{
    Alumno* arreglo2 = (Alumno*) realloc((*arr), sizeof(Alumno)*cant);
    if(arreglo2 != NULL)
    {
        (*arr) = arreglo2;
    }
}

int contarElementosEnArchivo(char nombre[])
{
    int cant = 0;
    FILE *archi;
    archi = fopen(nombre, "rb");
    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_END);
        cant = (ftell(archi) / sizeof(Alumno));
        fclose(archi);
    }
    return cant;
}

int pasarArchivoAArreglo(Alumno** arr, char nombre[])
{
    int i = 0;
    Alumno aux;
    int cant = contarElementosEnArchivo(nombre);
    aumentarArrDinAlum(arr, cant);
    FILE *archi = fopen(nombre, "rb");
    if(archi != NULL)
    {
        while(fread(&aux, sizeof(Alumno), 1, archi) > 0)
        {
            (*arr)[i] = aux;
            i++;
        }
        fclose(archi);
    }
    return cant;
 }

void mostrarAlumno(Alumno alumno)
{
    printf("\nLegajo de alumno: | %i |", alumno.legajo);
    printf("\nNombre y apellido de alumno: %s", alumno.nombreYapellido);
    printf("\nEdad del alumno: %i", alumno.edad);
    printf("\nAnio que cursa el alumno: %i\n", alumno.anio);
}

void mostrarArrAlum(Alumno arr[], int validos)
{
    int i = 0;
    Alumno aux;
    while(i < validos)
    {
        aux = arr[i];
        mostrarAlumno(aux);
        i++;
    }
}

//PUNTO 3
int pasarAlumnosDeMayores(Alumno arr[], int validos, int edad, Alumno** arrDin)
{
    int i = 0, j = 0;
    while(i < validos)
    {
        if(arr[i].edad > edad)
        {
            aumentarArrDinAlum(arrDin, j+1);
            (*arrDin)[j] = arr[i];
            j++;
        }
        i++;
    }
    return j+1;
}

//PUNTO 4
int combinarArreglosDinamicos(int validos1, int **arr, int validos2, int* arr2)
{
    int i = 0;
    int j = (validos1);
    int nuevosValidos = (validos1 + validos2);
    while(i < validos2)
    {
        aumentarDimDeArregloDinamico(arr, (j+1));
        (*arr)[j] = arr2[i];
        i++;
        j++;
    }
    return nuevosValidos;
}

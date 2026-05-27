#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int edad;
    char nombre[30];
    char raza[30];
    char genero; //F o M
}Mascota;

void menu();
//EJERCICIO 2
int contarPares(int arr[], int dim);
int* crearArrMalloc(int cantPares);
void cargarArrPares(int arr[], int arrPares[], int dim);
void mostrarArregloInt(int arr[], int validos);
void crearArrMalloc2(int cantPares, int** arrPares2);
//EJERCICIO 3
Mascota crearMascota();
Mascota* crearArrMascota();
Mascota* llenarArrMascota(Mascota *arrMascota, int *validos);
Mascota* crearArrRealloc(Mascota *arrMascota, int dim);
void mostrarMascota(Mascota mascota, int i);
void mostrarArregloMascota(Mascota mascota[], int validos);

int main()
{
    menu();
    printf("\n");

    return 0;
}

void menu()
{
    int op;
    do
    {
        printf("Ingrese el ejercicio que quiere probar [1-8]: \n");
        printf("            _____________________________________________\n");
        printf("            | [1] Cargar arreglo de alumnos             |\n");
        printf("            | [2] Mostrar arreglo alumnos               |\n");
        printf("            | [3] Mostrar alumno por matricula          |\n");
        printf("            | [0] Finalizar el programa                 |\n");
        printf("            ---------------------------------------------\n");
        scanf("%i", &op);
        system("cls");
        switch(op)
        {
            case 0:
                {
                    printf("\n- - - FINALIZANDO EL PROGRAMA - - -\n");
                }break;
            case 1:
                {
                        int valor = 10;
                        int *p = &valor;
                        int **pp = &p;
                        printf("EJERCICIO 1)A)\n");
                        printf("%i\n", &valor);
                        printf("%i\n", p);
                        printf("%i\n\n", pp);
                        printf("%i\n", valor);
                        printf("%i\n", *p);
                        printf("%i\n\n", **pp);

                        printf("EJERCICIO 1)B)\n");
                        valor = 5;
                        printf("%i\n", valor);
                        *p = 6;
                        printf("%i\n", valor);
                        **pp = 7;
                        printf("%i\n\n", valor);

                    system("pause");
                    system("cls");
                }break;
            case 2:
                {
                    int arr[5] = {1, 4, 9, 8, 7};
                    int valPares = contarPares(arr, 5);
                    int *arrPares = crearArrMalloc(valPares);
                    printf("EJERCICIO 2)A)\n");
                    cargarArrPares(arr, arrPares, 5);
                    mostrarArregloInt(arrPares, valPares);

                    printf("EJERCICIO 2)C)\n");
                    int *arrPares2 = NULL;
                    crearArrMalloc2(valPares, &arrPares2);
                    cargarArrPares(arr, arrPares2, 5);
                    mostrarArregloInt(arrPares2, valPares);

                    system("pause");
                    system("cls");
                }break;
            case 3:
                {
                    int validos = 1;
                    Mascota *arrMascota = NULL;
                    arrMascota = crearArrMascota();
                    arrMascota = llenarArrMascota(arrMascota, &validos);
                    mostrarArregloMascota(arrMascota, validos);
                    system("pause");
                    system("cls");
                }break;
            default:
                {
                    printf("\n~ ~ ~ Ingrese una opcion valida ~ ~ ~\n");
                    system("pause");
                    system("cls");
                }break;
            }
    }while(op != 0);
}

//EJERCICIO 2
int contarPares(int arr[], int dim)
{
    int cont = 0;
    for(int i = 0; i < dim; i++)
    {
        if(arr[i]%2==0)
        {
            cont++;
        }
    }
    return cont;
}

int* crearArrMalloc(int cantPares)
{
    int *arrPares = (int *) malloc (cantPares * sizeof(int));
    return arrPares;
}

void cargarArrPares(int arr[], int arrPares[], int dim)
{
    int j = 0;
    for(int i = 0; i < dim; i++)
    {
        if(arr[i]%2==0)
        {
            arrPares[j] = arr[i];
            j++;
        }
    }
}

void mostrarArregloInt(int arr[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("| %i |\n", arr[i]);
    }
}

void crearArrMalloc2(int cantPares, int** arrPares2)
{
    *arrPares2 = (int *) malloc (cantPares * sizeof(int));
}

//EJERCICIO 3
Mascota* crearArrMascota()
{
    Mascota* arrMascota = (Mascota*) malloc (1 * sizeof(Mascota));
    return arrMascota;
}

Mascota* crearArrRealloc(Mascota *arrMascota, int dim)
{
    Mascota *arrMascotaAux;
    arrMascotaAux =(Mascota*) realloc (arrMascota, dim*sizeof(Mascota));
    if(arrMascotaAux == NULL)
    {
        arrMascotaAux = arrMascota;
        printf("~ ~ ~ ERROR, NO HAY ESPACIO EN LA MEMORIA ~ ~ ~");
    }
    return arrMascotaAux;
}

Mascota crearMascota()
{
    Mascota mascotaAux;
    printf("Ingrese la mascota: \n");
    printf("    Edad de la mascota: ");
    scanf("%i", &mascotaAux.edad);
    printf("    Nombre de la mascota: ");
    scanf(" %s", &mascotaAux.nombre);
    printf("    Raza de la mascota: ");
    scanf(" %s", &mascotaAux.raza);
    printf("    Genero de la mascota: ");
    scanf(" %c", &mascotaAux.genero);
    return mascotaAux;
}

Mascota* llenarArrMascota(Mascota *arrMascota, int *validos)
{
    int i = 0;
    char op = 's';
    do
    {
        arrMascota[i] = crearMascota();
        printf("\nDesea ingresar otra mascota? (s / n):");
        scanf(" %c", &op);
        if(op == 's')
        {
            (*validos)++;
            arrMascota = crearArrRealloc(arrMascota, (*validos)+1);
        }
        i++;
    }while(op != 'n');
    return arrMascota;
}

void mostrarArregloMascota(Mascota mascota[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        mostrarMascota(mascota[i], i+1);
    }
}

void mostrarMascota(Mascota mascota, int i)
{
    printf("- MASCOTA %i-\n", i);
    printf("Edad: %i\n", mascota.edad);
    printf("Nombre: %s\n", mascota.nombre);
    printf("Raza: %s\n", mascota.raza);
    printf("Genero: %c\n", mascota.genero);
}

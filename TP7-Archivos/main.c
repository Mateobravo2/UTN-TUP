#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define ARCHIVO "enteros.bin"

typedef struct
{
    int legajo;
    char nombreYApellido[30];
    int edad;
    int anio;
}Alumno;

void menu();
//PUNTO 1
void agregarElementoArchivo(char archivo[]);
//PUNTO 2
void mostrarArchivo(char archivo[]);
//PUNTO 3
int contarElementosArchivoInt(char nombreArchivo[]);
//PUNTO 4
Alumno crearAlumno();
void cargarArchivoAlumnos (char archivo[]);
//PUNTO 5
void mostrarAlumno(Alumno alumno);
void mostrarArchivoAlumnos(char nombreAr[]);
//PUNTO 6
void agregarAlumnoArchivo(char archivo[]);
//PUNTO 7
void pasarLegajoaPila(char nombreArchivo[], Pila *pilita);
//PUNTO 8
int contarCantidadAlumnos(char archivo[], int edad);
//PUNTO 9
void mostrarAlumnosRangoEdad(char archivo[], int menor, int mayor);
//PUNTO 10
void buscarAlumnoMayor(char archivo[]);
//PUNTO 11
int cantidadAlumnosEnAnio(char archivo[], int anio);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op, aux = 0, edad, aux2 = 0;
    char alumnos[20];
    Pila pilita;
    inicpila(&pilita);
    do
    {
        printf("Ingrese el ejercicio que quiere probar [1-8]: \n");
        printf("                 _____________________________________________\n");
        printf("                 | [1] Agregar elemento a archivo (INT)      |\n");
        printf("                 | [2] Mostrar elemento de archivo (INT)     |\n");
        printf("                 | [3] Contar elementos de archivo (INT)     |\n");
        printf("                 | [4] Cargar archivo de alumnos             |\n");
        printf("                 | [5] Mostar archivo de alumnos             |\n");
        printf("                 | [6] Cargar 1 alumno en archivo            |\n");
        printf("                 | [7] Pasar legajos a pila                  |\n");
        printf("                 | [8] Contar alumnos con X edad             |\n");
        printf("                 | [9] Mostrar alumnos entre Y edad y X edad |\n");
        printf("                 | [10] Mostrar alumno mayor                 |\n");
        printf("                 | [11] Cantidad de allumnos en X anio       |\n");
        printf("                 | [12] |\n");
        printf("                 | [13] |\n");
        printf("                 | [14] |\n");
        printf("                 | [15] |\n");
        printf("                 | [16] |\n");
        printf("                 | [0] |\n");
        printf("                 ---------------------------------------------\n");
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
                    agregarElementoArchivo(ARCHIVO);
                    system("pause");
                    system("cls");
                }break;
            case 2:
                {
                    mostrarArchivo(ARCHIVO);
                    system("pause");
                    system("cls");
                }break;
            case 3:
                {
                    contarElementosArchivoInt(ARCHIVO);
                    system("pause");
                    system("cls");
                }break;
            case 4:
                {
                    printf("Ingrese el nombre del archivo: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    cargarArchivoAlumnos(alumnos);
                    system("pause");
                    system("cls");
                }break;
            case 5:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    mostrarArchivoAlumnos(alumnos);
                    system("pause");
                    system("cls");
                }break;
            case 6:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    agregarAlumnoArchivo(alumnos);
                    system("pause");
                    system("cls");
                }break;
            case 7:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    pasarLegajoaPila(alumnos, &pilita);
                    mostrar(&pilita);
                    system("pause");
                    system("cls");
                }break;
            case 8:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    printf("Ingrese una edad: ");
                    scanf("%i", &edad);
                    aux = contarCantidadAlumnos(alumnos, edad);
                    printf("Hay |%i| alumnos con esa edad\n", aux);
                    system("pause");
                    system("cls");
                }break;
            case 9:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    printf("Ingrese la edad MENOR del rango: ");
                    scanf("%i", &aux);
                    printf("Ingrese la edad MAYOR del rango: ");
                    scanf("%i", &aux2);
                    mostrarAlumnosRangoEdad(alumnos, aux, aux2);
                    system("pause");
                    system("cls");
                }break;
            case 10:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    printf("El alumno mayor de edad es: ");
                    buscarAlumnoMayor(alumnos);
                    system("pause");
                    system("cls");
                }break;
            case 11:
                {
                    printf("Ingrese el nombre del archivo que quiere leer: ");
                    scanf(" %s", alumnos);
                    strcat(alumnos, ".bin");
                    printf("De que anio desea saber la cantidad de alumnos?: ");
                    scanf("%i", &aux);
                    aux2 = cantidadAlumnosEnAnio(alumnos, aux);
                    printf("\nEn el anio |%i| hay |%i| alumnos", aux, aux2);
                    system("pause");
                    system("cls");
                }break;
            case 12:
                {

                    system("pause");
                    system("cls");
                }break;
            case 13:
                {

                    system("pause");
                    system("cls");
                }break;
            default:
                {
                    printf("\n- - - Ingrese una opcion valida - - -\n");
                    system("pause");
                    system("cls");
                }break;
            }
    }while(op != 0);
}

//PUNTO 1
void agregarElementoArchivo(char archivo[])
{
    int aux;
    FILE *archi;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {
        printf("Ingresar numero: ");
        scanf("%i", &aux);
        printf("\n");
        fwrite(&aux, sizeof(int), 1, archi);
        fclose(archi);
    }
}

//PUNTO 2
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

//PUNTO 3
int contarElementosArchivoInt(char nombreArchivo[])
{
    int aux = 0;
    FILE *archi;
    archi = fopen(nombreArchivo, "rb");
    if(archi!=NULL)
    {
        fseek(archi, 0, SEEK_END);
        aux = ftell(archi)/sizeof(int);
        fclose(archi);
    }
    return aux;
}

//PUNTO 4
Alumno crearAlumno()
{
    Alumno alum;
    printf("\nIngrese el legajo del alumno: ");
    scanf("%i", &alum.legajo);
    printf("Ingrese el nombre y el apellido del alumno: ");
    scanf(" %s", alum.nombreYApellido);
    printf("Ingrese la edad del alumno: ");
    scanf("%i", &alum.edad);
    printf("Ingrese el anio que cursa el alumno: ");
    scanf("%i", &alum.anio);
    return alum;
}

void cargarArchivoAlumnos (char archivo[])
{
    int i = 0;
    Alumno aux;
    FILE *archi;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {
        while(i < 5)
        {
            aux = crearAlumno();
            printf("\n");
            fwrite(&aux, sizeof(Alumno), 1, archi);
            i++;
        }
        fclose(archi);
    }
}

//PUNTO 5
void mostrarAlumno(Alumno alumno)
{
    printf("\n-------------------------------");
    printf("\n LEGAJO: %i", alumno.legajo);
    printf("\n NOMBRE Y APELLIDO: %s", alumno.nombreYApellido);
    printf("\n EDAD: %i", alumno.edad);
    printf("\n ANIO: %i", alumno.anio);
    printf("\n-------------------------------\n");
}

void mostrarArchivoAlumnos(char nombreArchivo[])
{
    FILE *archi;
    Alumno aux;
    archi = fopen(nombreArchivo, "rb");
    int i=0;

    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(Alumno), 1, archi);
            if(!feof(archi))
            {
                printf("Alumno N %i: ", i++);
                mostrarAlumno(aux);
            }
        }
        fclose(archi);
    }
}

//PUNTO 6
void agregarAlumnoArchivo(char archivo[])
{
    Alumno aux;
    FILE *archi;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {
        aux = crearAlumno();
        printf("\n");
        fwrite(&aux, sizeof(Alumno), 1, archi);
        fclose(archi);
    }
}

//PUNTO 7
void pasarLegajoaPila(char nombreArchivo[], Pila *pilita)
{
    Alumno aux;
    FILE *archi;
    archi = fopen(nombreArchivo, "rb");
    if(archi!=NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(Alumno), 1, archi);
            if(!feof(archi) && aux.edad >= 18)
            {
                apilar(pilita, aux.legajo);
            }
        }
        fclose(archi);
    }
}

//PUNTO 8
int contarCantidadAlumnos(char archivo[], int edad)
{
    int i=0;
    Alumno aux;
    FILE *archi;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(Alumno), 1, archi);
            if(!feof(archi) && aux.edad == edad)
            {
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

//PUNTO 9
void mostrarAlumnosRangoEdad(char archivo[], int menor, int mayor)
{
    FILE *archi;
    Alumno aux;
    archi = fopen(archivo, "rb");
    printf("Nombres de los alumnos que tienen entre |%i| y |%i| anios: \n", menor, mayor);
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(Alumno), 1, archi);
            if(!feof(archi) && menor > aux.edad < mayor)
            {
                printf(" %s", aux.nombreYApellido);
            }
        }
    }
}

//PUNTO 10
void buscarAlumnoMayor(char archivo[])
{
    FILE *archi;
    Alumno aux, mayor;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(Alumno), 1, archi);
            if(!feof(archi) && aux.edad > mayor.edad)
            {
                mayor = aux;
            }
        }
    }
    mostrarAlumno(mayor);
}

//PUNTO 11
int cantidadAlumnosEnAnio(char archivo[], int anio)
{
    int i = 0;
    FILE *archi;
    Alumno aux;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        while(!feof(archi))
        {
            fread(&aux, sizeof(Alumno), 1, archi);
            if(!feof(archi) && aux.anio == anio)
            {
                i++;
            }
        }
    }
    return i;
}

//PUNTO 12

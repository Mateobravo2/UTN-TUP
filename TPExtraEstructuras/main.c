#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  legajo;
    char nombre[30];
    char genero;   // 'm', 'f', 'o'
} Alumno;

typedef struct {
    int codigo;
    char nombre[20];
    Alumno listadoDeAlumnos[40];
    int cantAlumnos;
} Materia;

void menu();
//PUNTO 1
int crearArregloMaterias();
Materia crearMateria(int i);
Alumno crearAlumno();
void mostrarArregloMaterias(Materia materia, int validos);
void mostrarMateria(Materia materia, Alumno listadoDeAlumnos[], int i);
void mostrarAlumno(Alumno alumno);

int main()
{
    menu();
    return 0;
}

void menu()
{

}

//PUNTO 1
int crearArregloMaterias(Alumno listadoDeAlumnos[], int dim)
{
    int i;
    for(i = 0; i < dim; i++)
    {
        crearMateria(i);
    }
    return i;
}

Materia crearMateria(int i)
{
    Materia materiaux;
    Alumno alumnoaux;
    printf("Ingrese el codigo de la materia: ");
    scanf("%i", &materiaux.codigo);
    printf("Ingrese el nombre de la materia: ");
    scanf(" %s", &materiaux.nombre);
    alumnoaux = crearAlumno();
    materiaux.listadoDeAlumnos[i] = alumnoaux;
    printf("Ingrese el codigo de la materia: ");
    return materiaux;
}

Alumno crearAlumno()
{
    Alumno alumnoaux;
    printf("Ingrese el legajo del alumno: ");
    scanf("%i", &alumnoaux.legajo);
    printf("Ingrese el nombre del alumno: ");
    scanf(" %s", &alumnoaux.nombre);
    printf("Ingrese el genero del alumno (m / f / o): ");
    scanf(" %c", &alumnoaux.genero);
    return alumnoaux;
}

void mostrarArregloMaterias(Materia materia, int validos)
{
    int i;
    for(i = 0; i < validos; i++)
    {
        mostrarMateria(materia, materia.listadoDeAlumnos, i);
    }
}

void mostrarMateria(Materia materia, Alumno listadoDeAlumnos[], int i)
{
    printf("\nCodigo de la materia: %i", materia.codigo);
    printf("\nNombre de la materia: %s\n", materia.nombre);
    printf("\nAlumno: ");
    mostrarAlumno(listadoDeAlumnos[i]);
    printf("\nCantidad de alumnos de la materia: %i", materia.cantAlumnos);
}

void mostrarAlumno(Alumno alumno)
{
    printf("\n  Legajo del alumno: %i", alumno.legajo);
    printf("\n  Nombre del alumno: %s", alumno.nombre);
    printf("\n  Genero del alumno: %c", alumno.genero);
}

//PUNTO 2

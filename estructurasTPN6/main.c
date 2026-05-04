#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    char genero;
}stAlumno;

void menu();
//PUNTO 1
int cargarArregloAlumnos(stAlumno alumnos[], int dim);
stAlumno crearAlumno();
//PUNTO 2
void mostrarArregloAlumnos(stAlumno alumnos[], int dim);
void mostrarAlumno(stAlumno alumnos);
//PUNTO 3
int buscarArregloAlumnos(stAlumno alumnos[], int validos, int matricula);
//PUNTO 4
void ordenarPorSeleccion(stAlumno alumnos[], int validos);
int posicionMenor(stAlumno alumnos[], int posInicial, int validos);
//PUNTO 5
void mostrarAlumnosGenero(stAlumno alumnos[], int validos, char genero);
//PUNTO 6
int insertarAlumnoEnArreglo(stAlumno alumnos[], int validos, stAlumno alumno);
//PUNTO 7
void ordenarPorInsercion(stAlumno alumnos[], int validos);
void insertar(stAlumno alumnos[], int posInicial, stAlumno alumno);
//PUNTO 8
int contarAlumnosXGenero(stAlumno alumnos[], int validos, char genero);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op, aux, validos;
    char genero;
    stAlumno alumnos[100];
    stAlumno nuevoAlumno;
    printf("Ingrese el ejercicio que quiere probar [1-8]: \n");
    printf("            _____________________________________________\n");
    printf("            | [1] Cargar arreglo de alumnos             |\n");
    printf("            | [2] Mostrar arreglo alumnos               |\n");
    printf("            | [3] Mostrar alumno por matricula          |\n");
    printf("            | [4] Ordenar alumnos por seleccion         |\n");
    printf("            | [5] Mostrar alumnos de un genero          |\n");
    printf("            | [6] Insertar alumno en arreglo ordenado   |\n");
    printf("            | [7] Ordenar alumnos por insercion         |\n");
    printf("            | [8] Contar alumnos de un genero           |\n");
    printf("            | [0] Finalizar el programa                 |\n");
    printf("            ---------------------------------------------\n");
    scanf("%i", &op);
    system("cls");
    do
    {
        switch(op)
        {
            case 0:
                {
                    printf("\n- - - FINALIZANDO EL PROGRAMA - - -\n");
                }break;
            case 1:
                {
                    validos = cargarArregloAlumnos(alumnos, 100);
                    system("pause");
                    system("cls");
                }break;
            case 2:
                {
                    mostrarArregloAlumnos(alumnos, validos);
                    system("pause");
                    system("cls");
                }break;
            case 3:
                {
                    printf("De que matricula desea saber los datos: ");
                    scanf("%i", &aux);
                    int posicion = buscarArregloAlumnos(alumnos, validos, aux);
                    if(posicion != -1)
                    {
                    mostrarAlumno(alumnos[posicion]);
                    }
                    else
                    {
                        printf("No existe ningun alumno con esa matricula!!\n");
                    }
                    system("pause");
                    system("cls");
                }break;
            case 4:
                {
                    ordenarPorSeleccion(alumnos, validos);
                    mostrarArregloAlumnos(alumnos, validos);
                    system("pause");
                    system("cls");
                }break;
            case 5:
                {
                    printf("Los alumnos de que genero desea mostrar (m/f/o)");
                    scanf(" %c", &genero);
                    mostrarAlumnosGenero(alumnos, validos, genero);
                    system("pause");
                    system("cls");
                }break;
            case 6:
                {
                    printf("Ingrese un nuevo alumno: \n");
                    nuevoAlumno = crearAlumno();
                    validos = insertarAlumnoEnArreglo(alumnos, validos, nuevoAlumno);
                    mostrarArregloAlumnos(alumnos, validos);
                    system("pause");
                    system("cls");
                }break;
            case 7:
                {
                    ordenarPorInsercion(alumnos, validos);
                    system("pause");
                    system("cls");
                }break;
            case 8:
                {
                    printf("De que genero desea saber la cantidad de alumnos? (m/f/o)");
                    scanf(" %c", &genero);
                    aux = contarAlumnosXGenero(alumnos, validos, genero);
                    system("pause");
                    system("cls");
                }break;
            default:
                {
                    printf("\n~ ~ ~ Ingrese una opcion valida ~ ~ ~\n");
                    system("pause");
                    system("cls");
                }
            }
    }while(op != 0);
}

//PUNTO 1
int cargarArregloAlumnos(stAlumno alumnos[], int dim)
{
    int i;
    char op = 's';
    for(i=0; i < dim && op == 's'; i++)
    {
        alumnos[i] = crearAlumno();
        printf("Desea continuar? (s/n): ");
        scanf(" %c", &op);
    }
    return i;
}

stAlumno crearAlumno()
{
        stAlumno alumnoAux;
        printf("Ingrese la matricula del alumno: ");
        scanf("%i", &alumnoAux.matricula);
        printf("Ingrese el nombre del alumno: ");
        scanf(" %s", alumnoAux.nombre);
        printf("Ingrese el genero del alumno (m/f/o): ");
        scanf(" %c", &alumnoAux.genero);
        return alumnoAux;
}

//PUNTO 2
void mostrarArregloAlumnos(stAlumno alumnos[], int dim)
{
    for(int i=0; i < dim; i++)
    {
        mostrarAlumno(alumnos[i]);
    }
}

void mostrarAlumno(stAlumno alumno)
{
    printf("\n%i", alumno.matricula);
    printf(" %s", alumno.nombre);
    printf(" %c\n\n", alumno.genero);
}

//PUNTO 3
int buscarArregloAlumnos(stAlumno alumnos[], int validos, int matricula)
{
    int i, pos = -1;
    for(i=0; i < validos; i++)
    {
        if(alumnos[i].matricula == matricula)
        {
            pos = i;
        }
    }
    return pos;
}

//PUNTO 4
void ordenarPorSeleccion(stAlumno alumnos[], int validos)
{
    int posMenor, i=0;
    stAlumno aux;
    while(i < validos-1)
    {
        posMenor = posicionMenor(alumnos, i, validos);
        aux = alumnos[posMenor];
        alumnos[posMenor] = alumnos[i];
        alumnos[i] = aux;
        i++;
    }
}

int posicionMenor(stAlumno alumnos[], int posInicial, int validos)
{
    stAlumno menor = alumnos[posInicial];
    int posMenor = posInicial;
    int i = posInicial+1;
    while(i < validos)
    {
        if(menor.matricula > alumnos[i].matricula)
        {
            menor = alumnos[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

//PUNTO 5
void mostrarAlumnosGenero(stAlumno alumnos[], int validos, char genero)
{
    for(int i=0; i < validos; i++)
    {
        if(alumnos[i].genero == genero)
        {
            mostrarAlumno(alumnos[i]);
        }
    }
}

//PUNTO 6
int insertarAlumnoEnArreglo(stAlumno alumnos[], int validos, stAlumno alumno)
{
    int i = validos;
    stAlumno aux;
    while(i >= 0)
    {
        if(alumno.matricula < alumnos[i].matricula)
        {
            alumnos[i+1] = alumnos[i];
            aux = alumnos[i];
            alumnos[i] = alumno;
        }
        i--;
    }
    return validos+1;
}

//PUNTO 7
void ordenarPorInsercion(stAlumno alumnos[], int validos)
{
    int i=0;
    while(i < validos-1)
    {
        insertar(alumnos, i, alumnos[i+1]);
        i++;
    }
}

void insertar(stAlumno alumnos[], int posInicial, stAlumno alumno)
{
    int i = posInicial;
    while(i >= 0 && strcmp(alumno.nombre, alumnos[i].nombre)==-1)
    {
        alumnos[i+1] = alumnos[i];
        i--;
    }
    alumnos[i+1] = alumno;
}

//PUNTO 8
int contarAlumnosXGenero(stAlumno alumnos[], int validos, char genero)
{
    int cont = 0;
    for(int i = 0; i < validos; i++)
    {
        if(alumnos[i].genero == genero)
        {
            cont++;
        }
    }
    return cont;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMN 30

typedef struct{
    int codigo;
    char titulo[40];
    char autor[30];
    int paginas;
    float precio;
    int enEconomicos;
} Libro;

void menu();
//PUNTO 1
void nombreArchivo(char archivo[]);
Libro crearLibro();
void cargarArchivo(char archivo[]);
void mostrarArchivoInverso(char archivo[]);
void mostrarRegistro(FILE *archi, char archivo[]);
void mostrarLibro(Libro libro);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    char archivo[TMN];
    do
    {
        printf("INGRESE EL EJERCICIO QUE QUIERE PROBAR: \n");
        printf("_________________________________________\n");
        printf("|[1] Cargar y mostrar archivo           |\n");
        printf("|[2]|\n");
        printf("|[3]|\n");
        printf("|[0]            FINALIZAR PROGRAMA      |\n");
        printf("-----------------------------------------\n");
        scanf("%i", &op);
        switch(op)
        {
        case 0:
            {
                printf("~ ~ ~ FINALIZANDO EL PROGRAMA ~ ~ ~\n");
                system("pause");
                system("cls");
            }break;
        case 1:
            {
                nombreArchivo(archivo);
                cargarArchivo(archivo);
                mostrarArchivoInverso(archivo);
                system("pause");
                system("cls");
            }break;
        case 2:
            {

                system("pause");
                system("cls");
            }break;
        }
    }while(op != 0);
}

void nombreArchivo(char archivo[])
{
    printf("Inrgese el nombre del archivo a acceder: ");
    scanf(" %s", archivo);
    strcat(archivo, ".bin");
}

//PUNTO 1
Libro crearLibro()
{
    char nombre[TMN];
    char apellido[TMN];
    Libro registro;
    printf("\nIngrese el codigo del libro: ");
    scanf("%i", &registro.codigo);
    printf("Ingrese el titulo del libro: ");
    scanf(" %s", &registro.titulo);
    printf("Ingrese el nombre autor del libro: ");
    scanf(" %s", &nombre);
    printf("Ingrese el apellido del autor: ");
    scanf(" %s", &apellido);
    strcat(nombre, apellido);
    strcpy(registro.autor, nombre);
    printf("Ingrese la cantidad de paginas del libro: ");
    scanf("%i", &registro.paginas);
    printf("Ingrese el precio del libro: ");
    scanf("%f", &registro.precio);
    registro.enEconomicos = 0;
    return registro;
}

void mostrarLibro(Libro libro)
{
    printf("---------------\n");
    printf("Codigo:  %i\n", libro.codigo);
    printf("Titulo:  %s\n", libro.titulo);
    printf("Autor:  %s\n", libro.autor);
    printf("Paginas:  %i\n", libro.paginas);
    printf("Precio:  %.2f\n", libro.precio);
    if(libro.enEconomicos == 1)
    {
        printf("En economico:  SI\n");
    }
    else
    {
        printf("En economico:  NO\n");
    }
    printf("---------------\n");
}

void cargarArchivo(char archivo[])
{
    char op = 's';
    FILE *archi;
    Libro aux;
    archi = fopen(archivo, "ab");
    if(archi != NULL)
    {
        while(!feof(archi) && op != 'n')
        {
            if(!feof(archi))
            {
                aux = crearLibro();
                fwrite(&aux, sizeof(Libro), 1, archi);
                printf("\nDesea seguir cargando libros? (s/n): ");
                scanf(" %c", &op);
            }
        }
        fclose(archi);
    }

}

void mostrarRegistro(FILE *archi, char archivo[])
{
    Libro aux;
    if(fread(&aux, sizeof(Libro), 1, archi) > 0)
    {
        mostrarRegistro(archi, archivo);
        mostrarLibro(aux);
    }
}

void mostrarArchivoInverso(char archivo[])
{
    FILE *archi;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        mostrarRegistro(archi, archivo);
    }
    fclose(archi);
}

//PUNTO 2
float calcularPromedioPrecio()
{
    float aux;
    FILE *archi;
    archi = fopen(archivo, "rb");
    if(archi != NULL)
    {
        aux = sumarPrecioLibros(archi);
    }
    fclose(archi);
}

float sumarPrecioLibros(FILE *archi)
{
    float preciototal=0;
    return preciototal;
}

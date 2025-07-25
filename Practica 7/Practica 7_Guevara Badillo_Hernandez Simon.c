#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
    int boleta;
    char nombre[50];
    char apellidos[50];
    struct Alumno* siguiente;
    struct Alumno* anterior;
} Alumno;

Alumno* p = NULL;  // Puntero al primer nodo de la lista
Alumno* q = NULL;  // Puntero al último nodo de la lista

void datosAlumno() {
    printf("1. Ingresar Alumno\n--------------------------------\n");
    int boleta;
    char nombre[50];
    char apellidos[50];

    printf("Ingrese la boleta del alumno: ");
    scanf("%d", &boleta);

    printf("Ingrese el nombre del alumno: ");
    scanf("%s", nombre);

    printf("Ingrese los apellidos del alumno: ");
    scanf("%s", apellidos);

    insertarAlumno(boleta, nombre, apellidos);
}

void insertarAlumno(int boleta, char* nombre, char* apellidos) {
    Alumno* nuevoAlumno = (Alumno*)malloc(sizeof(Alumno));

    nuevoAlumno->boleta = boleta;
    strcpy(nuevoAlumno->nombre, nombre);
    strcpy(nuevoAlumno->apellidos, apellidos);

    nuevoAlumno->siguiente = NULL;
    nuevoAlumno->anterior = NULL;

    if (p == NULL) {
        // Si la lista está vacía, el nuevo alumno será el primer y último nodo
        p = nuevoAlumno;
        q = nuevoAlumno;
    } else {
        Alumno* actual = p;
        Alumno* anterior = NULL;

        // Buscar la posición correcta en la lista ordenada por apellidos
        while (actual != NULL && strcmp(apellidos, actual->apellidos) > 0) {
            anterior = actual;
            actual = actual->siguiente;
        }

        if (actual != NULL) {
            if (anterior != NULL) {
                // Insertar el nuevo alumno en el medio de la lista
                anterior->siguiente = nuevoAlumno;
                nuevoAlumno->anterior = anterior;
                nuevoAlumno->siguiente = actual;
                actual->anterior = nuevoAlumno;
            } else {
                // Insertar el nuevo alumno al inicio de la lista
                nuevoAlumno->siguiente = p;
                p->anterior = nuevoAlumno;
                p = nuevoAlumno;
            }
        } else {
            // Insertar el nuevo alumno al final de la lista
            anterior->siguiente = nuevoAlumno;
            nuevoAlumno->anterior = anterior;
            q = nuevoAlumno;
        }
    }

    printf("\nAlumno registrado exitosamente :D\n");
    system("pause");
    system("cls");
    menu();
}

void mostrarAscendente() {
    printf("2. Mostrar Lista\n--------------------------------\n");
    printf(">> Listado Ascendente\n\n");
    Alumno* actual = p;

    if (actual == NULL) {
        printf("No hay alumnos registrados.\n");
        return;
    }

    printf("Listado de alumnos en forma ascendente:\n");
    while (actual != NULL) {
        printf("Boleta: %d\nNombre: %s\nApellidos: %s\n\n", actual->boleta, actual->nombre, actual->apellidos);
        actual = actual->siguiente;
    }

    system("pause");
    system("cls");
    menu();
}

void mostrarDescendente() {
    printf("2. Mostrar Lista\n--------------------------------\n");
    printf(">> Listado Descendente\n\n");

    Alumno* actual = q;

    if (actual == NULL) {
        printf("No hay alumnos registrados.\n");
        return;
    }

    printf("Listado de alumnos en forma descendente:\n");
    while (actual != NULL) {
        printf("Boleta: %d\nNombre: %s\nApellidos: %s\n\n", actual->boleta, actual->nombre, actual->apellidos);
        actual = actual->anterior;
    }

    system("pause");
    system("cls");
    menu();
}

void modificarAlumno() {
    printf("3. Modificar Alumno\n--------------------------------\n");

    Alumno* actual = p;
    int boleta;

    printf("Ingrese la boleta del alumno a modificar: ");
    scanf("%d", &boleta);

    while (actual != NULL && actual->boleta != boleta) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("No se encontró el alumno con la boleta especificada.\n");
    } else {
        char nuevoNombre[50];
        char nuevosApellidos[50];
        int boleta = actual->boleta;

        printf("Ingrese el nuevo nombre del alumno: ");
        scanf("%s", nuevoNombre);
        printf("Ingrese los nuevos apellidos del alumno: ");
        scanf("%s", nuevosApellidos);

        if (actual->anterior == NULL) {
            // El alumno a modificar es el primer nodo de la lista
            p = actual->siguiente;
            free(actual);
        } else if (actual->siguiente == NULL) {
            // El alumno a modificar es el último nodo de la lista
            q = actual->anterior;
            free(actual);
        } else {
            // El alumno a modificar está en medio de la lista
            Alumno* anterior = actual->anterior;
            Alumno* siguiente = actual->siguiente;

            anterior->siguiente = siguiente;
            siguiente->anterior = anterior;
            free(actual);
        }

        insertarAlumno(boleta, nuevoNombre, nuevosApellidos);

        printf("Alumno modificado correctamente :D.\n");
    }

    system("pause");
    system("cls");
    menu();
}

void menu() {
    int opcion;

    printf("----- Menu -----\n");
    printf("1. Altas de alumnos\n");
    printf("2. Mostrar alumnos dados de alta\n");
    printf("3. Modificaciones de alumnos\n");
    printf("0. Salir\n");
    printf("Ingrese su opcion: ");

    do {
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("pause");
                system("cls");
                datosAlumno();
                break;

            case 2:
                system("pause");
                system("cls");
                printf("2. Mostrar Listado\n--------------------------------\n");
                printf("1. Listado de alumnos en forma ascendente\n");
                printf("2. Listado de alumnos en forma descendente\n");

                printf("Ingrese su opcion: ");
                scanf("%d", &opcion);
                system("pause");
                system("cls");

                switch (opcion) {
                    case 1:
                        mostrarAscendente();
                        break;
                    case 2:
                        mostrarDescendente();
                        break;
                    default:
                        printf("Opción inválida.\n");
                }
                break;

            case 3:
                system("pause");
                system("cls");
                modificarAlumno();
                break;

            case 0:
                printf("Saliendo del programa...\n");
                exit(0);
                break;
            default:
                printf("Opción inválida.\n");
        }

        printf("\n");
    } while (opcion != 0);
}

int main() {
    printf("Practica 7: LISTAS DOBLEMENTE ENLAZADAS.\n\n");
    menu();
    return 0;
}

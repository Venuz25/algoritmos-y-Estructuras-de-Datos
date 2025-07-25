#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[50];
    char fecha[20];
    char rfc[20];
}Persona;

int cantidad = 0;

int main() {
    Persona lista[100];
    int opcion;

    do{

        printf("\n << >> Menu de Opciones << >> \n");
        printf("1) Agregar persona\n");
        printf("2) Buscar persona mediante RFC\n");
        printf("3) Eliminar persona mediante posicion\n");
        printf("4) Mostrar personas\n");
        printf("5) Salir del programa\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        system("cls");

        switch(opcion) {
            case 1:
                printf("\n1) Agregar persona\n\n");
                insertar(lista, &cantidad);
                break;
            case 2:
                printf("\n2) Buscar persona mediante RFC\n\n");
                buscar(lista);
                break;
            case 3:
                printf("\n3) Eliminar persona mediante posicion\n\n");
                borrar(lista);
                break;
            case 4:
                printf("\n4) Mostrar personas\n\n");
                mostrar(lista);
                break;

            case 5:
                printf("\n\nGracias por usar nuestro programa!!\n\n");
                exit(1);
                break;

            default: printf("\nOpcion no valida, elija de nuevo!!\n");
                     system("pause");
                     system("cls");
        }
    }while (opcion > 0 || opcion < 6);
    return 0;
}

void insertar(Persona lista[]) {
    Persona p;

    int pos;
    printf("Que posicion deseas agregar: ");
    scanf("%d", &pos);

    fflush(stdin);
    printf("Ingrese el nombre de la persona: ");
    gets(p.nombre);
    printf("Ingrese la fecha de nacimiento de la persona: ");
    scanf("%s", p.fecha);
    printf("Ingrese el RFC de la persona: ");
    scanf("%s", p.rfc);

    cantidad++;
    for (int i = cantidad - 1  ; i >= pos - 1; i--) {
        lista[i] = lista[i-1];
    }
    lista[pos-1] = p;

    printf("\nLa persona ha sido agregada a la lista.\n");
    system("pause");
    system("cls");
}

int buscar(Persona lista[]) {
    char com[20];
    printf("Ingrese el RFC de la persona: ");
    scanf("%s", com);

    if(cantidad == 0)printf("\nBase de datos vacia\n\n");

    else{
        for (int i = 0; i < cantidad; i++) {
            if (strcmp(lista[i].rfc, com) == 0) printf("\n%d)Nombre:%s\n  Fecha de Nacimiento:%s\n  RFC:%s\t\n", i + 1, lista[i].nombre, lista[i].fecha, lista[i].rfc);
        }
    }

    system("pause");
    system("cls");
}

void mostrar(Persona lista[]) {
    if (cantidad == 0) printf("No hay personas en la lista.\n");

    else {
        printf("Lista de personas:\n");
        for (int i = 0; i < cantidad; i++) {
            printf("%d)Nombre:%s\n  Fecha de Nacimiento:%s\n  RFC:%s\t\n\n", i + 1, lista[i].nombre, lista[i].fecha, lista[i].rfc);
        }
        printf("Cantidad de elementos:%d\n", cantidad);
     }


    system("pause");
    system("cls");
}

int borrar(Persona lista[]) {
    int pos;
    printf("Que posicion deseas eliminar: ");
    scanf("%d", &pos);

    for (int i = pos - 1 ; i < cantidad; i++) {
        lista[i] = lista[i+1];
    }
    cantidad--;

    printf("\n\nLos datos han sido eliminados exitosamente!!!! :)\n");
    system("pause");
    system("cls");
}

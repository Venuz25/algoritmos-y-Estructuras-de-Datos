#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct NodoArbol {
    int valor;
    struct NodoArbol* izquierdo;
    struct NodoArbol* derecho;
} NodoArbol;

NodoArbol* crearNodo(int valor) {
    // Crea un nuevo nodo con el valor dado y devuelve su puntero
    NodoArbol* nuevoNodo = (NodoArbol*)malloc(sizeof(NodoArbol));
    nuevoNodo->valor = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

NodoArbol* insertarNodo(NodoArbol* raiz, int valor) {
    // Inserta un nuevo nodo con el valor dado en el árbol y devuelve la raíz actualizada
    if (raiz == NULL) {
        return crearNodo(valor);
    }
    if (valor < raiz->valor) {
        raiz->izquierdo = insertarNodo(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = insertarNodo(raiz->derecho, valor);
    }
    return raiz;
}

bool buscarNodo(NodoArbol* raiz, int valor) {
    // Busca un valor dado en el árbol binario
    if (raiz == NULL) {
        printf("No se encontro el valor en el arbol.\n");
        return false;
    }
    else if (raiz->valor == valor) {
        printf("Se encontro el valor en el arbol.\n");
        return true;
    }
    else if (valor < raiz->valor) {
        buscarNodo(raiz->izquierdo, valor);
    }
    else {
        buscarNodo(raiz->derecho, valor);
    }
}

NodoArbol* encontrarNodoMinimo(NodoArbol* nodo) {
    // Encuentra el nodo con el valor mínimo en el subárbol dado
    NodoArbol* actual = nodo;
    while (actual->izquierdo != NULL) {
        actual = actual->izquierdo;
    }
    return actual;
}

NodoArbol* eliminarNodo(NodoArbol* raiz, int valor) {
    // Elimina un nodo con el valor dado del árbol y devuelve la raíz actualizada
    if (raiz == NULL) {
        return raiz;
    }
    if (valor < raiz->valor) {
        raiz->izquierdo = eliminarNodo(raiz->izquierdo, valor);
    } else if (valor > raiz->valor) {
        raiz->derecho = eliminarNodo(raiz->derecho, valor);
    } else {
        if (raiz->izquierdo == NULL) {
            NodoArbol* temp = raiz->derecho;
            free(raiz);
            return temp;
        } else if (raiz->derecho == NULL) {
            NodoArbol* temp = raiz->izquierdo;
            free(raiz);
            return temp;
        }
        NodoArbol* temp = encontrarNodoMinimo(raiz->derecho);
        raiz->valor = temp->valor;
        raiz->derecho = eliminarNodo(raiz->derecho, temp->valor);
    }
    return raiz;
}

void recorridoPreOrden(NodoArbol* raiz) {
    // Realiza el recorrido en preorden (raíz-izquierdo-derecho) del árbol y muestra los valores
    if (raiz == NULL) {
        return;
    }

    printf("%d ", raiz->valor);
    recorridoPreOrden(raiz->izquierdo);
    recorridoPreOrden(raiz->derecho);
}

void recorridoInOrden(NodoArbol* raiz) {
    // Realiza el recorrido inorden (izquierdo-raíz-derecho) del árbol y muestra los valores
    if (raiz == NULL) {
        return;
    }

    recorridoInOrden(raiz->izquierdo);
    printf("%d ", raiz->valor);
    recorridoInOrden(raiz->derecho);
}

void recorridoPostOrden(NodoArbol* raiz) {
    // Realiza el recorrido postorden (izquierdo-derecho-raíz) del árbol y muestra los valores
    if (raiz == NULL) {
        return;
    }

    recorridoPostOrden(raiz->izquierdo);
    recorridoPostOrden(raiz->derecho);
    printf("%d ", raiz->valor);
}

void imprimirArbolRecursivo(NodoArbol* raiz, int nivel) {
    // Imprime el árbol de forma recursiva, mostrando los valores indentados según su nivel
    if (raiz == NULL) {
        return;
    }

    imprimirArbolRecursivo(raiz->derecho, nivel + 1);

    for (int i = 0; i < nivel; i++) {
        printf("\t");
    }
    printf("%d\n", raiz->valor);

    imprimirArbolRecursivo(raiz->izquierdo, nivel + 1);
}

void imprimirArbol(NodoArbol* raiz) {
    // Imprime el árbol completo, llamando a la función de impresión recursiva
    imprimirArbolRecursivo(raiz, 0);
}

void liberarArbol(NodoArbol* raiz) {
    // Libera la memoria ocupada por el árbol de forma recursiva
    if (raiz == NULL) {
        return;
    }
    liberarArbol(raiz->izquierdo);
    liberarArbol(raiz->derecho);
    free(raiz);
}

void menu(NodoArbol** raiz) {
    int op, valor;

    do {
        printf("----- Menu -----\n");
        printf("\n 1. Insertar valor");
        printf("\n 2. Buscar valor");
        printf("\n 3. Eliminar valor");
        printf("\n 4. Recorrido en PreOrden");
        printf("\n 5. Recorrido en InOrden");
        printf("\n 6. Recorrido en PostOrden");
        printf("\n 7. Imprimir Arbol");
        printf("\n 8. Salir");

        printf("\n\n --> Selecciones una opcion: ");
        scanf("%d", &op);
        system("pause");
        system("cls");

        switch (op) {
            case 1:
                printf("1. INSERTAR VALOR\n");
                printf("__________________________________________\n\n");

                printf("Ingrese un valor a insertar: ");
                scanf("%d", &valor);

                *raiz = insertarNodo(*raiz, valor);
                printf("Valor insertado con exito :D!!!\n\n");

                system("pause");
                system("cls");
                break;

            case 2:
                printf("2. BUSCAR VALOR\n");
                printf("__________________________________________\n\n");

                printf("Que valor desea buscar? ");
                scanf("%d", &valor);

                buscarNodo(*raiz, valor);
                system("pause");
                system("cls");
                break;

            case 3:
                printf("3. ELIMINAR VALOR\n");
                printf("__________________________________________\n\n");

                printf("Que valor desea eliminar? ");
                scanf("%d", &valor);

                if (buscarNodo(*raiz, valor)){
                    *raiz = eliminarNodo(*raiz, valor);
                    printf("Valor eliminado con exito :D!!!\n\n");
                }

                system("pause");
                system("cls");
                break;

            case 4:
                printf("4. RECORRIDO EN PREORDEN\n");
                printf("__________________________________________\n\n");

                recorridoPreOrden(*raiz);
                printf("\n\n");
                system("pause");
                system("cls");
                break;

            case 5:
                printf("5. RECORRIDO EN INORDEN\n");
                printf("__________________________________________\n\n");

                recorridoInOrden(*raiz);
                printf("\n\n");
                system("pause");
                system("cls");
                break;

            case 6:
                printf("6. RECORRIDO EN POSTORDEN\n");
                printf("__________________________________________\n\n");

                recorridoPostOrden(*raiz);
                printf("\n\n");
                system("pause");
                system("cls");
                break;

            case 7:
                printf("7. IMPRIMIR ARBOL\n");
                printf("__________________________________________\n\n");

                imprimirArbol(*raiz);
                printf("\n\n");
                system("pause");
                system("cls");
                break;

            case 8:
                printf("\n Saliendo del programa...\n");
                liberarArbol(*raiz);
                break;

            default:
                printf("\nOpcion no valida D: \n");
                system("pause");
                system("cls");
                break;
        }
    } while (op != 8);
}

void main() {
    printf("Practica 8: ARBOLES BINARIOS.\n\n");

    NodoArbol* raiz = NULL;
    menu(&raiz);
}

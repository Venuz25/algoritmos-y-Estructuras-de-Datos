#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Estructura de los nodos de la pila
struct Nodo {
    float valor;
    struct Nodo* sig;
};

// Función que inserta un valor en la pila
void insertar(struct Nodo** pila, float valor) {
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));

    nuevo->valor = valor;
    nuevo->sig = *pila;
    *pila = nuevo;
}

// Función que realiza la operación correspondiente y actualiza la pila
void operacion(struct Nodo** pila, char op) {
    float num2 = (*pila)->valor; // toma el primer valor de la pila
    *pila = (*pila)->sig; //borra el valor tomado de la pila

    float num1 = (*pila)->valor;// toma el, ahora, primer valor de la pila
    *pila = (*pila)->sig;//borra el valor tomado de la pila

    float resultado;

    switch (op) {//evalua la operacion que se va a realizar
        case '+':
            resultado = num1 + num2;
            break;

        case '-':
            resultado = num1 - num2;
            break;

        case '*':
            resultado = num1 * num2;
            break;

        case '/':
            resultado = num1 / num2;
            break;
    }
    insertar(pila, resultado);//envia el  resultado a la pila
}

// Función que resuelve la operación
void resolver(char* notacion) {
    struct Nodo* pila = NULL;
    char* subchar = strtok(notacion, " ");//divide la cadena principal en subcadenas delimitadas por los espacios

    while (subchar != NULL) {
        if (isdigit(subchar[0])) {//esta funcion evalua si el subcadena es un digito decimal
            float num = atof(subchar);//si es cierto convierte la subcadena en decimal
            insertar(&pila, num);// lo inserta en la pila
        }
        else if (subchar[0] == '+' || subchar[0] == '-' || subchar[0] == '*' || subchar[0] == '/') {
            if (pila == NULL || pila->sig == NULL) {//si la pila tiene menos de dos elementos de error
                printf("Error en la notacion!!\n");
                return;
            }
            operacion(&pila, subchar[0]);//si no --> envia la pila y el operador a hacer la operacion
        }
        else {
            printf("Error en la notacion!!\n");//si no se ingresa ni un numero ni un operador marca error
            return;
        }
        subchar = strtok(NULL, " ");//toma la siguiente subcadena
    }
    if (pila == NULL || pila->sig != NULL) {//si al final no quedan elementos o queda mas de un elemento en la pila marca error
        printf("Error en la notacion!!\n");
        return;
    }
    printf("Resultado: %.2f\n", pila->valor);//imprime el resultado
}

// Función principal
void main() {
    char notacion[20];
    printf("Practica 5: PILAS\n");

    printf("Ingrese la operacion en notacion postfija: ");
    fgets(notacion, 20, stdin);
    notacion[strcspn(notacion, "\n")] = 0; // Elimina el caracter de salto de línea

    resolver(notacion);
}

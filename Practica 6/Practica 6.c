#include <stdio.h> //libreria estandar para entrada y salida de datos.
#include <stdlib.h> //da funciones relacionadas con operaciones de utilidad y manejo de memoria.
#include <ctype.h> //da funciones para realizar operaciones y comprobaciones relacionadas con los caracteres.
#include <string.h> //da funciones para manipular cadenas de caracteres.

typedef struct Nodo {
    char valor;
    struct Nodo* sig;
} Nodo; //se define la estructura Nodo, tiene el campo dato para que se guarde el valor del nodo y el
        //puntero siguiente que, como se vió en clases, apunta al siguiente nodo en dicha estructura.

typedef struct Pila {
    Nodo* superior;
} Pila; //estructura pila con un campo llamado superior, que apunta al nodo SUPERIOR de la pila

typedef struct Cola {
    Nodo* delante;
    Nodo* final;
} Cola; //estructura cola y tiene dos campos: delante y final que tiene un puntero
        //que apunta al nodo que esta adelante y al que está al final de la cola.

void inPila(Pila* pila);
void pushPila(Pila* pila, char dato);
char popPila(Pila* pila);
void inCola(Cola* cola);
void encolar(Cola* cola, char dato);
char desencolar(Cola* cola);
int VerificarPalindromo(char* frase);

int main() {
    char frase[100];
    int r;

    printf("PRACTICA 6: COLAS\n\n");
    printf("Ingrese una frase: "); //pide la frase
    fgets(frase, sizeof(frase), stdin); //se lee la frase
    frase[strcspn(frase, "\n")] = '\0';  // Elimina el salto de línea que se encuentra al final de la frase


    if (VerificarPalindromo(frase)) {
        printf("La frase que usted a ingresado es un palindromo.\n");
    } else {
        printf("La frase que usted a ingresado no es un palindromo.\n");
    }

    return 0;
}

Nodo* crearNodo(char valor) { //se recibe el valor 'valor'.
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); //crea espacio en memoria
    nuevoNodo->valor = valor; //el valor del nodo será valor.
    nuevoNodo->sig = NULL; // puntero siguiente se inicializa con NULL
    return nuevoNodo; //se retorna el nuevo nodo que se ha creado
}

void inPila(Pila* pila) {
    pila->superior = NULL;
} /*lo que hace esta funcion es que recibirá un puntero a la pila
y el campo llamado superior se dirá que está vacia, esto da a entender
que la pila está vacia*/

void pushPila(Pila* pila, char dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    nuevoNodo->sig = pila->superior;
    pila->superior = nuevoNodo;
} /* se recibe un puntero a la pila y el valor llamado dato, se crea
un nuevo nodo con el valor que se le dio. En la linea 37
siguiente se establecerá como el nodo superior actual y solo
se actualiza superior para que apunte al nuevo nodo que se acaba de crear. */


char popPila(Pila* pila) { //la funcion extrae el valor del nodo superior
    if (pila->superior == NULL) { //si superior es null
        return '\0'; //significa que a pila está vacía y retorna el caracter nulo.
    }

   else{
        Nodo* nodoEliminado = pila->superior; //el nodo que está arriba, se guarda en nodoeliminado
        char valor = nodoEliminado->valor; //el 'dato' se guarda en una variable dato
        pila->superior = nodoEliminado->sig; //aqui se actualiza superior para que apunte al siguiente nodo
        free(nodoEliminado); //se libera la memoria del nodoeliminado
        return valor; //se retorna el el dato extraido.
   }
}

void inCola(Cola* cola) {
    cola->delante = NULL;
    cola->final = NULL;
} //se indica que la cola está vacia

void encolar(Cola* cola, char dato) {
    Nodo* nuevoNodo = crearNodo(dato); //se crea un nuevo nodo con el valor que se le mandó.
    if (cola->final == NULL) { //si está vacia
        cola->delante = nuevoNodo;
        cola->final = nuevoNodo; //se establecerá el valor de adelante y el de atras con el nodo quie se creó.
    } else { //sino está vacia
        cola->final->sig = nuevoNodo; //se enlaza el final al nuevo nodo
        cola->final = nuevoNodo; //se actualiza final para que se apunte al nuevo nodo.
    }
}

char desencolar(Cola* cola) { //extrae el valor del nodo que está adelante
    if (cola->delante == NULL) {
        return '\0';  // La cola está vacía y retorna el valor nulo.
    }
    Nodo* nodoEliminado = cola->delante; //el valor de adelante se guarda en el nodo eliminado.
    char valor = nodoEliminado->valor; //el dato se guarda en una variable dato
    cola->delante = nodoEliminado->sig; //se apunta al siguiente nodo
    if (cola->delante == NULL) { //si el valor de enfrente está vacio
        cola->final = NULL;  //el final se actualiza como null
    }
    free(nodoEliminado); //se libera la memoria ocupada
    return valor; //se retorna el valor del dato que se extrajo.
}

int VerificarPalindromo(char* frase) { //se recibe un puntero a una cadena de caracteres que es la frase que se ingresó.
    int longitud = strlen(frase); //se calcula la longitud de la frase.
    Pila pila;
    Cola cola;
    inPila(&pila); //se crea la pila
    inCola(&cola); //se crea la cola

    /*en este for se recorre a la cadena y cada caracter se convierte a minuscula con la funcion tolower
     que se encuentra en la libreria ctype.h y se comprueba si está de la a a la z.
    si se cumple se agrega a pushpila y encolar. */

    for (int i = 0; i < longitud; i++) {
        char caracter = tolower(frase[i]);
        if (caracter >= 'a' && caracter <= 'z') {
            pushPila(&pila, caracter);
            encolar(&cola, caracter);
        }
    }

    // AQUI SE COMPRUEBA SI ES O NO PALINDROMO
    /*  */
    while (pila.superior != NULL && cola.delante != NULL) {
    //MIENTRAS NO SEA NULO
        char caracterPila = popPila(&pila); //se sacan los caracteres de poppila y desencolar
        char caracterCola = desencolar(&cola);
        if (caracterPila != caracterCola) { //si son diferentes se retorna 0
            return 0;  // significa que no es palíndromo
        }
    }

    return 1;  // sino es palíndromo
}

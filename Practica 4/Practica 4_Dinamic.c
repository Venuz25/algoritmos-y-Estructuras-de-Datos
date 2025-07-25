#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo* sig;
}nodo;

void insertar(nodo **, int);//inserta nuevos elementos
void imprimir(nodo **, int);//imprime la lista
int cantidad(nodo **);//devuelve la cantidad de elementos de la lista
int pares(nodo **);//devuelve la cantidad de elementos pares de la lista
int buscar(nodo **, nodo **);//imprime si esta en la lista uno
int coin(nodo **, int);//compara los elementos de la lista 1 con la lista 2

void main(){
    printf("Practica 4:\n");
    printf("Parte 2: Listas dinamicas.\n\n");

    int x;
    nodo* p1 = NULL;//inicializa lista 1
    nodo* p2 = NULL;//inicializa lista 2

    printf(">Ingresa los valores para Lista 1:\n");
    printf("  *0: final de la lista\n");
    do{
        scanf("%d",&x);
        insertar(&p1, x);
    }while(x!=0);//registra valores hasta que el usuario teclee 0

    printf("\n>Ingresa los valores para Lista 2:\n");
    printf("  *0: final de la lista\n");
    do{
        scanf("%d",&x);
        insertar(&p2,x);
    }while(x!=0);//registra valores hasta que el usuario teclee 0

    printf("\n");
    system("pause");
    system("cls");

    printf("\n DATOS DE LAS LISTAS:\n");

    imprimir(&p1, 1);//imprime la lista 1
    printf("Cantidad de elementos: %d\n",cantidad(&p1));
    printf("Cantidad de elementos pares: %d\n",pares(&p1));

    imprimir(&p2, 2);//imprime la lista 2
    printf("Cantidad de elementos: %d\n",cantidad(&p2));
    printf("Cantidad de elementos pares: %d\n",pares(&p2));

    buscar(&p1, &p2);//llama a buscar

}

void insertar(nodo** p,int x){
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->valor = x;//iguala el valor del nuevo dato al dato ingresado
    nuevo->sig = NULL;//al ser el ultimo elemento se inicializa a nulo

    if (*p == NULL)*p = nuevo;// si la lista esta vacia se coloca en p
    else{// si no esta vacia recorremos la lista hasta llegar al ultimo nodo y lo colocamos ahi
        nodo* aux = *p;

        while( aux->sig != NULL ){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

int cantidad(nodo** p){
    struct nodo *reco = *p;
    int cant = 0;

    while (reco != NULL && reco->valor != 0){//recoremos todos los nodos hasta el final
        cant++;//contamos el numero de nodos
        reco = reco->sig;
    }
    return cant;//devuelve la cantidad
}

int pares(nodo** p){
    struct nodo *reco = *p;
    int par = 0;

    while (reco != NULL && reco->valor != 0){//recoremos todos los nodos hasta el final
        if(reco->valor%2 == 0)par++;//contamos el numero de valores que sean pares
        reco = reco->sig;
    }
    return par;//devuelve la cantidad de numeros pares
}

void imprimir(nodo** p, int n){
    struct nodo *reco = *p;

    printf("\nLista %d:\n",n);

    while (reco!=NULL && reco->valor != 0){//recorre la lista
        printf("%d\t",reco->valor);//imprime la seccion de valor del nodo
        reco = reco->sig;
    }
    printf("\n\n");
}

int buscar(nodo **p1, nodo **p2){
    struct nodo *datos = *p2;
    struct nodo *p = *p1;
    int x, e = 0;

    printf("\n\nDatos Coincidentes:\n");

    while (datos!=NULL && datos->valor != 0){
        x = datos->valor;//guarda el valor que se va a buscar en la lista 1
        e = coin(&p, x);//devuelve 1 si esta en la lista 1 y 0 si no esta

        if(e == 1)printf("%d\t-> SI esta en Lista 1\n", x);
        else printf("%d\t-> NO esta en Lista 1\n", x);

        datos = datos->sig;
    }
    printf("\n");
}

int coin(nodo** p, int x){
    struct nodo* aux = *p;
    int n = 0;

    while(aux != NULL){
        if(aux->valor == x) n = 1;//si encuentra el valor en la lista n vale 1
        aux = aux->sig;
    }
    return n;//devuelve si encontro o no el valor
}


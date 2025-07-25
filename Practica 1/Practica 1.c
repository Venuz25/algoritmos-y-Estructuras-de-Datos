#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

int entrada(void);//pide el no. de datos al usuario
void llenado(int* , int);//llena el arreglo
void insercion(int* , int);//ordena el arreglo

int main(){
    printf("Practica 1:\n");
    printf("Ordenamiento por Insercion\n\n");

    int n = entrada();//guarda el valor devuelto por la funcion entrada();
    int numeros[n];//declara el arreglo de tamanio n.

    printf("\nNumeros sin Ordenar\n");
    llenado(numeros, n);//llama la funcion llenado();

    printf("\n\nNumeros Ordenados\n");
    insercion(numeros, n);//llama la funcion insercion();

    printf("\n");

    return 0;
}

int entrada(){
    int n;

    do{
        printf("Dame el numero datos a ordenar?: ");//solicita el no. de datos a ordenar
        scanf("%d", &n);

        if(n > 50){//en caso de que n sea mayor a 50 lanza una alerta
            printf("\nEl numero de datos no debe de ser mayor a 50!!!!\n\n");
            system("pause");
            system("cls");
        }
    }while(n > 50);//se repite el proceso hasta que n cumpla las condiciones.

    return n;//no devuelve en numero de datos.
}

void llenado(int* numeros, int n){
    srand(time(NULL));//inicializa la funcion rand

    for(int i = 0; i < n; i++){
        numeros[i] = (rand()%98+1);//se lleva cada indice con un numero aleatorio
        printf("%d\t", numeros[i]);//imprime el indice que se acaba de llenar
    }
}

void insercion(int* numeros, int n){
    int i, j, aux;

    for(i = 1; i < n; i++){//indice principal
        j = i;//iguala el valor de j a i
        aux = numeros[i];//le da valor a la variable auxiliar

        while((j > 0) && (numeros[j-1] > aux)){//verificara si j es mayor a 0 y si el antecesor del numero
                                               //a comparar es mayor si esto es verdadero ejecuta el while
            numeros[j] = numeros[j-1];//pone al antecesor en el lugar del numero comparado
            j--;//decrementa uno a j
        }
        //cuando el while ya no se cumpla
        numeros[j] = aux;// coloca el numero comparado en el lugar que le corresponde
    }

    for(i = 0; i < n; i++)
        printf("%d\t", numeros[i]);//imprime el arreglo ordenado
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int entrada(void);//pide en numero de datos a ordenar
void llenado(int* , int);//llena el arreglo
void menu(int* , int);//muestra el menu de opciones
void insercion(int* , int);//ordena por insercion
void burbuja(int* , int);//ordena por burbuja
void seleccion(int* , int);//ordena por seleccion
void mezclaRec(int* , int, int);//hace las diviciones el arreglo
void mezcla(int*, int, int, int);//ordena el arreglo por partes
void imprimir(int*, int);//imprime el arreglo ordenado

int main(){
    int n, r = 1;

    do{
        printf("Practica 2:\n");
        printf("Ordenamiento por Insercion, Burbuja, Seleccion y Mezcla\n\n");

        n = entrada();//recibe el tamanio del arreglo
        int numeros[n];//declara el arreglo tamanio n

        menu(numeros, n);//llama el menu

        printf("\n\nDesea ordenar con otro metodo? (1/si , 0/no)\n");
        scanf("%d",&r);

        if (r == 1)
            system("cls");
    }while(r == 1);//permite que se repita el programa hasta que el ususario decida

    return 0;
}

int entrada(){
    int n;

    printf("Dame el numero datos a ordenar?: ");
    scanf("%d", &n);

    return n;//devuelve el numero de datos que el usuario quiere ordenar
}

void menu(int* numeros, int n){
    int op;

    do{
        printf("\n<>Menu Metodos de Ordenamiento<>");

        printf("\n1. Ordenamiento por Insercion");
        printf("\n2. Ordenamiento por Burbuja");
        printf("\n3. Ordenamiento por Seleccion");
        printf("\n4. Ordenamiento por Mezcla");

        printf("\n\nElije la opcion de ordenamiento:");
        scanf("%d", &op);//recibe la opcion que eligio el usuario

        switch(op){
            case 1: llenado(numeros, n);//llama a la funcion llenado
                    insercion(numeros,n);
                    printf("\n\nNumeros Ordenados por Insercion\n");
                    imprimir(numeros, n);//imprime los numero ordenado
                    break;

            case 2: llenado(numeros, n);//llama a la funcion llenado
                    burbuja(numeros,n);
                    printf("\n\nNumeros Ordenados por Burbuja\n");
                    imprimir(numeros, n);//imprime los numero ordenado
                    break;

            case 3: llenado(numeros, n);//llama a la funcion llenado
                    seleccion(numeros,n);
                    printf("\n\nNumeros Ordenados por Seleccion\n");
                    imprimir(numeros, n);//imprime los numero ordenado
                    break;

            case 4: llenado(numeros, n);//llama a la funcion llenado
                    mezclaRec(numeros,0,n-1);
                    printf("\n\nNumeros Ordenados por Mezcla\n");
                    imprimir(numeros, n);//imprime los numero ordenado
                    break;

            default: printf("Opcion no valida, elija de nuevo!!\n");
                     system("pause");
                     system("cls");
        }
    }while(op < 1 || op > 4);//se repite el menu en caso de que no elija una opcion disponible
}

void llenado(int* numeros, int n){
    int i;
    srand(time(NULL));//inicializa la funcion rand

    for(i = 0; i < n; i++){
        numeros[i] = (rand()%98+1);//se lleva cada indice con un numero aleatorio
    }
    printf("\nNumeros sin Ordenar\n");
    imprimir(numeros, n);//imprime el arreglo sin ordenar
}

void insercion(int* numeros, int n){
    int i, j, aux;

    for(i = 1; i < n; i++){//indice principal
        j = i;//iguala el valor de j a i
        aux = numeros[i];//le da valor a la variable auxiliar

        while((j > 0) && (numeros[j-1] > aux)){//verificara si j es mayor a 0
                                               //y si el antecesor del numero a comparar es mayor
            numeros[j] = numeros[j-1];//pone al antecesor en el lugar del numero comparado
            j--;//decrementa uno a j
        }
        //cuando el while ya no se cumpla
        numeros[j] = aux;// coloca el numero comparado en el lugar que le corresponde
    }
}

void burbuja(int* numeros, int n){
    int i, j, aux;

    for(i = 0; i < n; i++){
        for(j=1; j < n; j++){
        	if(numeros[j-1] > numeros[j]){//si el antecesor del numero es mayor
        		aux = numeros[j];//guarda el numero menor en auxiliar
        		numeros[j] = numeros[j-1];//guarda el numero mas grande en su lugar
        		numeros[j-1] = aux;//guarda el menor en su lugar
			}
		}
    }
}

void seleccion(int* numeros, int n){
    int i, j, aux, min;

    for(i = 0; i < n - 1; i++){
        min = i;//declara que el numero es el menor
        for(j = i + 1; j < n; j++){//busca si hay un numero mas pequenio que min
            if(numeros[j] < numeros[min]){
                min = j;//si encuentra un numero mas pequenio guarda la ubicacion de ese numero
            }
        }
            aux = numeros[i];//guarda el numero de la posicion i en un auxiliar
            numeros[i] = numeros[min];//pone el numero menor en la posicion i
            numeros[min] = aux;//pone el numero de i en el lugar del menor
    }
}

void mezclaRec(int* numeros, int inicio, int fin){
    int i;

    if(inicio < fin){//si el indice del inicio es menor que el indice del final
            int mitad = inicio + (fin - inicio)/2;//declara la mitad del arreglo
            mezclaRec(numeros, inicio, mitad);//llama recursivamente mandando inicio y mitad
            mezclaRec(numeros,mitad + 1, fin);//llama recursivamente mandando mitad y fin
            mezcla(numeros,inicio,mitad, fin);//llama mezcla la cual hara la funcion de ordenar los numeros
    }
}

void mezcla(int* numeros, int inicio, int mitad, int fin){
    int i,j,k;

    int n1 = mitad - inicio + 1;//declara el tamanio del primer arreglo
    int n2 = fin - mitad;//declara el tamanio del segundo arreglo

    int L[n1];//declara el primer arreglo tamanio n1
    int R[n2];//declara el segundo arreglo tamanio n2

    for(i = 0; i < n1; i++)
        L[i] = numeros[inicio + i];
        //llena el primer arreglo con la primera mitad del arreglo original

    for(j = 0; j < n2; j++)
        R[j] = numeros[mitad + j + 1];
        //llena el segundo arreglo con la segund mitad del arreglo original

    i = 0;//reinicia i
    j = 0;//reinicia j
    k = inicio;//declara k con el valor del inicio

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){//si el numero en R es menor que el de L
            numeros[k] = L[i];//coloca el numero de L en el indice k del arreglo original
            i++;//aumenta i + 1
        }
        else {// si el numero de L es menor que el de R
            numeros[k] = R[j];//coloca el numero de R en el indice k del arreglo original
            j++;//aunmenta j + 1
        }
        k++;//aumenta k + 1
    }

    while(i < n1){//mientras i sea menor al tamanio del primer arreglo
        numeros[k] = L[i];//pone el numero en L de i en el indice k del arreglo original
        i++;//aumenta i + 1
        k++;//aumenta k + 1
    }

    while(j < n2){//mientras j sea menor al tamanio del segundo arreglo
        numeros[k] = R[j];//pone el numero en R de j en el indice k del arreglo original
        j++;//aumenta j + 1
        k++;//aumenta k + 1
    }
}

void imprimir(int* numeros, int n){
    int i;
    for(i = 0; i < n ; i++)
        printf("%d\t", numeros[i]);
}

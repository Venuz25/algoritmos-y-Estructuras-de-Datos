#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int n, w, nc;

int entrada();//pide los datos al usuario
void llenado(int obj[3][n]);//le asigna los valores y pesos a los objetos
void combinaciones (int comb[nc][n]);//hace la matriz de combinaciones
void resultados (int obj[3][n],int bin[nc][n]);//calcula los resultados
void mejorres (int*,int*,int bin[nc][n]);//busca el resultado mas optimo

void main(){
    printf("Practica 3:\n");
    printf("El Problema de la Mochila\n\n");

    entrada();

    nc = pow(2,n);//calcula el numero de combinaciones posibles
    int obj[3][n];//arreglo de datos
    int comb[nc][n];

    printf("\n");
    llenado(obj);
    combinaciones(comb);
    resultados(obj,comb);
}

int entrada(){
    printf("Cuantos objetos quiere meter en la mochila? ");
    scanf("%d", &n);//recibe el numero de objetos

    printf("Cual es el peso maximo que soporta la mochila? ");
    scanf("%d", &w);//peso maximo de la mochila
}

void llenado(int obj[3][n]){
    srand(time(NULL));

    //da el indice de los objetos
    printf("Obj.\t");
    for(int i = 0; i < n; i++){
        obj[0][i] = i+1;
        printf("%d\t",obj[0][i]);
    }

    //asigna un peso aleatorio a los objetos igual o menor al peso maximo.
    printf("\nPeso:\t");
    for(int j = 0; j < n; j++){
        obj[1][j] = (rand()%(w-1)+1);;
        printf("%d\t",obj[1][j]);
    }

    //asigna un valor a los objetos de 1 a 20
    printf("\nValor:\t");
    for(int k = 0; k < n; k++){
        obj[2][k] = (rand()%19+1);
        printf("%d\t",obj[2][k]);
    }
    printf("\n\n");
}

void combinaciones(int comb[nc][n]){
    int razon, fil, cont;
	int i = 0, div = 2;

	for(int j = 0; j < n; j++){//recorre las columnas de la matriz de forma descendiente
		i = 0;//indice inicial de cada bloque
		cont = 1;//indica cuando se debe de poner un uno o un cero
		razon = nc / div;//numero de filas de cada bloque
		do{
			for(fil = i ; fil < i + razon ; fil++ ){//recorre las filas
				if(cont%2!=0){//si el contador es impar se asigna 0 a la casilla
					comb[fil][j] = 0;
				}
				else{//si es par se asina 1
					comb[fil][j] = 1;
				}
			}
			cont++;
			i += razon;
		}while(i < nc);//mientras i sea menor al numero de filas
		div *= 2;
	}
}

void resultados(int obj[3][n],int comb[nc][n]){
    int pesot[nc];//en este vector se guardaran los pesos totales de las combinaciones
    int valort[nc];//en este vector se guardaran los valores totales de las combinaciones
    int f = 0, c = 0;
    int peso, valor;//variables para guardar los pesos parciales

    do{
        peso = 0;//inicializa el peso en 0
        pesot[c] = 0;//limpia el indice del arreglo en el que se va a guardar el peso
        do{
            peso = obj[1][f] * comb[c][f];//multiplica el peso del objeto por
                                          //la cantidad de veces que estara en la mochila
            pesot[c] = pesot[c] + peso;//va guardando la suma de los pesos
            f++;//aumenta una fila
        }while(f<n);
        f = 0;//reinicia el indice de la fila
        c++;//aumenta una columna
    }while(c<nc);

    c = 0;//reincia el indice de la columna
    f = 0;//reinicia el indice de la fila
    do{
        valor = 0;//inicializa el valor a 0
        valort[c] = 0;//limpia el indice del arreglo en el que se va a guardar el valor
        do{
            valor = obj[2][f] * comb[c][f];//multiplica el valor del objeto por
                                           //la cantidad de veces que estara en la mochila
            valort[c] = valort[c] + valor;//va guardando la suma de los valores
            f++;//aumenta una fila
        }while(f<n);
        f = 0;//reinicia el indice de la fila
        c++;//aumenta una columna
    }while(c<nc);

    //imprime la tabla de combinaciones y resultados
    printf("\nTabla de Resultados\n");

    //imprime los encabezados de las columnas de la tabla
    for(int i = 0; i < n; i++){
            printf("obj.%d\t",i+1);
    }
    printf("Peso T\tValor T\n");

    //imprime las combinaciones y los pesos y valores totales para cada combinacion
    for(int i = 0; i < nc; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t",comb[i][j]);
        }
        printf("%d\t",pesot[i]);
        printf("%d\n",valort[i]);
    }

    mejorres (pesot,valort,comb);

}

void mejorres (int* pesos,int* valores, int comb[nc][n]){
    int mi = 0;//supone que la mejor combinacion se encuentra en el indice 0

    for(int j = 1; j < nc; j++){
        if(valores[j] > valores[mi] && pesos[j]<=w)
            //si el valor de j es mayor que el de mi y el peso de j es menor o igual a w
            mi = j;//la mejor combinacion sera en j
    }

    //imprime la mejor combinacion
    printf("\n\nCombinacion Optima\n");
    if(pesos[mi]<= w){
        for(int i = 0; i < n; i++){
            printf("obj.%d\t",i+1);
        }
        printf("Peso T\tValor T\n");


        for(int j = 0; j < n; j++){
            printf("%d\t",comb[mi][j]);
        }
        printf("%d\t",pesos[mi]);
        printf("%d\n",valores[mi]);
    }
    else printf("NO HAY COMBINACION OPTIMA!!!\n Todas se  pasan del peso permitido :(");

}

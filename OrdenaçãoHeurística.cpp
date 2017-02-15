#include<iostream>
#include<fstream>
#include<stdio.h>
#include<windows.h>

using namespace std;

void mostraVetor(int vetor[], int n){
    int i;
    for(i=0; i<n; i++)
        printf("%d \n", vetor[i]);
}

void troca(int* a, int* b){
    int t = *a;
    *a = *b;
    *b= t;
}

int getMax(int vetor[], int n){ //Função que retorna o máximo valor do vetor.
    int mx = vetor[0];
    for(int i =1; i<n; i++)
        if(vetor[i] > mx)
            mx = vetor[i];
    return mx;
}

void countSort(int vetor[], int n, int exp){ //Função que conta o vetor de acordo com o dígito.
    int output[n];// vetor de saída
    int i, count[10] = {0};

    for(i=0; i<n; i++) //armazena quantidade de ocorrências no vetor.
        count[(vetor[i]/exp)%10]++;

    for(i=1; i<10; i++)//Trocar para atuais posições do dígito
        count[i] += count[i-1];

    for(i=n -1; i>=0; i--){ //Constrói o vetor de saída.
        output[count[(vetor[i]/exp)%10] -1] = vetor[i];
        count[(vetor[i]/exp)%10] --;
    }

    for(i=0; i<n; i++)//Copia o vetor de saída para o vetor original agora ordenado de acordo com o dígito.
        vetor[i] = output[i];
}

void radixsort(int vetor[], int n){
    int m = getMax(vetor, n); //Procura o maior valor para saber o número de dígitos

    for(int exp = 1; m/exp >0; exp *=10)//Contar para cada dígito.
        countSort(vetor, n , exp);
}

void insertionSort(int vetor[], int n){
    int i, chave, j;
    for(i=1; i<n; i++){
        chave = vetor[i];
        j = i-1;

        while(j>= 0 && vetor[j] > chave){
            vetor[j+1] = vetor[j];
            j = j-1;
        }
        vetor[j+1] = chave;
    }
}

int particao(int vetor[], int low, int high){
    int pivo = vetor[high];
    int i = (low - 1);

    for(int j=low; j<= high-1; j++){
        if(vetor[j]<=pivo){
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i+1], &vetor[high]);
    return(i+1);
}

void quickSort(int vetor[], int low, int high){
    if(low<high){
        int pi = particao(vetor, low, high);

        quickSort(vetor, low, pi-1);
        quickSort(vetor, pi+1, high);
    }
}


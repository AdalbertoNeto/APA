//www.geeksforgeeks.org
//Algoritmo de ordena��o em tempo linear
//An�lise e projeto de algoritmos 2016.2
//Adalberto 11228217
#include<iostream>
#include<fstream>
using namespace std;

int getMax(int vetor[], int n){ //Fun��o que retorna o m�ximo valor do vetor.
    int mx = vetor[0];
    for(int i =1; i<n; i++)
        if(vetor[i] > mx)
            mx = vetor[i];
    return mx;
}

void countSort(int vetor[], int n, int exp){ //Fun��o que conta o vetor de acordo com o d�gito.
    int output[n];// vetor de sa�da
    int i, count[10] = {0};

    for(i=0; i<n; i++) //armazena quantidade de ocorr�ncias no vetor.
        count[(vetor[i]/exp)%10]++;

    for(i=1; i<10; i++)//Trocar para atuais posi��es do d�gito
        count[i] += count[i-1];

    for(i=n -1; i>=0; i--){ //Constr�i o vetor de sa�da.
        output[count[(vetor[i]/exp)%10] -1] = vetor[i];
        count[(vetor[i]/exp)%10] --;
    }

    for(i=0; i<n; i++)//Copia o vetor de sa�da para o vetor original agora ordenado de acordo com o d�gito.
        vetor[i] = output[i];
}

void radixsort(int vetor[], int n){
    int m = getMax(vetor, n); //Procura o maior valor para saber o n�mero de d�gitos

    for(int exp = 1; m/exp >0; exp *=10)//Contar para cada d�gito.
        countSort(vetor, n , exp);
}

void mostraVetor(int vetor[], int n){//Fun��o para mostrar o vetor na tela.
    for(int i =0; i<n; i++)
        cout << vetor[i] << " "<<endl;
}

int main(){

    ifstream file("example.in");
    if(!file){/* Falhou em abrir o arquivo */}

    int tamanho;
    if(!(file >> tamanho)){/*Falhou em ler o primeiro valor */}

    int* vetor = new int[tamanho];
    for(int i=0; i<tamanho; ++i){
        if(!(file>>vetor[i])){/*Falhou em ler um dos valores */}
    }

    //int vetor[] = {170, 45, 75, 90, 802, 24, 2 , 66};
    //int n = sizeof(vetor)/sizeof(vetor[0]);
    radixsort(vetor, tamanho);
    mostraVetor(vetor, tamanho);
    return 0;
}

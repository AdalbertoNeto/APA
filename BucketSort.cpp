//www.sanfoundry.com
//Algoritmo de ordenação em tempo linear
//Análise e projeto de algoritmos 2016.2
//Adalberto 11228217
#include <iostream>
#include <fstream>

using namespace std;

void bucketsort(int vetor[], int n){

    int range = 10000; //Limite de valores contido no exemplo
    int buckets[range];//cria o bucket

    for(int i=0; i<range; ++i){ //inicializa o bucket todos iguais a 0
        buckets[i] = 0;
    }

    for(int i=0; i<n; ++i) //Incrementa quantas vezes cada elemento está presente no vetor.
        ++buckets[vetor[i]];

    for(int i=0,j =0; j<range; ++j)//Ordema utilizando o  InsertionSort
        for(int k = buckets[j]; k>0; --k)
            vetor[i++] = j;
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


    //int input_vetor[] = {10, 24, 22, 62, 1, 50, 100, 75, 2, 3};
    //int n = sizeof (input_vetor)/ sizeof(input_vetor[0]);
    bucketsort(vetor, tamanho);

    cout<<"Sorted Array: "<<endl;
    for(int i=0; i<tamanho; ++i){
        cout<< vetor[i] <<" "<<endl;
    }
    return 0;
}

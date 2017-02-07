//www.sourcetricks.com
#include <iostream>
#include <fstream>

using namespace std;

//const int INPUT_SIZE = 20;
const int BUCKET_K = 10000;

void MostraVetor(int *vetor, int n){
    for(int i =0; i< n; i++)
        cout << vetor[i] << " " << endl;
}

void countingsort(int* vetor, int n){
    int CountVetor[BUCKET_K] = { 0 };

    for(int i=0; i<n; i++){
        CountVetor[vetor[i]]++;
    }

    int outputIndex = 0;
    for(int j=0; j<BUCKET_K; j++){
        while(CountVetor[j]--)
            vetor[outputIndex++] = j;
    }
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

    //int input[INPUT_SIZE] = {2,4,6,4,7,1,4,9,5,3,7,2,2,6,9,3,7,3,4,4};
    //cout<<"Input: "<<endl;
    //MostraVetor(input);

    countingsort(vetor, tamanho);
    cout<<"Output: "<<endl;
    MostraVetor(vetor, tamanho);

    return 0;
}

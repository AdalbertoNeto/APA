#include <iostream>

using namespace std;

const int INPUT_SIZE = 20;
const int BUCKET_K = 10;

void MostraVetor(int *input){
    for(int i =0; i< INPUT_SIZE; i++)
        cout << input[i] << " " << endl;
}

void countingsort(int* input){
    int CountVetor[BUCKET_K] = { 0 };

    for(int i=0; i<INPUT_SIZE; i++){
        CountVetor[input[i]]++;
    }

    int outputIndex = 0;
    for(int j=0; j<BUCKET_K; j++){
        while(CountVetor[j]--)
            input[outputIndex++] = j;
    }
}

int main(){
    int input[INPUT_SIZE] = {2,4,6,4,7,1,4,9,5,3,7,2,2,6,9,3,7,3,4,4};

    cout<<"Input: ";
    MostraVetor(input);

    countingsort(input);
    cout<<"Output: ";
    MostraVetor(input);

    return 0;
}

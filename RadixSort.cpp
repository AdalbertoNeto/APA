//www.geeksforgeeks.org
#include<iostream>
#include<fstream>
using namespace std;

int getMax(int vetor[], int n){
    int mx = vetor[0];
    for(int i =1; i<n; i++)
        if(vetor[i] > mx)
            mx = vetor[i];
    return mx;
}

void countSort(int vetor[], int n, int exp){
    int output[n];
    int i, count[10] = {0};

    for(i=0; i<n; i++)
        count[(vetor[i]/exp)%10]++;

    for(i=1; i<10; i++)
        count[i] += count[i-1];

    for(i=n -1; i>=0; i--){
        output[count[(vetor[i]/exp)%10] -1] = vetor[i];
        count[(vetor[i]/exp)%10] --;
    }

    for(i=0; i<n; i++)
        vetor[i] = output[i];
}

void radixsort(int vetor[], int n){
    int m = getMax(vetor, n);

    for(int exp = 1; m/exp >0; exp *=10)
        countSort(vetor, n , exp);
}

void mostraVetor(int vetor[], int n){
    for(int i =0; i<n; i++)
        cout << vetor[i] << " "<<endl;
}

int main(){
    int vetor[] = {170, 45, 75, 90, 802, 24, 2 , 66};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    radixsort(vetor, n);
    mostraVetor(vetor, n);
    return 0;
}

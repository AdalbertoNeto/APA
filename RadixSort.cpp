//www.geeksforgeeks.org
#include<iostream>
#include<fstream>
using namespace std;

int getMax(int vetor[], int n){
    int mx = vetor[];
    for(int i =1; i<n; i++)
        if(vetor[i] > mx)
            mx = vetor[i];
    return mx;
}

void

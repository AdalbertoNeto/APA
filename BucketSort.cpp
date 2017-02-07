//www.sanfoundry.com
#include <iostream>
using namespace std;

void bucketsort(int vetor[], int n){

    int range = 101;
    int buckets[range];

    for(int i=0; i<range; ++i){
        buckets[i] = 0;
    }

    for(int i=0; i<n; ++i)
        ++buckets[vetor[i]];

    for(int i=0,j =0; j<range; ++j)
        for(int k = buckets[j]; k>0; --k)
            vetor[i++] = j;
}

int main(){
    int input_vetor[] = {10, 24, 22, 62, 1, 50, 100, 75, 2, 3};
    int n = sizeof (input_vetor)/ sizeof(input_vetor[0]);
    bucketsort(input_vetor, n);

    cout<<"Sorted Array: "<<endl;
    for(int i=0; i<n; ++i){
        cout<< input_vetor[i] <<" "<<endl;
    }
    return 0;
}

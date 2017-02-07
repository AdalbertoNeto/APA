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



}

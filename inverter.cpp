#include <iostream>
#include <stdio.h>

using namespace std;

void inverter (int *v, int n){

    int inicio = 0;
    int fim = n-1;

    while(inicio < fim){
        if(inicio != fim){
            int aux = *(v+inicio);
            *(v+inicio) = *(v+fim);
            *(v+fim) = aux;
        }
        ++inicio;
        --fim;
    }
}

int main(){

    int vetor[5] = {17, 42, 9, 33, 12};
    int *v = vetor+0;
    int *fim = vetor+5;
    inverter(v, 5);
    for(v; v!=fim; ++v){
        printf("%d\n", *v);
    }
}

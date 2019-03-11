#include <iostream>

using namespace std;


void particionar(int *pivor, int *i, int *f){

    cout << "vamos particionar o vetor : ";
    for(int *k=i; k<=f; k++){
        cout << *k << " ";
    }
    cout << "pivor = " << *pivor;
    cout << " i = " << *i;
    cout << " f = " << *f;
    cout << "\n";

    if(pivor != i){
        int aux = *i;
        *i = *pivor;
        *pivor = aux;
        pivor = i;
    }

    int *j = i+1;
    int *x = i;
    while (j <= f){
        if(*j <= *pivor){
            ++x;
            if(j !=  x){
                int aux = *x;
                *x = *j;
                *j = aux;
            }
        }
        j++;
    }

    if(x != i){
        int aux = *x;
        *x = *i;
        *i = aux;
    }

    cout << "apos particionar: ";
    for(int *k=i; k<=f; k++){
        cout << *k << " ";
    }
    cout << "pivor = " << *x;
    cout << "\n\n";


    if(x != i){
        particionar(x-1, i, x-1);
    }
    if (x != f){
        particionar(x+1, x+1, f);
    }
}

int main(){

    int vetor[11] = {8,-9,3,0,-2,5,7,1,-4,4,-1};
    int *v = vetor;
    int *i = v;
    int *f = v+10;
    int *pivor = v;

    particionar(pivor, i, f);
    for(int *k=i; k<=f; k++){
        cout << *k << " ";
    }
    cout << "\n";
}

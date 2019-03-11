#include <iostream>

using namespace std;


int* particionar(int pivor, int *i, int *f, int *v){

    cout << "comecar particionamento \n";
    if(pivor != 0){
        int aux = *i;
        *i = *(v+pivor);
        *(v+pivor) = aux;
        pivor = 0;
    }

    for(int *k=i; k<=f; k++){
        cout << *k << " ";
    }
    cout << "\n";
    int *j = i+1;
    int *x = i;
    while (j <= f){
        if(*j <= *(v+pivor)){
            ++x;
            if(j !=  x){
                int aux = *x;
                *x = *j;
                *j = aux;
            }
        }
        j++;
        for(int *k=i; k<=f; k++){
            cout << *k << " ";
        }
        cout << "\n";
    }

    if(x != i){
        int aux = *x;
        *x = *(v+0);
        *(v+0) = aux;
    }

    return x;
}

int main(){

    int vetor[6] = {17, 12, 42, 9, 33, 12};
    int *v = vetor;
    int *i = v;
    int *f = v+4;

    int *pivor = particionar(5, i, f, v);
    for(int *k=i; k<=f; k++){
        cout << *k << " ";
    }
    cout << "\n";
    int x=0;
    for(int *k=i; k<f; k++){
        if(k == pivor)
            break;
        x++;
    }
    cout << x;

}

#include <iostream>

using namespace std;

void selecionar(int *selecao, int *i, int *f){

    int *x = i;

    while (selecao != x){
        int *pivor = i;

        int *j = i+1;
        x = i;
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

        if( selecao > x ){
            i = x+1;
        } else if(selecao < x){
            f = x-1;
        }
    }
}

int main(){

    int vetor[11] = {8,-9,3,0,-2,5,7,1,-4,4,-1};
    int *v = vetor;
    int *i = v;
    int *f = v+10;
    int *selecao = v+6;

    selecionar(selecao, i, f);
    for(int *k=i; k<=f; k++){
        cout << *k << " ";
    }
    cout << "\n";
}

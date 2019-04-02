#include <iostream>

using namespace std;

int* selecionarMedianaDasMedianas(int *selecao, int space, int *i, int *f){

    int *x = i;

    while (selecao != x){

        int *pivor = i;

        int *j = i+space;
        x = i;
        bool loop = true;
        if( j > f )
            loop = false;

        while (loop){
            if(j>=f){
                j = f;
                loop = false;
            }

            if(*j <= *pivor){
                x+=space;
                if(j !=  x){
                    int aux = *x;
                    *x = *j;
                    *j = aux;
                }
            }
            j+=space;
        }

        if(x != i){
            int aux = *x;
            *x = *i;
            *i = aux;
        }

        if( selecao > x ){
            if( x+space <= f )
                i = x+space;
            else
                i = f;
        } else if(selecao < x){
            f = x-space;
        }
    }

    return selecao;
}

int main(){

    int vetor[11] = {2, 4, 5, 6, 6, 2, 3, 3, 4, 5, 1};
    int *v = vetor;
    int *i = v+2;
    int *f = v+16;
    int *selecao = v+7;

    int *mediana = selecionarMedianaDasMedianas(selecao, 5, i, f);
    cout << *mediana << "\n";
    for(int k=0; k<18; k++){
        cout << vetor[k] << " ";
    }
    cout << "\n";
}


#include <iostream>
#include <math.h>
#include <random>
#include <time.h>

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

int* pivorMedio(int *i, int *f) {

    int divisao = 5;

    int *inicio = i;

    int *fimDasMedianas = i-1;
    while(inicio <= f){

        int *fim = inicio+(divisao-1);
        if( fim > f )
             fim = f;

        int meio = ceil(((fim-inicio)+1) / 2.0);
        int *mediana = inicio+(meio-1);
        selecionar(mediana, inicio, fim);
        fimDasMedianas++;
        int aux = *fimDasMedianas;
        *fimDasMedianas = *mediana;
        *mediana = aux;
        inicio += divisao;
    }

    int meio = ceil(((fimDasMedianas-i)+1) / 2.0);
    int *mediana = i+(meio-1);
    selecionar(mediana, i, fimDasMedianas);
    return mediana;
}

void particionamento_triplo(int *pivor, int *i, int *f){

    while(i < f){
        //coloca pivor para o inicio do vetor
        if(pivor != i){
            int aux = *i;
            *i = *pivor;
            *pivor = aux;
            pivor = i;
        }

        int *j = i+1;
        int *menor = i;
        int *igual = i;


        while (j <= f){
            if(*j < *pivor){
                ++menor;
                ++igual;

                int aux = *menor;
                *menor = *igual;
                *igual = aux;

                if(igual != j){
                    aux = *menor;
                    *menor = *j;
                    *j = aux;
                }
            }
            else if(*j == *pivor){
                ++igual;
                int aux = *igual;
                *igual = *j;
                *j = aux;
            }
            j++;
        }

        //devolve o pivor para sua posicao correta
        if(menor > i){
            int aux = *menor;
            *menor = *i;
            *i = aux;
        }

        int esq = menor - i;
        int dir = f - igual;

        if(esq <= dir){
            if(menor > i){
                particionamento_triplo(pivorMedio(i,menor-1), i, menor-1);
            }
            i = igual+1;
            if(i<=f)
                pivor = pivorMedio(i, f);
        }else {
            if (igual != f){
                particionamento_triplo(pivorMedio(igual+1,f), igual+1, f);
            }
            f = menor -1;
            if(i<=f)
                pivor = pivorMedio(i, f);
        }
    }
}

void gerarVetorAleatorio(int *vetor, int tamanhoVetor, int intervaloInicial, int intervaloFinal){

    random_device rd;
    mt19937 ger(rd());

    uniform_int_distribution<int> dis(intervaloInicial, intervaloFinal);

    for(int i=0; i<tamanhoVetor; ++i){
        *(vetor+i) = dis(ger);
    }
}

main() {

    int tamanhoVetor;
    cout << "Tamanho do vetor = ";
    cin >> tamanhoVetor;

    int intervaloInicial;
    cout << "Intervalo inicial dos numeros gerados = ";
    cin >> intervaloInicial;

    int intervaloFinal;
    cout << "Intervalo final dos numeros gerados = ";
    cin >> intervaloFinal;

    int *vetor = new int[tamanhoVetor];
    int *v = vetor;
    int *i = v;
    int *f = v+(tamanhoVetor-1);
    int *pivor = pivorMedio(i, f);
    gerarVetorAleatorio(v, tamanhoVetor, intervaloInicial, intervaloFinal);


    time_t start = time(nullptr);
    particionamento_triplo(pivorMedio(v,(v+(tamanhoVetor-1))), v, (v+(tamanhoVetor-1)));
    double diff = difftime(time(nullptr), start);

    bool ordenado = true;
    for(int i=0; i<tamanhoVetor-1; ++i){
        if(vetor[i] > vetor[i+1])
            ordenado = false;
    }

    if(ordenado){
        printf("Vetor ordenado com sucesso em %.f segundos\n", diff);
    }else{
        cout<<"vetor nao foi ordenado com sucesso\n";
    }
}

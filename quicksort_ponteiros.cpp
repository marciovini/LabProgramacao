#include <iostream>
#include <math.h>
#include <random>
#include <time.h>

using namespace std;

void gerarVetorAleatorio(int *vetor, int tamanhoVetor, int intervaloInicial, int intervaloFinal){

    random_device rd;
    mt19937 ger(rd());

    uniform_int_distribution<int> dis(intervaloInicial, intervaloFinal);

    for(int i=0; i<tamanhoVetor; ++i){
        *(vetor+i) = dis(ger);
    }
}

int* escolhe_pivo(int *primeiro,int *ultimo){
    return primeiro;
}

ordenar(int *pivor, int *i, int *f){

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
        ++j;
    }

    if(x != i){
        int aux = *x;
        *x = *i;
        *i = aux;
    }

    if(x != i){
        ordenar(escolhe_pivo(i,x-1), i, x-1);
    }
    if (x != f){
        ordenar(escolhe_pivo(x+1,f), x+1, f);
    }
}

main() {

    bool executarTeste = true;

    while(executarTeste){
        system("clear||cls");
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
        gerarVetorAleatorio(v, tamanhoVetor, intervaloInicial, intervaloFinal);


        time_t start = time(nullptr);
        ordenar(escolhe_pivo(v,(v+(tamanhoVetor-1))), v, (v+(tamanhoVetor-1)));
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

        char executarNovoTeste;
        cout<<"Deseja executar novo teste (y\\n)?";
        cin >> executarNovoTeste;

        if(executarNovoTeste != 'y')
            executarTeste = false;

        delete []vetor;
    }
}


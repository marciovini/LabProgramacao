#include <iostream>

using namespace std;

class No{
    public:
        int valor;
        No *proximoNo;
};

int main() {

    int m;
    cout << "Digite o valor de M = ";
    cin >> m;
    int n;
    No **lista = new No*[m];
    for(int i=0; i<m; i++){
        lista[i] = nullptr;
    }

    cout<<"Digite n = ";
    cin >> n;

    while(n>=0){

        int resto = n % m;
        No *no = new No;
        if(no == nullptr){
            break;
        }
        no->valor = n;
        No *primeiro = lista[resto];
        no->proximoNo = primeiro;
        lista[resto] = no;
        cout<<"Digite n = ";
        cin >> n;
    }

    for(int i=0; i<m; i++){
        No *no = lista[i];
        cout << "lista " << i << " = ";
        while(no != nullptr){
            No noV = *no;
            cout << " " << noV.valor;
            no = noV.proximoNo;
        }
        cout << "\n";
    }
}

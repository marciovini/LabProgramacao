#include <iostream>
#include <stdio.h>

using namespace std;

bool sao_iguais(const char *r,const char *s){

    bool result = true;
    for(r; *r!='\0'; ++r){
        printf("r = %c \n", *r);
        printf("s = %c \n", *s);
        if(*r != *s){
            result = false;
            break;
        }
        ++s;
    }

    for(s; *s!='\0'; ++s){
        printf("r = %c \n", *r);
        printf("s = %c \n", *s);
        if(*r != *s){
            result = false;
            break;
        }
        ++r;
    }
    return result;
}


int main(){

    const char s1[] = "tese";
    const char s2[] = "teste";
    const char *r = &s1[0];
    const char *s = &s2[0];
    bool resultado = sao_iguais(r,s);
    cout <<resultado;
}


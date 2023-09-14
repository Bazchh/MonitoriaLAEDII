#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 32

struct contato{
 char *nome;
 char *tel;
 char *email;
};

int concatenacao(char c[]){
    int key = 0, i = 0;
    while(c[i] != '\0'){
        key += c[i];
        i++; 
    } 
    return key;
}

int funHashDiv(int key){
    return key % size;
}

int funcHashMult(int key){
    srand(time(NULL));
    float random = rand()/RAND_MAX;
    return key * random * size;
}

typedef struct contato *agendaDeContatos[size];

int inserir(agendaDeContatos Hash, struct contato *c){
    int key = concatenacao(c->nome);
    key = funHashDiv(key);
    int key_inicio = key;


    while(1){
        if(Hash[key] == 0){
            Hash[key] = c;
            break;
        }
        key++;

        if(key_inicio == key){
            break;
        }

        if(key > size){
            key = key%size;
            key_inicio = key;
        }
    }
}

int main(){
    
}

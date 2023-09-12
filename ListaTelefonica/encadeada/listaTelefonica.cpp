#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 32

struct contato{
 char nome[20];
 char tel[11];
 char email[20];
 struct no *prox;
};

struct no{
    struct contato *contato;
    struct no *prox;
};

struct contato *criaContato(char nome[], char tel[], char email[]){
    struct contato *novo = (struct contato *)malloc(sizeof(struct contato));
    strcpy(novo->nome,nome);
    strcpy(novo->tel,tel);
    strcpy(novo->email,email);
    return novo;
}

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

void iniciarAgenda(agendaDeContatos &Hash){
    int i;
    for(i = 0; i < size; i++){
        Hash[i] = 0;
        Hash[i]->prox = NULL;
    }

}

int inserir(agendaDeContatos Hash, struct contato *c){
    int key = concatenacao(c->nome);
    key = funHashDiv(key);

    if(Hash[key] == 0){
        Hash[key] = c;
    } else {
        struct no *novo = (struct no*)malloc(sizeof(struct no));
        novo = Hash[key]->prox;
        for(novo; novo != NULL; novo = novo->prox ){
            if(novo == NULL){
                novo->contato = c;
            }
        }
    }
}

int main(){
    struct contato *novo = (struct contato*)malloc(sizeof(contato));
    char *nome = "Mikael";
    char *tel = "84996488895";
    char *email = "mikael.vidal@gmail.com";
    novo = criaContato(nome, tel,email);

    agendaDeContatos agenda;
    inserir(agenda,novo);

}
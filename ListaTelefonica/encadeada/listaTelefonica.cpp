#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 32

struct contato{
 char nome[20];
 char tel[11];
 char email[20];
 struct lista *prox;
};

struct lista{
    struct contato *contato;
    struct lista *prox;
};

struct contato *criaContato(char *nome, char *tel, char *email){
    struct contato *novo = (struct contato *)malloc(sizeof(struct contato));
    strncpy(nome,novo->nome,sizeof(nome)-1);
    strncpy(tel,novo->tel,sizeof(tel)-1);
    strncpy(email,novo->email,sizeof(email)-1);
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

typedef struct lista *agendaDeContatos[size];

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
        Hash[key]->contato = c;
    } else {
        struct lista *novo = (struct lista*)malloc(sizeof(struct lista));
        novo = Hash[key]->prox;
        for(novo; novo != NULL; novo = novo->prox ){
            if(novo == NULL){
                novo->contato = c;
            }
        }
    }
    
    return key;
}

int main(){
    struct contato *novo = (struct contato*)malloc(sizeof(contato));
    char *nome;
    strncpy(nome,"Mikael", sizeof("Mikael")-1);
    char *tel;
    strncpy(tel,"84996488895",sizeof("84996488895")-1);
    char *email;
    strncpy(email,"mikael.vidal@gmail.com",sizeof("mikael.vidal@gmail.com")-1);
    novo = criaContato(nome, tel,email);

    agendaDeContatos agenda;
    inserir(agenda,novo);

}

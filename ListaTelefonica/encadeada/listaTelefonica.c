#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define size 32

struct contato{
 char *nome;
 char *tel;
 char *email;
};

struct lista{
    struct contato *contato;
    struct lista *prox;
};

struct contato *criaContato(char *nome, char *tel, char *email){
    struct contato *novo = (struct contato *)malloc(sizeof(struct contato));
    novo->nome = (char *)malloc(sizeof(char));
    novo->tel = (char *)malloc(sizeof(char));
    novo->email = (char *)malloc(sizeof(char));
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

typedef struct lista *agendaDeContatos[size];

void iniciarAgenda(agendaDeContatos Hash){
    int i;
    for(i = 0; i < size; i++){
        Hash[i] = NULL;
    }

}

int inserir(agendaDeContatos Hash, struct contato *c){
    size_t key = concatenacao(c->nome);
    key = funHashDiv(key);
    struct lista*novo = (struct lista*)malloc(sizeof(struct lista));
    novo->contato = c;
    novo->prox = NULL;
    if(Hash[key] == NULL){
        Hash[key] = novo;
    } else {
        struct lista *aux = Hash[key]; 
        
        for(; aux->prox != NULL; aux = aux->prox );    
                aux->prox = novo;
    
            
    }
    
    return key;
}

int main(){

    struct contato *novo = (struct contato*)malloc(sizeof(struct contato));
    char *nome = (char*)malloc(sizeof(char));
    strncpy(nome,"Mikael", sizeof("Mikael"));
    char *tel = (char*)malloc(sizeof(char));
    strncpy(tel,"84996488895", sizeof("84996488895"));
    char *email = (char*)malloc(sizeof(char));
    strncpy(email,"mikael.vidal@gmail.com",sizeof("mikael.vidal@gmail.com"));
    novo = criaContato(nome, tel,email);

    agendaDeContatos agenda;
    iniciarAgenda(agenda);
    inserir(agenda,novo);
    nome = (char*)malloc(sizeof(char));
    strncpy(nome,"Joao", sizeof("Joao"));
    tel = (char*)malloc(sizeof(char));
    strncpy(tel,"84996488891", sizeof("84996488891"));
    email = (char*)malloc(sizeof(char));
    strncpy(email,"joao.vidal@gmail.com",sizeof("joao.vidal@gmail.com"));
    novo = criaContato(nome, tel,email);
    inserir(agenda,novo);

    strncpy(email,"joao.vidal@gmail.com",sizeof("joao.vidal@gmail.com"));

}

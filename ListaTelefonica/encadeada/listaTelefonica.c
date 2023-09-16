#include <stdio.h>
#include <stdlib.h>
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

double funcHashMult(int key){
    return (key * 0.2) / size;
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
    key = funcHashMult(key);
    struct lista*novo = (struct lista*)malloc(sizeof(struct lista));
    novo->contato = c;
    novo->prox = NULL;
    if(Hash[key] == NULL){
        Hash[key] = novo;
    } else {
        struct lista *aux = Hash[key]; 
        
        for(; aux->prox != NULL; aux = aux->prox);    
                aux->prox = novo;
    
            
    }
    
    return key;
}

struct contato *buscarContato(agendaDeContatos Hash, struct contato* c){
    size_t key = concatenacao(c->nome);
    key = funcHashMult(key);
    struct contato *novo;
    if(Hash[key]->contato == c){
        novo = Hash[key]->contato;
        return novo;
    } else {
        struct lista *aux = Hash[key]; 
        
        for(; aux != NULL; aux = aux->prox){
            if(aux->contato == c){
                return aux->contato;
            }
        }     
        
    }
    
}

void removerContato(agendaDeContatos Hash, struct contato *c){
    size_t key = concatenacao(c->nome);
    key = funcHashMult(key);
    
    struct lista *aux = Hash[key];
    struct lista *aux1 = aux;
    
    for(; aux != NULL; aux = aux->prox){
            if(aux->contato == c){  
                aux1->prox = aux->prox;
                free(aux);
                break;
            }
            aux1 = aux;
        
    }
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
    strncpy(nome,"Joao", sizeof("Joao"));
    strncpy(tel,"84996488891", sizeof("84996488891"));
    strncpy(email,"joao.vidal@gmail.com",sizeof("joao.vidal@gmail.com"));
    novo = criaContato(nome, tel,email);
    inserir(agenda,novo);
    inserir(agenda,novo);
    strncpy(email,"joao.vidal@gmail.com",sizeof("joao.vidal@gmail.com"));
    removerContato(agenda, novo);

}

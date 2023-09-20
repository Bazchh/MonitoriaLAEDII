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
    return key % size;
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

int removerContato(agendaDeContatos Hash, struct contato *c){
    size_t key = concatenacao(c->nome);
    key = funcHashMult(key);
    
    struct lista *aux = Hash[key];
    struct lista *aux1 = aux;
    
    if(aux->contato == c){
        if(aux->prox == NULL){
            free(aux1);
            return 1;
        } else {
            aux = aux->prox;
            free(aux1);
            return 1;
        }
    }

    for(; aux != NULL; aux = aux->prox){
            if(aux->contato == c){  
                aux1->prox = aux->prox;
                free(aux);
                break;
            }
            aux1 = aux;
        
    }
    return 0;
}

void exportarContatos(agendaDeContatos Hash){
    FILE *f = fopen("Agenda de Contatos","w");
    size_t i = 0;
    for(i; i < size; i++){
        struct lista *aux = Hash[i];
        while(aux != NULL){
            fprintf(f,"%s %s %s\n",aux->contato->nome, aux->contato->tel, aux->contato->email);
            aux = aux->prox;
        }
        
    }

}

void listarContatos(agendaDeContatos Hash){
    size_t i = 0;
    for(i; i < size; i++){
        struct lista *aux = Hash[i];
        while(aux != NULL){
            printf("\n Nome: %s \n Telefone: %s \n Email: %s\n",aux->contato->nome, aux->contato->tel, aux->contato->email);
            aux = aux->prox;
        }
        
    }

}

int main(){
    struct contato *novo = (struct contato*)malloc(sizeof(struct contato));
    char *nome = (char *)malloc(strlen("mikael") + 1); // +1 para o caractere nulo
    char *tel = (char *)malloc(strlen("84996488895") + 1);
    char *email = (char *)malloc(strlen("mikael.vidal@gmail.com") + 1);

    strcpy(nome, "mikael");
    strcpy(tel, "84996488895");
    strcpy(email, "mikael.vidal@gmail.com");

    novo = criaContato(nome,tel,email);
    agendaDeContatos agenda;
    iniciarAgenda(agenda);
    strcpy(nome, "mikael");
    strcpy(tel, "84996488895");
    strcpy(email, "mikael.vidal@gmail.com");

    inserir(agenda,novo);
    removerContato(agenda, novo);
    listarContatos(agenda);
}

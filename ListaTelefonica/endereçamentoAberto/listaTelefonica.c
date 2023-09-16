#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 32

struct contato{
 char *nome;
 char *tel;
 char *email;
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
    
    int inteiroAleatorio = rand();
    double random = (double)inteiroAleatorio / RAND_MAX;
    return (key * random) / size;
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

struct contato *buscarContato(agendaDeContatos Hash, struct contato *c){
    size_t key = concatenacao(c->nome);
    key = funcHashMult(key);
    struct contato *novo;
    int key_inicio = key;
    while(1){
        if(Hash[key] == c){
        novo = Hash[key];
        return novo;
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

void removerContato(agendaDeContatos Hash, struct contato *c){
    struct contato *novo = buscarContato(Hash, c);
    free(novo);
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
    inserir(agenda,novo);
    strncpy(nome,"Joao", sizeof("Joao"));
    strncpy(tel,"84996488891", sizeof("84996488891"));
    strncpy(email,"joao.vidal@gmail.com",sizeof("joao.vidal@gmail.com"));
    novo = criaContato(nome, tel, email);
    inserir(agenda,novo);
    removerContato(agenda, novo);
    
}

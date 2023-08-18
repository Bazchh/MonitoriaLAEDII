#include <stdio.h>
#include <stdlib.h>

//Estrutura que define uma arvore
struct arvore{
    int dados;
    struct arvore *esq;
    struct arvore *dir;
};

//Definição de escopo de funções
int verificaBalanceamento(struct arvore *raiz);
int sucessor(struct arvore *raiz);
int alturaDaArvore(struct arvore *raiz);
struct arvore *inserirNovoNo(struct arvore *raiz, int dados);
struct arvore *removerNo(struct arvore *raiz, int dados);
void mostrarArvore(struct arvore*raiz);

int main(){

struct arvore * raiz = (struct arvore*)malloc(sizeof(struct arvore));
raiz = NULL;

raiz = inserirNovoNo(raiz, 10);
raiz = inserirNovoNo(raiz, 22);
raiz = inserirNovoNo(raiz, 4);
raiz = inserirNovoNo(raiz, 1);
raiz = inserirNovoNo(raiz, 7);
raiz = inserirNovoNo(raiz, 16);
raiz = inserirNovoNo(raiz, 13);
raiz = inserirNovoNo(raiz, 19);
raiz = inserirNovoNo(raiz, 54);
raiz = inserirNovoNo(raiz, 28);
raiz = inserirNovoNo(raiz, 57);
raiz = inserirNovoNo(raiz, 51);
raiz = inserirNovoNo(raiz, 25);
raiz = inserirNovoNo(raiz, 48);
raiz = inserirNovoNo(raiz, 60);

int altura = alturaDaArvore(raiz);
printf("\nAltura da arvore: %i\n\n", altura);
mostrarArvore(raiz);
raiz = removerNo(raiz,54);
printf("\n");
mostrarArvore(raiz);
printf("\n");
int balanceamento = verificaBalanceamento(raiz);

if(balanceamento == 0){
    printf("\nA arvore está desbalanceada");
} else {
    printf("\nA arvore está balanceada");
}

}

 struct arvore *inserirNovoNo(struct arvore *raiz, int dados){
    if(raiz == NULL){
        struct arvore *novoNo = (struct arvore*)malloc(sizeof(struct arvore));
        novoNo->dados = dados;
        novoNo->esq = novoNo->dir = NULL;
        return novoNo;
    }
    
    if(dados < raiz->dados){
        raiz->esq = inserirNovoNo(raiz->esq, dados);
    } else if (dados > raiz->dados){
        raiz->dir = inserirNovoNo(raiz->dir, dados);
    } else {
        printf("\nEste valor já está presente na arvore");
    }

    return raiz;

}

int alturaDaArvore(struct arvore *raiz){
    if(raiz == NULL){
        return -1;
    }

    int alturaEsq = alturaDaArvore(raiz->esq);
    int alturaDir = alturaDaArvore(raiz->dir);

    return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
}

//Função que verifica se uma arvore está balanceada
int verificaBalanceamento(struct arvore *raiz){
    //caso a arvore esteja vazia, ela está balanceada e retornamos 1, sinalizando verdadeiro para o balanceamento
    if(raiz == NULL){
        return 1;
    }
    //Para verificar se uma arvore está balanceada devemos calcular a altura de ambos os lados da arvore, esquerdo e direito
    int alturaEsq = alturaDaArvore(raiz->esq);
    int alturaDir = alturaDaArvore(raiz->dir);

    //Depois, atraves de um operador ternario, que verifica atraves da subtração da altura direita com a esquerda ou ao contrario a diferença das alturas
    int balanceamento = (alturaEsq > alturaDir) ? alturaEsq - alturaDir : alturaDir - alturaEsq;

    //caso a diferença de altura seja mais que 1, então a arvore está desbalanceada
    if(balanceamento > 1){
        return 0;
    }

}

int sucessor(struct arvore *raiz){
 int s = raiz->dados;
    while(raiz->dir != NULL){
        s = raiz->dir->dados;
        raiz = raiz->dir;
    }
    //Removendo o sucessor encontrado para não permitir duplicação de valores
    raiz->dir = NULL;
    return s;
}

struct arvore *removerNo(struct arvore *raiz, int dados){

    if(raiz == NULL){
        printf("\nO valor buscado não está na arvore");
        return NULL;
    }

    
     if(dados < raiz->dados){
        raiz->esq = removerNo(raiz->esq, dados);
    } else if(dados > raiz->dados) {
        raiz->dir = removerNo(raiz->dir, dados);
    } else { 
        if(raiz->esq == NULL){
            return raiz->dir;
        }if(raiz->dir == NULL){
            return raiz->esq;
        }

      //Essa função reorganiza a arvore com base no sucessor do nó atual, colocando o sucessor no lugar do nó que queremos remover
      raiz->dados = sucessor(raiz->esq);
      //Ao realizar o processo anterior
      raiz->esq = removerNo (raiz->esq,raiz->dados);   

    }


    return raiz;

}

void mostrarArvore(struct arvore*raiz){

    if(raiz != NULL){
        printf(" %i ", raiz->dados);
    mostrarArvore(raiz->esq);
    
    mostrarArvore(raiz->dir);  
    
    }      
    
}
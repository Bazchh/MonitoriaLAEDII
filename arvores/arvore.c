#include <stdio.h>
#include <stdlib.h>

// Estrutura que define uma arvore
struct arvore {
  int dados;
  struct arvore *esq;
  struct arvore *dir;
};

// Definição de escopo de funções
int verificaBalanceamento(struct arvore *);
int antecessor(struct arvore *);
int alturaDaArvore(struct arvore *);
struct arvore *inserirNovoNo(struct arvore *, int );
struct arvore *removerNo(struct arvore *, int );
void mostrarArvore(struct arvore *);

int main() {

  struct arvore *raiz = (struct arvore *)malloc(sizeof(struct arvore));
  raiz = NULL;

  raiz = inserirNovoNo(raiz, 30);
  raiz = inserirNovoNo(raiz, 20);
  raiz = inserirNovoNo(raiz, 12);
  raiz = inserirNovoNo(raiz, 25);
  raiz = inserirNovoNo(raiz, 27);
  raiz = inserirNovoNo(raiz, 40);
  raiz = inserirNovoNo(raiz, 35);
  raiz = inserirNovoNo(raiz, 41);
  raiz = inserirNovoNo(raiz, 42);

  int altura = alturaDaArvore(raiz);
  printf("\nAltura da arvore: %i\n\n", altura);
  mostrarArvore(raiz);
  raiz = removerNo(raiz, 54);
  printf("\n");
  mostrarArvore(raiz);
  printf("\n");
  int balanceamento = verificaBalanceamento(raiz);

  if (balanceamento == 0) {
    printf("\nA arvore está desbalanceada");
  } else {
    printf("\nA arvore está balanceada");
  }
}

// Função para inserir um novo nó na arvore
struct arvore *inserirNovoNo(struct arvore *raiz, int dados) {
  // Caso encontremos uma folha da arvore, inserimos os nossos novos dados
  // naquela folha
  if (raiz == NULL) {
    struct arvore *novoNo = (struct arvore *)malloc(sizeof(struct arvore));
    novoNo->dados = dados;
    novoNo->esq = novoNo->dir = NULL;
    return novoNo;
  }

  // Se a arvore nao estiver vazia, verificamos o valor dentro do nó
  // Se o valor a qual queremos inserir for menor do que o valor do nó atual,
  // inserimos o novo nó a esquerda do nó atual
  if (dados < raiz->dados) {
    // É realizado a recursão nos nós esquerdos até que cheguemos no caso base
    // da linha 60
    raiz->esq = inserirNovoNo(raiz->esq, dados);
    // Se o valor a qual queremos inserir for maior do que o valor do nó atual,
    // inserimos o novo nó a direita do nó atual
  } else if (dados > raiz->dados) {
    // É realizado a recursão nos nós direitos até que cheguemos no caso base da
    // linha 60
    raiz->dir = inserirNovoNo(raiz->dir, dados);
  } else {
    // Se nenhuma das condições forem atendidas, significa que o valor a qual
    // queremos inserir ja está presente na arvore
    printf("\nEste valor já está presente na arvore");
  }

  return raiz;
}
// Função para calcular a altura da arvore
int alturaDaArvore(struct arvore *raiz) {
  // Caso cheguemos em uma folha, retornamos o valor -1 para a chamada recursiva
  // de cima
  if (raiz == NULL) {
    return -1;
  }
  // Calculando a altura das subarvore a esquerda
  int alturaEsq = alturaDaArvore(raiz->esq);
  // Calculando a altura das subarvore a direita
  int alturaDir = alturaDaArvore(raiz->dir);

  // Quando estamos em um nó preenchido com algum valor, verificamos a altura
  // das subarvores a esquerda e direita do nó pai e retornamos o maior valor da
  // alturas de uma das duas subarvores
  return (alturaEsq > alturaDir) ? alturaEsq + 1 : alturaDir + 1;
}

// Função que verifica se uma arvore está balanceada
int verificaBalanceamento(struct arvore *raiz) {
  // caso a arvore esteja vazia, ela está balanceada e retornamos 1, sinalizando
  // verdadeiro para o balanceamento
  if (raiz == NULL) {
    return 1;
  }
  // Para verificar se uma arvore está balanceada devemos calcular a altura de
  // ambos os lados da arvore, esquerdo e direito
  int alturaEsq = alturaDaArvore(raiz->esq);
  int alturaDir = alturaDaArvore(raiz->dir);

  // Depois, atraves de um operador ternario, que verifica atraves da subtração
  // da altura direita com a esquerda ou ao contrario a diferença das alturas
  int balanceamento =
      (alturaEsq > alturaDir) ? alturaEsq - alturaDir : alturaDir - alturaEsq;

  // caso a diferença de altura seja mais que 1, então a arvore está
  // desbalanceada
  if (balanceamento > 1) {
    return 0;
  }
}

int antecessor(struct arvore *raiz) {
  int s = raiz->dados;
  while (raiz->dir != NULL) {
    s = raiz->dir->dados;
    raiz = raiz->dir;
  }
  // Removendo o antecessor encontrado para não permitir duplicação de valores
  raiz->dir = NULL;
  return s;
}

struct arvore *removerNo(struct arvore *raiz, int dados) {

  if (raiz == NULL) {
    printf("\nO valor buscado não está na arvore");
    return NULL;
  }

  if (dados < raiz->dados) {
    raiz->esq = removerNo(raiz->esq, dados);
  } else if (dados > raiz->dados) {
    raiz->dir = removerNo(raiz->dir, dados);
  } else {

    if (raiz->esq == NULL) {
      return raiz->dir;
    }
    if (raiz->dir == NULL) {
      return raiz->esq;
    }

    // Essa função reorganiza a arvore com base no antecessor do nó atual,
    // colocando o antecessor no lugar do nó que queremos remover
    raiz->dados = antecessor(raiz->esq);
    // Ao realizar o processo anterior
    raiz->esq = removerNo(raiz->esq, raiz->dados);
  }

  return raiz;
}

void mostrarArvore(struct arvore *raiz) {

  if (raiz != NULL) {

    mostrarArvore(raiz->esq);

    mostrarArvore(raiz->dir);
    printf(" %i ", raiz->dados);
  }
}

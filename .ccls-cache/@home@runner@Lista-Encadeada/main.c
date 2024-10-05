#include <stdio.h>
#include <stdlib.h>

// struct "no" possui dois campos
typedef struct no
{
    int v; // inteiro "v"
    struct no *prox; // ponteiro para o próximo elemento
} t_no;

t_no *cabeca = NULL;
//cria a lista inicial
t_no * criar_lista(int valor){
  //aloca espaço em memória
  t_no * p = (t_no*) malloc(sizeof(t_no));

  if(p==NULL){
    printf("Falha ao alocar memória");
    return NULL;
  }

  p->v = valor;
  p->prox = NULL;
  cabeca = p;
  return p;
 
}

//imprimi a lista
void imprimir_lista(){
  t_no *aux = cabeca;
  while(aux != NULL){
    printf("%d\n", aux->v);
    aux = aux->prox;
  }
}

//mostra o tamanho da lista
void tamanho_lista(){
  int quantidade = 0;
  t_no *aux = cabeca;
  while(aux != NULL){
    quantidade++;
    aux = aux->prox;
  }
  printf("A quantidade da lista é: %d\n", quantidade);
}

//exclui um item da lista no meio e inseri um valor determinado
void excluir_lista(int v){
  t_no *aux = aux = cabeca;
  //Percorrendo até o último registro
  t_no *ant = cabeca;
  while(aux->prox != NULL)
    if(aux->v == v){
      ant->prox = aux->prox;
      free(aux);
    }else{
      ant = aux;
      aux = aux->prox;
    }
}

//inseri um valor no inicio da lista (cabeça)
t_no* inserir_inicio(int v){
  if(cabeca==NULL)
      return criar_lista(v);
 
  t_no * p = (t_no*)malloc(sizeof(t_no));
  p->v = v;
  p->prox = cabeca;
  cabeca = p;
  return p;
}

//adiciona item a lista de um em um e aloca espaço na memória para armazenar os próximo
t_no* adicionar_lista(int v){
  if(cabeca==NULL)
      return criar_lista(v);
 
  t_no * p = (t_no*)malloc(sizeof(t_no));
  p->v = v;
  p->prox = NULL;
  t_no *aux = aux = cabeca;
  //Percorrendo até o último registro
  while(aux->prox != NULL)
    aux = aux->prox;
 
  aux->prox = p;
  return p;
}

//exclui o ultimo item da lista e inclui um valor determinado
/*void excluir_final(){
  t_no *aux = aux = cabeca;
  //Percorrendo até o último registro
  t_no *ult = cabeca;
  while(aux->prox != NULL)
    if(aux->v == v){
      ult->prox = aux->prox;
      free(aux);
    }else{
      ult = aux;
      aux = aux->prox;
    }
}*/

//função principal
int main(){
  
  criar_lista(10);
  imprimir_lista();
  tamanho_lista();
  
  adicionar_lista(50);
  imprimir_lista();
  tamanho_lista();
  
  adicionar_lista(70);
  imprimir_lista();
  tamanho_lista();
  
  excluir_lista(50);
  imprimir_lista();
  tamanho_lista();
  
  inserir_inicio(100);
  imprimir_lista();
  tamanho_lista();
   
  /*excluir_final();
  imprimir_lista();
  tamanho_lista();*/
  
  
  return(0);
}
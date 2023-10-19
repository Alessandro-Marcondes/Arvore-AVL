#include <stdio.h>
#include <stdlib.h>
#include "bst.h"




int id = 0;
link novoNo (int item, link l, link r) {
  link t = malloc(sizeof(struct node));
  t->item = item;
  t->l = l;
  t->r = r;
  t->N = 1;
  t->id = id++;
  return t;
}
Tree createTree(){
  Tree t = malloc (sizeof (struct tree));
  t->z = malloc (sizeof(struct node));
  t->head = t->z;
  t->z->l = t->z;
  t->z->N = 0;
  t->z->r = t->z;
  return t;
}

link rotR(Tree t, link h) {
  link x = h->l;
  h->l = x->r;
  x->r = h;

  // Atualiza a altura e o tamanho da sub�rvore
  h->height = max(height(h->l), height(h->r)) + 1;
  h->N = 1 + size(h->l) + size(h->r);

  x->height = max(height(x->l), height(x->r)) + 1;
  x->N = 1 + size(x->l) + size(x->r);

  return x;
}

link rotL(Tree t, link h) {
  link x = h->r;
  h->r = x->l;
  x->l = h;

  // Atualiza a altura e o tamanho da sub�rvore
  h->height = max(height(h->l), height(h->r)) + 1;
  h->N = 1 + size(h->l) + size(h->r);

  x->height = max(height(x->l), height(x->r)) + 1;
  x->N = 1 + size(x->l) + size(x->r);

  return x;
}

int size(link x) {
  if (x == NULL) {
    return 0;
  }
  return x->N;
}

link searchR(Tree t, link h, int query) {
  if (h == t->z) {
    return NULL;
  }
  if(h->item == query) 
    return h;
  if (h->item >= query) 
    return searchR(t, h->l, query);
  return searchR(t, h->r, query);
} 


link search (Tree t, int query){
   return searchR(t, t->head, query);
}

link insertR(Tree t, link h, link n) {
  if (h == t->z) {
    return n;
  }

  if (n->item < h->item) {
    h->l = insertR(t, h->l, n);
  } else {
    h->r = insertR(t, h->r, n);
  }

  // Atualiza a altura e o tamanho da sub�rvore
  h->height = max(height(h->l), height(h->r)) + 1;
  h->N = 1 + size(h->l) + size(h->r);

  return h;
}

link insert (Tree t, int item){
  if(t->head == t->z) {
    return (t->head =novoNo(item, t->z, t->z));
  }
  return insertR(t, t->head, novoNo(item, t->z, t->z));
}

void imprimeEmOrdem (Tree t, link h){
  if(h == t->z) return;
  imprimeEmOrdem (t, h->l);
  printf("<chave: %d N: %d>", h->item, h->N); 
  imprimeEmOrdem (t, h->r);
}

void imprimePosOrdem (Tree t, link h){
  if(h == t->z) return;
  imprimePosOrdem (t, h->l);
  imprimePosOrdem (t, h->r);
  printf("<chave: %d N: %d>", h->item, h->N); 
}
void imprimePreOrdem (Tree t, link h, int k) {
  if(h == t->z) return;
  int i = 0; // definir variavel fora do la�o
  for(i = 0; i <= k; i++)
    printf (" . ");
  printf("<chave: %d N: %d>\n", h->item, h->N); 
  imprimePreOrdem (t, h->l, k + 1); 
  imprimePreOrdem (t, h->r, k + 1);
}


void printnode (char  *x, int h) {
    int i;
    for(i = 0; i < h; i++)
        printf("\t");
    printf("%s\n", x);
}
int c = 0;
void imprimeR(Tree a, link t){
    char s[255];
    if(t==a->z) { return;}
    imprimeR(a,t->r);
    printf ("%d [ label = \"<f0>| <f1> %d (%d) | <f2>\" ]\n", t->id, t->item, t->N);
    if(t->l != a->z){
        printf("%d:f0->%d:f1;\n", t->id, t->l->id);
    } else {
        printf("z%d [ shape=point ];\n", c);
        printf("%d:f0->z%d;\n", t->id, c);
        c++;
    }
    if(t->r != a->z){
        printf("%d:f2->%d:f1;\n", t->id, t->r->id);
    } else {
        printf("z%d [ shape=point ];\n", c);
        printf("%d:f2->z%d;\n", t->id, c );
        c++;
    }
    imprimeR(a,t->l);
}
void imprime(Tree a, char *s) {
    c = 0;
    printf("digraph %s {\n", s);
    printf ("node [shape=record,style=rounded, height=.1]\n");
    imprimeR(a, a->head);
    printf("}\n");
}
void imprimeFromNode(Tree a, link h, char *s) {
  c = 0;
  printf("digraph  {\n" );
  printf ("name [label = \"%s\",shape=plaintext]\n", s);
  printf ("node [shape=record,style=rounded, height=.1]\n");
  imprimeR(a, h);
  printf("}\n");
}

link AVLinsertR(Tree t, link h, int item) {
  if (h == t->z) {
    return novoNo(item, t->z, t->z);
  }

  if (item < h->item) {
    h->l = AVLinsertR(t, h->l, item);
  } else {
    h->r = AVLinsertR(t, h->r, item);
  }

  // Atualiza a altura e o tamanho da sub�rvore
  h->height = max(height(h->l), height(h->r)) + 1;
  h->N = 1 + size(h->l) + size(h->r);

  // Calcula o fator de balanceamento do n� atual
  int balance = getBalance(h);

  // Verifica o balanceamento e realiza rota��es, se necess�rio
  // Rota��o simples � direita
  if (balance > 1 && item < h->l->item) {
    return rotR(t, h);
  }

  // Rota��o simples � esquerda
  if (balance < -1 && item > h->r->item) {
    return rotL(t, h);
  }

  // Rota��o dupla � direita (esquerda-direita)
  if (balance > 1 && item > h->l->item) {
    h->l = rotL(t, h->l);
    return rotR(t, h);
  }

  // Rota��o dupla � esquerda (direita-esquerda)
  if (balance < -1 && item < h->r->item) {
    h->r = rotR(t, h->r);
    return rotL(t, h);
  }

  return h;
}


int height(link x) {
    if (x == NULL) {
        return 0;
    }
    return x->N;
}

// Fun��o para calcular o fator de balanceamento de um n�
int getBalance(link x) {
    if (x == NULL) {
        return 0;
    }
    return height(x->l) - height(x->r);
}

// Fun��o para calcular o m�ximo entre dois n�meros inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}






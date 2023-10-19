#ifndef BST_H
#define BST_H


typedef struct node * link;
struct node {
  link l;
  link r;
  int item;
  int N;      // quantidade de nos na subarvore
  int id;     // id da nó
  int height //altura de nos na subarvore
};

typedef struct tree {
  link head; // raiz
  link z;    // nó externo
} * Tree;


link novoNo(int item, link l, link r);
Tree createTree();
link rotR(Tree t, link h);
link rotL(Tree t, link h);
int height(link x);
int size(link x);
link insertR(Tree t, link h, link n);
link insert(Tree t, int item);
link searchR(Tree t, link h, int query);
link search(Tree t, int query);
void imprimeEmOrdem(Tree t, link h);
void imprimePosOrdem(Tree t, link h);
void imprimePreOrdem(Tree t, link h, int k);
void printnode(char *x, int h);
void imprimeR(Tree a, link t);
void imprime(Tree a, char *s);
void imprimeFromNode(Tree a, link h, char *s);
link AVLinsert (Tree t,link h, int item);

 
#endif 



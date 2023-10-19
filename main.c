#include <stdio.h>
#include "bst.c"

int main () {
 Tree t = createTree();

  // Insira elementos na árvore AVL
  t->head = AVLinsertR(t,t->head,99);
  t->head = AVLinsertR(t,t->head,88);
  t->head = AVLinsertR(t,t->head,17);
  t->head = AVLinsertR(t,t->head,34);
  t->head = AVLinsertR(t,t->head,12);
  t->head = AVLinsertR(t,t->head,13);
  t->head = AVLinsertR(t,t->head,22);

  // Imprima a árvore AVL
  imprime(t, "arvore_avl");

  return 0;

  return 0;
}

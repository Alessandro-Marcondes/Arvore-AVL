#include <stdio.h>
#include "bst.h"

int main () {

   Tree avlTree = createTree();
	
	
	
	insert(avlTree, 90);
	insert(avlTree, 80);
	insert(avlTree, 70);
	insert(avlTree, 60);
	insert(avlTree, 50);
	insert(avlTree, 40);
	insert(avlTree, 30);
	insert(avlTree, 20);
	insert(avlTree, 10);
	insert(avlTree, 9);
	insert(avlTree, 8);
	insert(avlTree, 7);
	insert(avlTree, 6);
	
	
	
	
	
	imprime(avlTree,"Arvore_AVL");
	
	
  return 0;
}

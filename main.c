#include <stdio.h>
#include "bst.h"

int main () {

   Tree avlTree = createTree();
	
	
	
	insert(avlTree, 10);
	insert(avlTree, 5);
	insert(avlTree, 30);
	insert(avlTree, 25);
	insert(avlTree, 12);
	insert(avlTree, 32);
	insert(avlTree, 20);
	insert(avlTree, 24);
	insert(avlTree, 4);
	insert(avlTree, 7);
	insert(avlTree, 58);
	insert(avlTree, 13);
	imprime(avlTree,"oi");
	
	
  return 0;
}

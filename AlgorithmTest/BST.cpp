#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE{
	int data;
	
	struct _NODE *left;
	struct _NODE *right;
	
}NODE, *PNODE;

typedef struct _TREE{
	PNODE root;
	
	int size;
	
}TREE, *PTREE;

PNODE create_node(int data){
	PNODE node = (PNODE)malloc(sizeof(NODE));
	assert(node != NULL);
	
	node->data = data;
	node->left = node->right = NULL;
	
	return node;
}

void create_tree(PTREE tree, int data){
	tree->root = create_node(data);
	tree->size = 1;
}

void insert(PTREE tree, int data){
	assert(tree != NULL);
	
	PNODE curr = tree->root;
	
	while(curr){
		if(data > curr->data){
			if(curr->right == NULL){
				curr->right = create_node(data);
				tree->size++;
			}else{
				curr = curr->right;
			}
		}else if(data < curr->data){
			if(curr->left == NULL){
				curr->left = create_node(data);
				tree->size++;
			}else{
				curr = curr->left;
			}
		}else{
			break;
		}
	}
}

void preorder(PNODE root){
	if(root){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int get_size(PTREE tree){
	assert(tree != NULL);
	
	return tree->size;
}

bool find(PTREE tree, int data){
	assert(tree != NULL);
	
	PNODE curr = tree->root;
	
	while(curr){
		if(data > curr->data){
			curr = curr->right;
		}else if(data < curr->data){
			curr = curr->left;
		}else{
			return true;
		}
	}
	
	return false;
}

void test_tree(){
	TREE tree;

	create_tree(&tree, 0);

	for(int i=0; i<10; i++){
		insert(&tree, i);
	}

	preorder(tree.root);

	printf("\n%d", find(&tree, 5));
}

int main(){
	test_tree();
	
	return 0;
}

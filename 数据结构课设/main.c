#include <stdio.h>
#include <stdlib.h>
typedef char Data;
typedef struct Node {
	Data c;
	struct Node *left, *right;
} list;
// 注意：将指针作为参数传递其实是copy的一个副本，也就是对这个副本进行任何操作都不会影响被当做参数传递的指针.. 
void init_poi(list *poi) {
	// poi = (list*)malloc(sizeof(list));
	poi->c = '\0';
	poi->left = poi->right = NULL;
}
int main() {
//	list n1, n2, n3;
//	n1.c = 'A';
//	n2.c = 'B';
//	n3.c = 'C';
//	n1.left = &n2;
//	n1.right = &n3;
//	printf("%c %c %c ", n1.c, n1.left->c, n1.right->c);
	Data ch;
	list *head = NULL;
	list *now = NULL;
//	now = head;
//	now->left = next;
//	next->right = now;
//	// next == null;
//	now = next;
//	next = malloc
	head = (list*)(malloc(sizeof(list)));
	init_poi(head);
	now = head;
//	pre = head;
	// 思路：用一个next作为下一个节点，且下一个节点一定默认为空，然后now作为当前节点，且一开始为头结点
	// 然后每次输入一个字符，就是将now的右节点连到新分配的next上，再将next的左指针连到now上，然后将now
	// 更新为next，周而复返，即可连出一条双链表，比较难想的还是怎么使得下一个节点为新分配的节点并且当前
	// 节点能始终作为尾节点更新... 
	while (scanf("%c", &ch) != EOF) {
		if (ch == '\n' || ch == ' ') continue;
		list* next;
		next = (list*)(malloc(sizeof(list)));
		init_poi(next);
		next->c = ch;
		now->right = next;
		next->left = now;
		// 关键步骤，将now指向新分配内存的next，这样next就不会找不到了... 
		now = next;
		// printf("\n%p\n", &*next);
//		list *temp, *pre, *now;
//		init
//		temp->c = ch;
//		end = temp;
//		pre->right = end;
//		end->left = pre;
	}
	list *st = head->right;
	while (st) {
		printf("%c\n", st->c);
		st = st->right;
	}
	int i;
	// &temp 地址每次相同，&*temp 地址每次不同，temp本身是一个变量，也就是它的地址固定，但是它作为指针
	// 使用时指向的地址是会随malloc变化的.. 
//	for (i = 0; i < 3; i++) {
//		list *temp;
//		temp = (list*)(malloc(sizeof(list)));
//		//free(temp);
//		// temp->c = 'O';
//		printf("\n%p\n", &*temp);
//		// free(temp)实际上是把temp指向的地址的内存释放了，那么malloc每次去分配内存就会直接用上次的那个空间了... 
//		// free(temp);
//		
//	}
	
	return 0;
}

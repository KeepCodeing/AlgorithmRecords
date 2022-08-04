#include <stdio.h>
#include <stdlib.h>
typedef char Data;
typedef struct List {
	Data val;
	struct List *left, *right;
} LinkList;
int main() {
	Data c;
	LinkList head, list, pre;
	pre = head;
	// head = (LinkList*)malloc(sizeof(LinkList));
	// head.left = (LinkList*)malloc(sizeof(LinkList)), head.right = (LinkList*)malloc(sizeof(LinkList));
//	list->left = head, head->right = list, pre = list;
	while (~scanf("%c", &c)) {
		if (c == ' ' || c == '\n') continue;
		list.val = c;
		list.left = &pre, pre.right = &list, pre = list;

	}
	printf("%c", head.right->val);
	return 0;
}

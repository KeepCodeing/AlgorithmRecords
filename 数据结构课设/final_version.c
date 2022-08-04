#include <stdio.h>
#include <stdlib.h>
typedef char DATA;
DATA input;
typedef struct OwO {
	DATA val;
	struct OwO *left, *right;
} LinkedList;
LinkedList *head = NULL, *end = NULL;
LinkedList* init_node() {
	LinkedList *list;
	list = (LinkedList*)(malloc(sizeof(LinkedList)));
	list->val = '\0', list->left = list->right = NULL;
	return list;
}
void add_node() {
	LinkedList *next = init_node();
	next->val = input, end->right = next, next->left = end, end = next;
}
void clear_node() {
	while (head && end) {
		LinkedList *ht = head->right, *et = end->right;
		free(head), free(end);
		head = ht, end = et;
	}
}
void print_str(LinkedList *str) {
	while(str) printf("%c", str->val), str = str->right;
}
char* solve() {
	end->right = init_node();
	LinkedList *lf = head->right, *rt = end;
	print_str(lf);
	while (lf != rt) {
		if (lf->val != rt->val) return "is not a huiwen string!";
		lf = lf->right, rt = rt->left;
	}
	return "is a huiwen string!";
}
int main() {
	head = init_node(head), end = head;
	puts("Please input your string!(Enter ' ' or '\\n' to check result)");
	while(scanf("%c", &input) != EOF && input != '\n' && input != ' ') add_node();
	puts(solve());
	clear_node();
	return 0;
}

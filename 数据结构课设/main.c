#include <stdio.h>
#include <stdlib.h>
typedef char Data;
typedef struct Node {
	Data c;
	struct Node *left, *right;
} list;
// ע�⣺��ָ����Ϊ����������ʵ��copy��һ��������Ҳ���Ƕ�������������κβ���������Ӱ�챻�����������ݵ�ָ��.. 
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
	// ˼·����һ��next��Ϊ��һ���ڵ㣬����һ���ڵ�һ��Ĭ��Ϊ�գ�Ȼ��now��Ϊ��ǰ�ڵ㣬��һ��ʼΪͷ���
	// Ȼ��ÿ������һ���ַ������ǽ�now���ҽڵ������·����next�ϣ��ٽ�next����ָ������now�ϣ�Ȼ��now
	// ����Ϊnext���ܶ���������������һ��˫�����Ƚ�����Ļ�����ôʹ����һ���ڵ�Ϊ�·���Ľڵ㲢�ҵ�ǰ
	// �ڵ���ʼ����Ϊβ�ڵ����... 
	while (scanf("%c", &ch) != EOF) {
		if (ch == '\n' || ch == ' ') continue;
		list* next;
		next = (list*)(malloc(sizeof(list)));
		init_poi(next);
		next->c = ch;
		now->right = next;
		next->left = now;
		// �ؼ����裬��nowָ���·����ڴ��next������next�Ͳ����Ҳ�����... 
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
	// &temp ��ַÿ����ͬ��&*temp ��ַÿ�β�ͬ��temp������һ��������Ҳ�������ĵ�ַ�̶�����������Ϊָ��
	// ʹ��ʱָ��ĵ�ַ�ǻ���malloc�仯��.. 
//	for (i = 0; i < 3; i++) {
//		list *temp;
//		temp = (list*)(malloc(sizeof(list)));
//		//free(temp);
//		// temp->c = 'O';
//		printf("\n%p\n", &*temp);
//		// free(temp)ʵ�����ǰ�tempָ��ĵ�ַ���ڴ��ͷ��ˣ���ômallocÿ��ȥ�����ڴ�ͻ�ֱ�����ϴε��Ǹ��ռ���... 
//		// free(temp);
//		
//	}
	
	return 0;
}

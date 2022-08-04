#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

typedef int DATA;
DATA input;

typedef struct QAQ {
	DATA val;
	struct QAQ *left, *right;
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

const int MAX_LIST_SIZE = 5;

set<int > pro_pool; 
vector<int > pro_list;
map<int, QAQ > mp;

bool isElementUsed(int el) {
	return pro_pool.count(el) == 1; 
}

int main() {
	int el;
	while (cin >> el) {
		
	}
//	while (cin >> el) {
//		if (pro_list.size() <= MAX_LIST_SIZE) {
//			if (!isElementUsed(el)) {
//				pro_list.insert(pro_list.begin(), el); 
//				pro_pool.insert(el); 
//			} else {
//				
//			}
//		}
//	}
//	for (int i = 0; i < pro_list.size(); i++) cout << pro_list[i] << endl;
	return 0;
}

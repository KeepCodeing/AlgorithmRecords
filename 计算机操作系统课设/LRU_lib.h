#include <iostream>
#include <map>
using namespace std;

const int MAX_SIZE = 10;
int init_process[MAX_SIZE];

struct Node {
	int val;
	int left, right;
	Node(int v, int l, int r): val(v), left(l), right(r) {};
	Node() {};
};

map<int, Node > pro_map;

void printProcess(int h, int& cnt) {
	cout << "round: " << cnt << endl;
	int temp = h;
	while(pro_map[temp].right != -1) {
		cout << pro_map[temp].val << ' ';
		temp = pro_map[temp].right;
	}
	cout << pro_map[temp].val << endl;

	cnt++;
}

void deleteTailNode(int& e) {
	int temp = pro_map[pro_map[e].left].val;
	pro_map[temp].right = -1;
	pro_map.erase(e);
	e = temp;
}

void appendHeadNode(int& h, int val) {
	pro_map[val] = Node(val, -1, h);
	pro_map[h].left = val;
	h = val;
}

void updateNodeList(int val, int& h, int& e) {
	if (val == pro_map[h].val) {
		return;
	}
	if (val == pro_map[e].val) {
		deleteTailNode(e);
		appendHeadNode(h, val);
		return;
	}

	pro_map[pro_map[val].left].right = pro_map[pro_map[val].val].right;

	pro_map[pro_map[val].right].left = pro_map[pro_map[val].val].left;

	pro_map.erase(val);

	appendHeadNode(h, val);
}

void initNodeList(int max_size, int& h, int& e) {
	int l, r;
	cout << "input the max size of your process queue(max: 10):" << endl;
	cin >> max_size;
	if (max_size > MAX_SIZE) return;
	cout << "now, input your process' id:" << endl;
	for (int i = max_size - 1; i >= 0; i--) cin >> init_process[i];

	h = init_process[0], e = init_process[max_size - 1];

	for (int i = 0; i < max_size; i++) {
		l = i == 0 ? -1 : init_process[i - 1];
		r = i == max_size - 1 ? -1 : init_process[i + 1];
		pro_map[init_process[i]] = Node(init_process[i], l, r);
	}
}

void LRU() {
	int max_size, val, h, e, cnt = 0;

	initNodeList(max_size, h, e);

	printProcess(h, cnt);

	while(cin >> val) {

		if (!pro_map.count(val)) deleteTailNode(e), appendHeadNode(h, val);
		else updateNodeList(val, h, e);

		printProcess(h, cnt);
	}
}

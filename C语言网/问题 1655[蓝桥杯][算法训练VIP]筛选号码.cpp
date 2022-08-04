#include <iostream>
using namespace std;
const int N = 10010;
int head = -1, idx = 0, cnt = 0, e[N], ex[N];

void add_to_head(int x) {
	e[idx] = x;
	ex[idx] = head;
	head = idx++;
	cnt++;
}

void add(int k, int v) {
	e[idx] = v;
	ex[idx] = ex[k];
	ex[k] = idx++;
	cnt++;
}

void rem(int k) {
	ex[k] = ex[ex[k]];
	cnt--;
}
// 谔谔，发现不会循环链表，但是写单链表的时候好像也写错了点地方，谔谔 
int main() {
	int n;
	cin >> n;
	// 头结点传入的是值，不是下标 
	add_to_head(1);
	// 第一个下标从0开始 
	for (int i = 2; i <= n; i++) add(i - 2, i);
	int st = 0;
	while (cnt != 1) {
		head = ex[head];
		st++;
		if (!(st % 3)) {
			st = 0;
			rem(e[])
		}
	}
	return 0;
}

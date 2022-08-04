#include <iostream>
using namespace std;
const int N = 5100;
struct Node {
	int l, r;
	char c;
	bool flag;
} root[N];
int n;
string str;
void pushup(int now, int left, int right) {
	int zcnt = 0, ocnt = 0;
	// 注意这里线段树根节点从1开始，但是字符串下标从0开始.. 
	for (int i = left - 1; i <= right - 1; i++) {
		if (str[i] == '0') zcnt++;
		else ocnt++;
	}
	// 三种情况，没有0，没有1，或者两者都有.. 
	if (!ocnt) root[now].c = 'B';
	else if (!zcnt) root[now].c = 'I';
	else root[now].c = 'F'; 
}
void build(int now, int left, int right) {
	// 注意这里给用到的节点加了标记，方便待会后序遍历判断是否存在节点 
	root[now].l = left, root[now].r = right, root[now].flag = true;
	if (left == right) {
		// 叶子节点非0即1 
		root[now].c = str[left - 1] == '0' ? 'B' : 'I';
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	// 和普通线段pushup有所区别，这里不是求区间和之类的东西，而是求区间内有多少个0和1，所以要把当前区间给传进去 
	pushup(now, left, right);
}
void pre_order(int now) {
	if (!root[now].flag) return;
	pre_order(now << 1);
	pre_order(now << 1 | 1);
	cout << root[now].c;
}
int main() {
	cin >> n >> str;
	int sLen = str.size();
	// 题目描述有坑w，应该是2^n，不是2*n... 
	build(1, 1, sLen);
	pre_order(1);
	return 0;
}

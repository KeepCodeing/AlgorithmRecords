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
	// ע�������߶������ڵ��1��ʼ�������ַ����±��0��ʼ.. 
	for (int i = left - 1; i <= right - 1; i++) {
		if (str[i] == '0') zcnt++;
		else ocnt++;
	}
	// ���������û��0��û��1���������߶���.. 
	if (!ocnt) root[now].c = 'B';
	else if (!zcnt) root[now].c = 'I';
	else root[now].c = 'F'; 
}
void build(int now, int left, int right) {
	// ע��������õ��Ľڵ���˱�ǣ���������������ж��Ƿ���ڽڵ� 
	root[now].l = left, root[now].r = right, root[now].flag = true;
	if (left == right) {
		// Ҷ�ӽڵ��0��1 
		root[now].c = str[left - 1] == '0' ? 'B' : 'I';
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	// ����ͨ�߶�pushup�����������ﲻ���������֮��Ķ������������������ж��ٸ�0��1������Ҫ�ѵ�ǰ���������ȥ 
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
	// ��Ŀ�����п�w��Ӧ����2^n������2*n... 
	build(1, 1, sLen);
	pre_order(1);
	return 0;
}

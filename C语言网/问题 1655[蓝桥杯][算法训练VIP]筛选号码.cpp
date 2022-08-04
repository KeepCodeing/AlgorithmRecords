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
// ���̣����ֲ���ѭ����������д�������ʱ�����Ҳд���˵�ط������� 
int main() {
	int n;
	cin >> n;
	// ͷ��㴫�����ֵ�������±� 
	add_to_head(1);
	// ��һ���±��0��ʼ 
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

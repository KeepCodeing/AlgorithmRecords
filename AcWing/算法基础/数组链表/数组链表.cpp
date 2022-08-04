#include <iostream>
using namespace std;
const int N = 100010;

// head��ʾͷ�����±�
// e��ʾ�ڵ�i��ֵ
// ne��ʾ�ڵ�i��nextָ���Ƕ���
// idx�洢��ǰ�Ѿ��õ����Ǹ��� 
int head, e[N], ne[N], idx;

// ��ʼ�� 
void initList() {
	head = -1, idx = 0;
}

// ��x���뵽ͷ��� 
void add_to_head(int x) {
	// ���Ȱ�����㴴������ 
	e[idx] = x;
	// Ȼ�������ڵ����һ���ڵ㣨����ָ��ָ��head 
	ne[idx] = head;
	// ����ڵ�ͳ�Ϊ���µ�ͷ��㣬����ִ��ͷ��������ͻ��
	// ����ڵ㿪ʼ���� 
	head = idx;
	// ʹ�õĽڵ������� 
	idx++;
	// 2 -> 1 -> head... 
}
// ��x���뵽�±�Ϊk�Ľڵ�� 
void add(int k, int x) {
	// ͬ���ȴ���������ڵ� 
	e[idx] = x;
	// Ȼ������ڵ�ָ��k����Ľڵ� 
	ne[idx] = ne[k];
	// �ٽ�kָ������ڵ� 
	ne[k] = idx;
	idx++;
}
// ���±�Ϊk�Ľڵ�����һ���ڵ�ɾ�� 
void remove(int k) {
	// ɾ�������ýڵ�k����k+1���ڵ�ֱ��ָ��k+2���ڵ�
	// ����Ĳ�������ȡ��kָ�����һ���ڵ���±꣬Ȼ��
	// ��kָ������ڵ�ָ��Ľڵ㣬������k+1���ڵ� 
	ne[k] = ne[ne[k]];
}
int main() {
	initList();
	int n;
	cin >> n;
	char code;
	int x, y;
	while (n--) {
		cin >> code;
		if (code == 'H') {
			cin >> x;
			add_to_head(x);
		} else if (code == 'D') {
			cin >> x;
			// ɾ��ͷ��������ͷ���ָ����һ���ڵ� 
			if (!x) head = ne[head];
			else
			// �ڵ��0��ʼ����������Ҫ-1 
			remove(x - 1);
		} else {
			cin >> x >> y;
			add(x - 1, y);
		}
	}
	while (head != -1) {
		cout << e[head] << ' ';
		head = ne[head];
	}
	return 0;
}
/*
����������

10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6

���������

6 4 6 5
*/

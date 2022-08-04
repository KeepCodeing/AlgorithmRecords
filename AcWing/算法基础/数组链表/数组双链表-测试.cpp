#include <iostream>
using namespace std;
const int N = 100010;
int e[N], l[N], r[N];
int idx;

void add(int k, int x) {
	// ��������Ӳ���һ��Ҫ�ϸ���������ҵ�˳���� 
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx;
	idx++;
}

void remove(int k) {
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}
int main() {
	r[0] = 1, l[1] = 0;
	// ע�������±��2��ʼ����Ϊͷβ��ռ��һ��λ�� 
	idx = 2;
	int n;
	cin >> n;
	int x, y;
	while (n--) {
		string code;
		cin >> code >> x;
		if (code == "L") {
			// ������˲��룬Ҳ����ζ���Ǵ�ͷ������
			add(0, x); 
		} else if (code == "R") {
			// �����ұ߲���ֻ��Ҫ��������˵�Ԫ�أ�ͷ��㣩���ɣ���Ϊ
			// ͷ���������β��㣨���Ҷ˵�Ԫ�أ� 
			add(l[1], x);
		} else if (code == "D") {
			// �±��2��ʼ�����Ի�Ҫ+1 
			remove(x + 1);
		} else if (code == "IL") {
			cin >> y;
			// �������ȵ��ҵ��������ߵ�Ԫ�أ�Ȼ����ͨ����ߵ�Ԫ�ص��Ҳ���
			// �ﵽ�����Ԫ��������Ч������ΪaddĬ�����Ҳ��룩 
			add(l[x + 1], y);
		} else {
			cin >> y;
			// �Ҳ����ֱ�Ӵ������λ�ü��ɣ��͵�����һ�� 
			add(x + 1, y);
		}
	}
	int head = r[0];
	// ע���������õ���ֹ�������ǵ�rightָ����1Ϊֹ 
	while (head != 1) {
		cout << e[head] << ' ';
		head = r[head];
	}
	return 0;
}

/*
����������
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
���������
8 7 7 3 2 9
*/

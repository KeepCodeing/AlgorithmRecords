#include <iostream>
using namespace std;
int *arr;
bool *choose;
// �Ӽ����⣺����һ�����ϣ�Ҫ�������ȫ���Ӽ�

// �������ݹ鷨��������ɶ���������ѡ���״̬ѡ��ֻ��2����
// �����Ԫ�غ�û�����Ԫ�أ���һ�����ߵ�ͷ��Ȼ�����һ�������ߵ�ͷ...Ҳ���ǻ��ݷ���
// �������Ϊ���ϵ�ѹջ��ջ�Ĺ��� 
void printZiji(int len) {
	for (int i = 0; i < len; i++) {
		if (choose[i]) {
			cout << arr[i] << ' ';
		}
	}
	cout << endl;
}
void ziji(int level, int len) {
	if (level >= len) {
		printZiji(len);
		return;
	}
	choose[level] = true;
	ziji(level + 1, len);
	choose[level] = false;
	ziji(level + 1, len);
}
int main() {
	int n;
	cin >> n;
	arr = new int[n]();
	choose = new bool[n];
	for (int i = 0; i < n; i++) arr[i] = i + 1;
	ziji(0, n);
	delete[] choose;
	delete[] arr;
	return 0;
}

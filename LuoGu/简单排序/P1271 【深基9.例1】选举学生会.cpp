#include <iostream>
using namespace std;

// ����������򣬵��ǻ���Ҫע�⣬����������Ͱ�ţ�
// �����Ϊʲô���˸�����n��ԭ�� 

int *bucket;
int main() {
	int n, m, temp;
	// mֻ��ͶƱ���������Ǻ�ѡ������������m <= n 
	cin >> n >> m;
	bucket = new int[n + 1]();
	for (int i = 0; i < m; i++) {
		cin >> temp;
		bucket[temp]++;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < bucket[i]; j++) {
			cout << i;
			cout << ' ';
		}
	}
	delete[] bucket;
	return 0;
}

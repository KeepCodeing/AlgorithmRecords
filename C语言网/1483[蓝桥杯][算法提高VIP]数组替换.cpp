#include <iostream>
using namespace std;

// �ӵ��������ж�a�����ж��ٸ�Ԫ�أ����û�и��õİ취
// ������Ȼ�����¾��� 

void  Add(int a[], int m, int b[], int n) {
	int s = 1;
	// ��Ϊ˵�Ǵ�a[m]��ʼ��b[n]�滻�����Խ�n��Ԫ�����λ������� 
	while (s <= n) a[m++] = b[s++];
}
int *a, *b;
int main() {
	int m, n;
	cin >> m >> n;
	a = new int[m + n + 5]();
	b = new int[n + 5]();
	// ���a������������ֵ��˵������ûԪ���� 
	fill(a, a + m + n + 5, 0x3FFFFFFF);
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int start, end;
	cin >> start >> end;
	// ��������������start + 1 
	Add(a, start + 1, b, end);
	int t = 1;
	// ͳ��a�����ж��ٸ�Ԫ�� 
	while(a[t] != 0x3FFFFFFF) t++;
	// �������
	for (int i = 1; i <= t - 1; i++) {
		cout << a[i];
		if (i != t - 1) cout << ',';
	}
	delete[] a, b;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

// �����������ж����г��ȼ��� 

int *a, *b; 
int main() {
	int n;
	cin >> n;
	a = new int[n], b = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			cout << "NE";
			delete[] a, b;
			return 0;
		}
	}
	cout << "DA";
	delete[] a, b;
	return 0;
}

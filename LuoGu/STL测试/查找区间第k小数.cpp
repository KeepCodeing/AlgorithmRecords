#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int a[15] = {1, 2, 5, 7, 3, 4, 1};
	// nth_element(�����䣬k�������䣩�����Խ�[l,r)�е�kС��������k���λ�ã����Ӷ�O(n) 
	//for (int i = 0; i < 7; i++) nth_element(a, a + i, a + 7), cout << a[i] << endl;
	nth_element(a + 5, a + 1, a + 7);
	cout << a[5];
	return 0;
}

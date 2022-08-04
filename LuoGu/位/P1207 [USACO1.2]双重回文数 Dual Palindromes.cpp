#include <iostream>
using namespace std;

// ��Ҫ��������ģ��̳�����k���� 

// ת������+�ж��Ƿ��ǻ��ĵĺ��� 
bool isPrime(int n, int k) {
	int res[35], index = 0;
	// ����ת�������Ǹ����ģ���������ν����Ϊ����
	// ���ǶԳƵģ�������������ø�˫ָ���ж��� 
	while (n) {
		res[index++] = n % k;
		n /= k;
	}
	// ����ʮ���Ƶ��������Բ��ÿ�����ĸʲô�� 
	// for (int i = index - 1; i >= 0; i--) cout << res[i];
	int left = 0, right = index - 1;
	while (left < right) {
		if (res[left++] != res[right--]) return false;
	}
	return true;
}
int main() {
	int n, s, cnt;
	cin >> n >> s;
	while (true) {
		if (n <= 0) break;
		s++, cnt = 0;
		for (int i = 2; i <= 10; i++) {
			if (isPrime(s, i)) cnt++;
		}
		// �����˫�ػ����������������n 
		if (cnt >= 2) cout << s << endl, n--;
	}
	return 0;
}

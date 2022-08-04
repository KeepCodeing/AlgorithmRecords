#include <iostream>
#include <cmath>
using namespace std;

// Ͱ�ż��ж���������Ϊ���ݷ�ΧС������ֻ��Ҫ�ж�һ��
// ���������Կ��Բ�������ɸ 
// ��Ŀû���꣬�����������Ӧ�����0 

int arr[26];
bool isPrime(int num) {
	if (num < 2) return false;
	int k = (int)sqrt((double)num);
	for (int i = 2; i <= k; i++) {
		if (num % i == 0) return false;
	}
	return true;
}
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 'a']++;
	}
	int maxCnt = -1, minCnt = 101;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) continue;
		if (arr[i] > maxCnt ) maxCnt = arr[i];
		if (arr[i] < minCnt) minCnt = arr[i];
	}
	if (isPrime(maxCnt - minCnt)) cout << "Lucky Word" << endl << maxCnt - minCnt;
	else cout << "No Answer" << endl << 0;
	return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

// 桶排加判断素数，因为数据范围小，而且只需要判断一次
// 素数，所以可以不用素数筛 
// 题目没看完，如果不是素数应该输出0 

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

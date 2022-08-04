#include <iostream>
using namespace std;

// 蓝桥杯，真有你的，开始刷枚举/暴力的题力 

int bucket[100];
int main() {
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				bucket[i + j + k]++;
			}
		}
	} 
	int maxCnt = -1, index;
	for (int i = 1; i < 100; i++) {
		if (bucket[i] > maxCnt) {
			maxCnt = bucket[i];
			index = i;
		}
	}
	cout << index;
	return 0;
}

#include <iostream>
using namespace std;
int *road;
int main() {
	// 从0开始计数 
	int len, cnt, result = 0;
	cin >> len >> cnt;
	road = new int[len + 1]();
	int start, end;
	for (int i = 1; i <= cnt; i++) {
		cin >> start >> end;
		for(int j = start; j <= end; j++) {
			// 防止重复标记
			if (road[j] == 0) road[j] = 1;
		}
	}
	// 主要的bug还是把起点当成1了，审题不仔细 
	for (int i = 0; i <= len; i++) {
		if (road[i] == 1) continue;
		result += 1;
	}
	cout << result;
}

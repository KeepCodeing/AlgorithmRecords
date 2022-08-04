#include <iostream>
using namespace std;
int main() {
	int LEN = 5;
	int arr[LEN][LEN];
	int temp = 1;
	// 初始化数组 
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			arr[i][j] = temp;
			temp++;
		}
	}
	// 打印数组(不想写了（无能）） 
	
	return 0;
}

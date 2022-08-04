#include <iostream>
using namespace std;
const int LEN = 5;
void printArr(int arr[LEN][LEN]) {
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
void clearZero(int arr[LEN][LEN]) {
	// 思路：记录有0的行和列的下标
	 int temp[LEN][2];
	 int index = 0;
	 for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			if (arr[i][j] == 0) {
				// 行 
				temp[index][0] = i;
				// 列 
				temp[index][1] = j;
				index++;
			}
		}
	}
	for (int i = 0; i < index; i++) {
		int line = temp[i][0];
		int column = temp[i][1];
		for (int n = 0; n < LEN; n++) arr[line][n] = 0;
		for(int j = 0; j < LEN; j++) arr[j][column] = 0;
	}
}
int main() {
	
	int arr[LEN][LEN];
	int temp = 1;
	// 初始化数组 
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			arr[i][j] = temp;
			temp++;
		}
	}
	// printArr(arr);
	arr[3][4] = 0;
	arr[1][2] = 0;
	printArr(arr);
	clearZero(arr);
	printArr(arr);
	return 0;
} 

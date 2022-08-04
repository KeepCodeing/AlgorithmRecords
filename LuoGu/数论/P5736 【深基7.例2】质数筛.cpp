#include <iostream>
using namespace std;

// 再次复习埃氏筛 
// 不过这题没必要 

int *arr;
bool li[100005];
void sai() {
	li[0] = li[1] = true;
	for (int i = 2; i <= 100000; i++) {
		if (!li[i]) {
				for (int j = i * 2; j <= 100000; j += i) {
				li[j] = true;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sai();
	for (int i = 0; i < n; i++) {
		if (!li[arr[i]]) cout << arr[i] << ' ';
		
	}
	delete[] arr;
	return 0;
}

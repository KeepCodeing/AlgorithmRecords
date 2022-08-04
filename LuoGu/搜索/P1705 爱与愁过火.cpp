#include <iostream>
using namespace std;

// ˮ...����������Ŷ�����������֦�ᳬʱ 

int cnt = 0;
void dfs(int level, int deepth, int arr[], int sumNum, int n, int r, int c) {
	if (c == r) {
		if (sumNum > n) cnt++;
		return;
	}
	// ���ʣ�µĲ˲���r�֣�ֱ�ӷ���
	if (deepth - level + 1 < r - c) return;
	// �����ǰ�˼��Ѿ�������n������ֱ��ͳ��ʣ�·���
	if (sumNum > n) {
		int can = 1, left = deepth - level + 1;
		for (int i = 1; i <= r - c; i++) {
			can *= (left - i + 1) / i;
		}
		cnt += can; 
		return;
	} 
	for (int i = level; i <= deepth; i++) {
		dfs(i + 1, deepth, arr, sumNum + arr[i], n, r, c + 1);
	}
}
int main() {
	int m, r, n;
	cin >> m >> r >> n;
	int *arr = new int[m + 1];
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
	}
	dfs(1, m, arr, 0, n, r, 0);
	cout << cnt;
	delete[] arr;
	return 0;
}

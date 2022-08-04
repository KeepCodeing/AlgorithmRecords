#include <iostream>
using namespace std;
int nums[105][105];
int maxSum[105][105];
// ���仯 
int visited[105][105];
int n;

// ˼·�����ж�ѡ���µĴ������µĴ� 

int rec(int i, int j) {
	if (visited[i][j] != -1) return visited[i][j];
	// ������Ͳ��û����ѡ�ˣ����ֵ�������� 
	if (i == n - 1) {
		visited[i][j] = nums[i][j];
	} else {
		visited[i][j] = max(rec(i + 1, j), rec(i + 1, j + 1)) + nums[i][j];
	}
	return visited[i][j];
	// ѡ���µ��� 
//	int x = rec(i + 1, j);
//	// ѡ���µ��� 
//	int y = rec(i + 1, j + 1);
//	// �ж����Ž� 
//	return max(x, y) + nums[i][j];
} 

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> nums[i][j];
			visited[i][j] = -1;
		}
	}
	// ��ȵݹ�д�������� 
	// ����д��:���������ƣ���������ʼ�±�Ϊ1��ʡȥ�ܶ��鷳... 
	for (int i = 0; i < n; i++) maxSum[n - 1][i] = nums[n - 1][i];
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + nums[i][j];
		}
	} 
	cout << maxSum[0][0];
	return 0;
}

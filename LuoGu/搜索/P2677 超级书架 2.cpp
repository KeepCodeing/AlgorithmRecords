#include <iostream>
using namespace std;

// һ����Ϊ�Ǹ�̰���⣬�������.. 

int *arr;
int minHight = 1145141919;
void dfs(int level, int deepth, int hight, int SumH) {
	// ����ûд�� 
	// ������һֱ�����ڲ�κ���ȵ�ѡ���ϣ��������һ��Ҫ�������ֶ����ϵĻ���һ���ܵõ����Ž�
	// ��֮����̫����ģ���� 
	// level == deepth + 1 || 
	if (SumH >= hight) {
		minHight = min(minHight, SumH);
		// if (hight < minHight && hight >= 0) minHight = hight;
		return;
	}
	for (int i = level; i <= deepth; i++) {
		dfs(i + 1, deepth, hight, SumH + arr[i]);
	}
}

int main() {
	int n, b;
	cin >> n >> b;
	arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, n - 1, b, 0);
	cout << minHight - b;
	delete[] arr;
	return 0;
}

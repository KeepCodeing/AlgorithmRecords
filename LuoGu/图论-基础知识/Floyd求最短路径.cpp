#include <iostream>
using namespace std;

// ����㷨���ǽ�����һ��������ʹ·�����̣�����Ч�ʺܵͣ�ֻ��O(n^3)��������������
// ʵ�� ������Floyd�㷨�����������и�Ȩ�ߵ�ͼ��Ҳ��������1->2->3->1->2->3...����
// �໥��ͨ��ͼ 

int graph[1000][1000]; 

int main() {
	// ��ʼ��ͼ 
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = -1;
			else graph[i][j] = 0;
		}
	} 
	int x, y, w;
	while(m--) {
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
	// Floyd���Ĵ��룺����ѭ��
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// ����м��k��j����i��k�Ϸ����ж�ֱ�Ӵ�i��j�Ƿ���ڽ����м��k��������ڣ���
				// ������̾��� 
				// ���ﻹ���Լ򻯣������ǲ��ܵ����õĲ���-1����inf��������min()��������� 
				// if
				if (graph[i][k] != -1 && graph[k][j] != -1 && graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	} 
	return 0;
}

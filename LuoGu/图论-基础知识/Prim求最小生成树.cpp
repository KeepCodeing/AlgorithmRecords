#include <iostream>
#include <cstring>
using namespace std;

// �������е�����Dijkstra�����·�������������õ���̰��˼�룬ÿ��
// ѡ��ѡ�������С�ĵ㣬Prim�㷨��Ҫ���ö�������С���� 

// Prim�㷨���̸���������㷨��Dijkstra�㷨������ֻ࣬�������µ�������
// ���ȣ�ͬ�����ҵ�һ������㣬ͬʱ��¼�����Ĵ��ۣ�Ȼ����������㣬ȥ
// ȥ�������������Ƿ��д��۴�������㵽��������ͨ�㣬����У����� 

#define N 6
#define INF 114514
int dist[N];
bool visited[N];
int graph[N][N] = { {INF,7,4,INF,INF,INF},   //INF��������֮�䲻�ɴ�
                    {7,INF,6,2,INF,4}, 
                    {4,6,INF,INF,9,8}, 
                    {INF,2,INF,INF,INF,7}, 
                    {INF,INF,9,INF,INF,1}, 
                    {INF,4,8,7,1,INF}
                  };

int prim(int cur) {
	int index, sumMoney = 0;
	memset(visited, false, sizeof(visited));
	cout << cur << ' ';
	visited[cur] = true;
	for (int i = 0; i < N; i++) {
		// ��ʼ����ǰ����Ե���ĵ�ľ��� 
		dist[i] = graph[cur][i];
	}
	for (int i = 1; i < N; i++) {
		int minMoney = INF;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && dist[j] < minMoney) {
				// �ҵ��뵱ǰ������ĵ㣬��������С�����Լ��������±� 
				index = j;
				minMoney = dist[j];
			}
		}
		// ʹ������� 
		visited[index] = true;
		cout << index << ' ';
		sumMoney += minMoney;
		// �ӵ�ǰ���ܵ�������㿪ʼ��չ��Ҳ���ǻ����㿪ʼ���� 
		for (int j = 0; j < N; j++) {
			// ����ʼ�㵽j��ķ���С���ѵĵ����Ϊ��ǰ�����Ļ��� 
			if (!visited[j] && dist[j] > graph[index][j]) {
				dist[j] = graph[index][j];
			}
		}
	}
	cout << endl;
	return sumMoney;
}

int main() {
	cout << prim(0) << endl;
	return 0;
}

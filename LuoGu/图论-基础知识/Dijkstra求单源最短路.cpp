#include <iostream>
using namespace std;

// ��Դ���·����ָһ���ڵ㵽�����ڵ����Сֵ 
// Dijkstra���ȶ���Դ���·�㷨 

int graph[1000][1000], dis[1000], visited[1000];
int n, m;
// ע�⣬����֮ǰ͵����-1������inf�������������ƺ���Щ���� 
int inf = 114514;

// Dijkstra�㷨���̸�����ÿ�ζ��ھ��������в�ѯ����Ľڵ㣬Ȼ�����������Сֵȥ����
// �������飬���¼����жϾ����������Ƿ��о���ȵ�ǰ��̾���ڵ㵽����ͨ������ڵ���������
// ��������͸���ֵ 

void Dijkstra() {
	// ��ʼ��dis���飬�������ĳ���ڵ㵽�������нڵ����̾���
	// �����dis�����ʼ��Ϊ�˽ڵ�1���������нڵ�ľ��� 
	for (int i = 1; i <= n; i++) dis[i] = graph[1][i];
	// ��ʼ��visited���� 
	for (int i = 1; i <= n; i++) visited[i] = 0;
	// ��1�㿪ʼ�ɳ� 
	visited[1] = 1;
	// Dijkstra�㷨�������
	int minDis, u;
	for (int i = 1; i <= n - 1; i++) {
		// ��ǰ���ҵ������·�� 
		minDis = inf;
		// �ҵ���1�Ŷ�������Ľڵ�
		for (int j = 1; j <= n; j++) {
			// ���������priority_queue�����Ż���Ҫ��С���� 
			if (!visited[j] && dis[j] < minDis) {
				minDis = dis[j];
				// ��¼��̾���ڵ���±� 
				u = j;
			}
		}
		// ��Ŀǰ�ҵ������·������Ϊ�Է��� 
		visited[u] = 1;
		// ������ǰ���·�� 
		for (int v = 1; v <= n; v++) {
			// �������е㣬���ж�������̵㵽�����Ϸ���ľ����Ƿ��ܸ��� 
			if (graph[u][v] < inf) {
				// �ӵ�ǰ��̾��������ɳڲ���������u��v����̾�����жԱ� 
				if (dis[v] > dis[u] + graph[u][v]) dis[v] = dis[u] + graph[u][v];
			}
		} 
	} 
}

int main() {
	
	cin >> n >> m;
	// ��ʼ��ͼ 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) graph[i][j] = inf;
			else graph[i][j] = 0;
		}
	}
	int x, y, w;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
	Dijkstra();
	// ������ 
	for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
 	return 0;
}
/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/

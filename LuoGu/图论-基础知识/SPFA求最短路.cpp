#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define inf 0x3f3f3f3f

// ����㷨����Bellman-Ford�Ķ����Ż��汾��Ч�ʸ��ߣ��е���������ѣ�����������Բ���
// ���һ��Ԫ�أ�������ڸ�Ȩ�ߵ�ͼ��ʵû�����·�� 
// SPFA��һ�����ȶ�������·������Ϊ�䲻�϶�һ������ӿ��ܵ��¸��Ӷ����������һ��
// �������������� 

struct node {
	int y, z;
	// ע���ʼ����ʽ��������ʼ���ƺ���(node){y, z}��ʱ���������� 
	node(int a, int b) : y(a), z(b){};
	// ������ʼ������y��z����0 
//	node(int a = 0, int b = 0) {
//		y = a, b = z;
//	}
};
// ͼ�Ĵ�С���Լ����� 
int n, m;
// ���ڽӱ��ͼ��������m<n^2����� 
vector<node > graph[1000];
// ���� 
queue<int > que;
// ������Ž���������Լ���Ƿ��ʵ����� ���м�¼
// ��Ӵ��������飬��Ϊ�и�Ȩ�ߵ�ͼspfa�������� 
int dist[1000], visited[1000], enter_cnt[1000];

void spfa(int cur) {
	// ��ʼ��visited�����enter_cnt���� 
	// for (int i = 1; i <= n; i++) visited[i] = enter_cnt[i] = 0;
	// �Լ����Լ��ľ���Ϊ0 
	dist[cur] = 0;
	// ��ӣ���BFS���� 
	que.push(cur);
	// ����Է��� 
	visited[cur] = 1; 
	// curԪ����Ӵ�������
	enter_cnt[cur]++;
	
	int x;
	while(!que.empty()) {
		x = que.front();
		que.pop();
		// �����б߽��б��� 
		for (int i = 0; i < graph[x].size(); i++) {
			// �����ɳڣ�����ǰ������ϸñ�������һ��Ԫ�ص�Ȩֵ�ȸñ�ֱ�ӵ���һ���ߵ�
			// ȨֵСʱ�ͽ����ɳڣ�������б߶��ɳ����ˣ�����ͽ����� 
			if (dist[x] + graph[x][i].z < dist[graph[x][i].y]) {
				dist[graph[x][i].y] = dist[x] + graph[x][i].z;
				// ���δ���ʹ����Ե�ǰ�������п��Ե���ĵ��������ɳ� 
				if (!visited[graph[x][i].y]) {
					que.push(graph[x][i].y);
					enter_cnt[graph[x][i].y]++;
					// ��������ڸ�Ȩ�ߣ���ÿ���ڵ㶼�����ܱ�����n�����ϣ�
					// ��������˸�Ȩ�ߣ�spfa�޷�����ֱ�ӷ��� 
					if (enter_cnt[graph[x][i].y] >= n) {
						cout << "ERROR!" << endl;
						return;
					}
					// ��Ƿ��ʹ� 
					visited[graph[x][i].y] = 1;
				}
			}
		}
	} 
} 
/*
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
0 -3 -1 2 4

5 7
1 2 3
1 3 2
2 4 1
4 1 4
4 3 6
4 5 4
5 3 4
0 3 2 4 8
*/

int main() {
	int x, y, z;
	cin >> n >> m;
	// ��ʼ��������飬��Ȼȫ�ֱ���Ĭ��Ϊ0
	for (int i = 1; i <= n; i++) dist[i] = inf;
	for (int i = 1; i <= m; i++) {
		// x->y,z��Ȩֵ 
		cin >> x >> y >> z;
		// ��������ͼ 
		graph[x].push_back((node){y, z}); 
		// Ҫ��������ͼ��һ��{z,y}���� 
	}
	// ���� 
	spfa(1); 
	for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	return 0;
} 

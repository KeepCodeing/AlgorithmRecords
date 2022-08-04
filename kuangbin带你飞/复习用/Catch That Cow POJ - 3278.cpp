#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// BFSö��״̬ 
// һ˲д�꣬�����Ǽ���Ҫö��״̬��BFS֮�������������������ôд�ˣ�
// ֮ǰ�б�����֮�ӣ���Ϊ��ʱ��������֪��ö�ٵ���״̬... 

const int N = 100000 * 2 + 10;
// ��Ϊ��֪���ж�����״̬�����ø�queue�������� 
queue<int > que;
int dist[N];
int bfs(int n, int k) {
	memset(dist, -1, sizeof dist);
	dist[n] = 0;
	que.push(n);
	while (que.size()) {
		int now = que.front();que.pop();
		if (now == k) return dist[now];
		if (now + 1 < N && dist[now + 1] == -1) {
			dist[now + 1] = dist[now] + 1;
			que.push(now + 1);
		}
		if (now - 1 >= 0 && dist[now - 1] == -1) {
			dist[now - 1] = dist[now] + 1;
			que.push(now - 1);
		}
		if (now * 2 < N && dist[now * 2] == -1) {
			dist[now * 2] = dist[now] + 1;
			que.push(now * 2);
		}
	}
	return 0;
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k);
	return 0;
}

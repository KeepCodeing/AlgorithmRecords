#include <iostream>
#include <cstring>
using namespace std;

// �������⣬��������������أ��͵���ϰ����... 
// ���ò���ˣ���Ҫ�ǳ�ʼֵ�����ã����з��ʷ������.. 

int n, k;
const int N =  100000 * 2 + 10;
int que[N];
int dist[N];
int bfs() {
	// ȫ������Ϊһ��һ��ʼ�����ڵ�ֵ����֮ǰ���õľ���0������0����һ��ʼ����... 
	memset(dist, -1, sizeof dist);
	int qtop = 0, qback = 0;
	que[qtop] = n;
	dist[n] = 0;
	while (qtop <= qback) {
		int now = que[qtop++];
		if (now == k) return dist[now];
		// �����ж��ܲ������жϵ�����һ���㣬�����ǵ�ǰ��... 
		if (now + 1 < N && dist[now + 1] == -1) {
			dist[now + 1] = dist[now] + 1;
			que[++qback] = now + 1; 
		}
		if (now - 1 >= 0 && dist[now - 1] == -1) {
			dist[now - 1] = dist[now] + 1;
			que[++qback] = now - 1;
		}
		if ( now * 2 < N && dist[now * 2] == -1) {
			dist[now * 2] = dist[now] + 1;
			que[++qback] = now * 2;
		}
	}
}
int main() {
	cin >> n >> k;
	cout << bfs();
	return 0;
}

#include <iostream>
using namespace std;
// ��������鿪��������Ϊx * 2�����߷����ֻ��һ�������Ļ����߲���ģ���������Ҫ��������֤����
// �߷������� 
const int N = 1e5 * 2 + 10;
int que[N], dist[N];
int bfs(int x, int y) {
	fill(dist, dist + N, -1);
	int qtop = 0, qback = 0;
	que[qtop] = x;
	dist[x] = 0;
	// �ܵ���˵�����ס������⣨������˵���w�� 
	while (qtop <= qback) {
		int t = que[qtop++];
		if (t == y) return dist[t];
		// t + 1�������ڲ���ĳ��δ���ʾ�˵�������ߣ�������ж�ͬ�� 
		if (t + 1 < N && dist[t + 1] == -1) {
			dist[t + 1] = dist[t] + 1;
			que[++qback] = t + 1;
		}
		if (t - 1 >= 0 && dist[t - 1] == -1)  {
			dist[t - 1] = dist[t] + 1;
			que[++qback] = t - 1;
		}
		if (t * 2 < N && dist[t * 2] == -1) {
			dist[t * 2] = dist[t] + 1;
			que[++qback] = t * 2;
		}
	}
	return -1;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		// �����ı��㼼�ɣ����򻻺� 
		cout << bfs(x, y) << endl;
	}
	return 0;
}

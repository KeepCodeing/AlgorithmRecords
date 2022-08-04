#include <iostream>
using namespace std;

// ������������ۣ�
// 1. ʲôʱ���һ����ũ�������x����N֮�ھͿ���ִ�м�һ����
// 2. ʲôʱ���һ��ֻҪ��ũ�������x>0���ܽ��м�һ����
// 3. ʲôʱ��˶���ֻҪ��ũ�������x*2<N�Ϳ���ִ�г˶�����

// ʲôʱ���˳�BFS
// ��ũ������x����ţ������ʱ����

// ��μ��㲽������һ��dist������ÿ�β��������Ĳ�������ǰ�����͵����ϴβ�����һ 

// ��������Ϊ�˷�ֹ�˶�����Խ�� 
const int N = 2e5 + 10;
int n, k;
int que[N], dist[N];
int bfs() {
	int qtop = 0, qback = 0;
	// �Լ����Լ��ľ���Ϊ0 
	fill(dist, dist + N, -1);
	dist[n] = 0;
	// �ӵ�ǰ�㿪ʼ��չ 
	que[0] = n;
	while (qtop <= qback) {
		int t = que[qtop++];
		// ����ҵ��˴𰸣�ֱ�ӷ��ؾ��� 
		if (t == k) return dist[t];
		// ��dist�����ž���ͬʱ�ж�ĳ���ڵ��Ƿ���ʹ� 
		if (t + 1 < N && dist[t + 1] == -1) {
			// ��ǰ�ڵ�ľ�������ϸ��ڵ�ľ���+1 
			dist[t + 1] = dist[t] + 1;
			// �´δ�����㿪ʼ��չ 
			que[++qback] = t + 1;
		}
		if (t - 1 >= 0 && dist[t - 1] == -1) {
			dist[t - 1] = dist[t] + 1;
			que[++qback] = t - 1;
		} 
		if (t * 2 < N && dist[t * 2] == -1) {
			dist[t * 2] = dist[t] + 1;
			que[++qback] = t * 2;
		}
	}
	return 0;
}
int main() {
	cin >> n >> k;
	cout << bfs();
	return 0;
} 

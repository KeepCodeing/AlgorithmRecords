#include <iostream>
#include <map>

using namespace std;

// Ȼ������������...���������Ǹ�ץţ���⣬������BFS�����· 
// �������Ͱ�Ų����ܴ������е㣬���Կ��Կ�����map������ɢ�� 

// 70�֣�û������.... 

typedef unsigned long long LL;
const int mod = 1000000007, out = 100000;
map<LL, int > dist;
LL que[out + 10];
int bfs(int start) {
	dist[start] = 0;
	int qtop = 0, qback = 0;
	que[qtop] = start;
	while (qtop <= qback) {
		LL now = que[qtop++];
		if (qtop > out + 10) return -1;
		if (!(now % mod)) return dist[now];
		int nx1 = (now * 4 + 3) % mod, nx2 = (now * 8 + 7) % mod;
		if (!dist.count(nx1)) dist[nx1] = dist[now] + 1, que[++qback] = nx1;
		if (!dist.count(nx2)) dist[nx2] = dist[now] + 1, que[++qback] = nx2;
	}
}
int main() {
	LL start;
	cin >> start;
	cout << bfs(start);
	return 0;
} 

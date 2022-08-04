#include <iostream>
#include <cstdio>
using namespace std;
const int N = 310, INF = 0x3fffffff;
int graph[N][N];
int pos[N];
void init_graph(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}
}
int main() {
	int n, m, cnt;
	scanf("%d%d", &n, &m);
	init_graph(n);
	// ��ͼ 
	while (m--) {
		scanf("%d", &cnt);
		for (int i = 1; i <= cnt; i++) scanf("%d", &pos[i]);
		// ���� 
		for (int i = 1; i <= cnt; i++) {
			for (int j = i + 1; j <= cnt; j++) {
				// ˫��ߣ�ö�����п������ߵĵ㣬���붼Ϊ1����Ŀ����������ʵ����˵��Щ���бߣ���
				// ��ͬ����������ָ�ľ�������û��ֱ�������ĵ�ı߾�Ϊ1+1+..+1.. 
				graph[pos[i]][pos[j]] = 1;
				graph[pos[j]][pos[i]] = 1;
			}
		}
	}

	// floyd���ӣ�����n�������ж������������һ��ÿ���㶼�б�.. 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	} 
	// ͳ�ƴ𰸣�ע��������ƽ��ֵҪֱ����intȡ����������ܳ���
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && graph[i][j] != INF) tot += graph[i][j];
		}
		// ����Ӧ���ȳ���100�ٳ�ȥ��������Ϊ���붼��С�������1/100�ͻ�õ�0 
		ans = min(ans, (tot * 100 / (n - 1)));
	} 
	printf("%d", ans);
	return 0;
}

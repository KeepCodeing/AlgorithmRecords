#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// Ӳ�װ˻ʺ��˼����������w���������Բ��ü�¼��һ�б����ˣ�ֻҪ����
// ÿ�ζ�ֱ�������߾����ˣ�Ҳ����ֻ�ü�¼��һ�б����ˣ���ô����ĳ�����
// ѭ��������... 
// ������̬��ը�����������Ŀû������.. 

const int N = 10;
int n, m;
long long cnt;
bool graph[N][N];
bool visited[N];
void dfs(int y, int m) {
	if (!m) {
		cnt++;
		return;
	}
	// ֱ�Ӵ���һ�п�ʼ... 
	for (int i = y + 1; i <= n; i++) {
		// ö����һ�е���һ�е����зŷ� 
		for (int j = 1; j <= n; j++) {
			// �����ǰ�����ܷ����Ӳ�����һ��û�з����ӣ��ͼ���������.. 
			if (graph[i][j] && !visited[j]) {
				visited[j] = true;
				dfs(i, m - 1);
				visited[j] = false;
			} 
		}
	}
}
int main() {
	char temp;
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == -1 && m == -1) break;
		memset(visited, 0, sizeof visited);
		memset(graph, 0, sizeof graph);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> temp;
				// ��Ŀ��#���ǿ��Է����ӵĵط�... 
				graph[i][j] = (temp == '#');
			}
		}
		// ������ֱ�Ӵӵ�һ�п�ʼ������������������Ϊ��0��.. 
		dfs(0, m);
		printf("%lld\n", cnt);
	}
	return 0;
}

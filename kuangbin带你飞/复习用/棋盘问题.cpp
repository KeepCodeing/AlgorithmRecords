#include <iostream>
using namespace std;
const int N = 10;
char graph[N][N];
bool visited[N];
int res;
void dfs(int level, int n, int cnt, int mx) {
	if (cnt == mx) {
		res++;
		return;
	}
	// ֱ�ӱ�֤�´δ���һ�п�ʼ�������о;��Բ����ظ� 
	for (int i = level; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// ��Ŀ˵�������ж���������ͬ���ӣ�����ֻ��������.. 
			if (graph[i][j] == '#' && !visited[j]) {
//				graph[i][j] = '.'; ����ƺ�ûʲô��...
				// �ѵ�ǰ��һ�б�ǣ���ֹ�ߵ�ͬһ������... 
				visited[j] = true;
				dfs(i + 1, n, cnt + 1, mx);
//				graph[i][j] = '#';
				visited[j] = false;
			}
		}
	}
}
int main() {
	int n, k;
	while (cin >> n >> k, n != -1)  {
		res = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) cin >> graph[i][j];
		dfs(0, n, 0, k); 
		cout << res << endl;
	} 
	 
	return 0;
}

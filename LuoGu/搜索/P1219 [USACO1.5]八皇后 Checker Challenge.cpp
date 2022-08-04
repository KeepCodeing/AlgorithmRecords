#include <iostream>
using namespace std;
int n;
// ���鿪��㣬��Ȼ����磨��֪��Ϊʲô����nxn��С�ĵ�ͼ�� 
// ���о���ֻ�ñ���һά��״̬... 
bool graph[100][100], col[100], dg[100], udg[100];
int cnt = 0;
void dfs(int y) {
	if (y == n) {
		if (cnt < 3) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][j]) {
						cout << j + 1 << ' ';
						break;
					}
				}
			}
			cout << endl;
		}
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!graph[y][i]) {
			if (!col[i] && !dg[y + i] && !udg[n - y + i]) {
				col[i] = dg[y + i] = udg[n - y + i] = true;
				graph[y][i] = true;
				dfs(y + 1);
				graph[y][i] = false;
				col[i] = dg[y + i] = udg[n - y + i] = false;
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	dfs(0);
	cout << cnt;
	return 0;
} 

#include <iostream>
#include <vector>
using namespace std;

// 数据范围100，这意味着我们可以用Floyd求，而且题目没给出明确的起始点 

int graph[110][110];
// 必须要走的数组的大小开小了... 
int must[100010];
int n, m;

int main() {
	cin >> n >> m;
	// int x;
	for (int i = 1; i <= m; i++) cin >> must[i];
	int x; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			graph[i][j] = x;
		}
	}
	// Floyd，三行循环，最外层是中间点，要计算的就是min(j~k, j~i + i~k); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				// 自己到自己的距离是0，要特判下 
				if (i != j && i != k && j != k) {
					graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
				}
			}
		}
	} 
	int ans = 0;
	for (int i = 2; i <= m; i++) {
		// 必须要走的点，这句话的意思就是前一个点到后一个点的距离累加 
		ans += graph[must[i - 1]][must[i]];
	}
	cout << ans;
	return 0;
}

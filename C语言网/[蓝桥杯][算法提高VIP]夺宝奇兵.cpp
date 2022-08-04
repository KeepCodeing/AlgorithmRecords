#include <iostream>
#include <cstdio>
using namespace std;
const int N = 110;
int graph[N][N];
int f[N][N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) f[n][i] = graph[n][i];
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + graph[i][j];
		}
	} 
	printf("%d", f[1][1]);
	return 0;
}

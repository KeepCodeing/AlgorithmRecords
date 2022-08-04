#include <iostream>
using namespace std;
int graph[30][30];
int main() {
	int n;
	cin >> n;
	graph[1][1] = 1;
	graph[2][1] = 1, graph[2][2] = 1;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			graph[i][j] = graph[i - 1][j]
		}
	}
	return 0;
}

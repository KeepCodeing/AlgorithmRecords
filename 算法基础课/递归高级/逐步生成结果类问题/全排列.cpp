#include <iostream>
using namespace std;
int *result, *visited;
void printArr(int len) {
	for (int i = 1; i <= len; i++) cout << result[i] << ' ';
	cout << endl;
}
void dfs(int level, int deepth) {
	if (level >= deepth + 1) {
		printArr(deepth);
		return;
	}
	for (int i = 1; i<= deepth; i++) {
		if (visited[i]) continue;
		result[level] = i;
		visited[i] = 1;
		dfs(level + 1, deepth);
		visited[i] = 0;
	}
	
}
int main() {
	int n;
	cin >> n;
	result = new int[n + 1];
	visited = new int[n + 1]();
	dfs(1, n);
	return 0;
}

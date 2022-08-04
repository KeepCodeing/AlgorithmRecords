#include <iostream>
#include <cstdio> 
using namespace std;

// 可以用STL写(忘了），也可以自己写 

void printArr(int arr[], int n) {
	for (int i = 1; i <= n; i++) {
		printf("%5d", arr[i]);
	}
	printf("\n");
}

void dfs(int level, int deepth, int arr[], bool visited[]) {
	if (level == deepth + 1) {
		printArr(arr, deepth);
		return;
	}
	for (int i = 1; i <= deepth; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[level] = i;
			dfs(level + 1, deepth, arr, visited);
			visited[i] = false;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int *arr;
	bool *visited;
	arr = new int[n + 1]();
	visited = new bool[n + 1]();
	
	dfs(1, n, arr, visited);
	
	delete[] arr, visited;
	return 0;
}

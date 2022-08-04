#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

// 剪枝 

int cnt = 0;
void dfs(int level, int deepth, string str, bool visited[], string r) {
	if (level == deepth) {
		// 据说printf比cin快...（然而printf不能输出string类...） 
		cout << r << endl;
		cnt++;
		return;
	} 
	char pre = str[0] - 1;
	for (int i = 0; i < deepth; i++) {
		if (!visited[i] && pre != str[i]) {
			visited[i] = true;
			dfs(level + 1, deepth, str, visited, r + str[i]);
			pre = str[i];
			visited[i] = false;
		}
	}
}
int main() {
	int n;
	bool *visited;
	string str;
	cin >> n;
	cin >> str;
	visited = new bool[n];
	// 忘了sort，不然没法去重 
	sort(str.begin(), str.end());
	dfs(0, n, str, visited, "");
	cout << cnt;
	delete[] visited;
	return 0;
}

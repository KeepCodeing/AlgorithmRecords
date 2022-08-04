#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

// ��֦ 

int cnt = 0;
void dfs(int level, int deepth, string str, bool visited[], string r) {
	if (level == deepth) {
		// ��˵printf��cin��...��Ȼ��printf�������string��...�� 
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
	// ����sort����Ȼû��ȥ�� 
	sort(str.begin(), str.end());
	dfs(0, n, str, visited, "");
	cout << cnt;
	delete[] visited;
	return 0;
}

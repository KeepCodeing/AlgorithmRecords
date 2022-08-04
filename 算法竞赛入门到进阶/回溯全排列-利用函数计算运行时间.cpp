#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// 啊这...万恶之源

void dfs(int level, int deepth, vector<int >& v, bool visited[]) {
	if (level == deepth + 1) {
//		for (int i = 0; i < v.size(); i++) {
//			cout << v[i] << ' ';
//		}
//		cout << endl;
		return;
	}
	for (int i = 1; i <= deepth; i++) {
		if (!visited[i]) {
			v.push_back(i);
			visited[i] = true;
			dfs(level + 1, deepth, v, visited);
			v.pop_back(); 
			visited[i] = false;
		}
	}
} 
int main() {
	vector<int > v;
	int len;
	cin >> len;
	bool *visited = new bool[len + 1]();
	// 测试运行时间
	clock_t start, end;
	start = clock(); 
	dfs(1, len, v, visited);	
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	delete[] visited;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int x, y;
	Node(int x, int y) : x(x), y(y) {};
};
char graph[105][105];
bool visited[105][105];
bool res[105][105];
string words = "yizhong";
int n;
vector<Node > path;
void dfs(int x, int y, int index, string str) {
	if (x < 0 || x > n || y < 0 || y > n) return;
	if (index > 7) return;
	if (graph[x][y] != words[index]) return;
	// 之前池沼了，把这里写成了7，回头一想index是从0开始的... 
	if (str == words) {
//		for (int i = 0; i < path.size(); i++) {
//			cout << path[i].x << ' ' << path[i].y << endl;
//		}
//		cout << "----------" << endl;
//		res.push_back(path); 
		//str += graph[x][y];
		//if (str == words) {
		path.push_back((Node){x, y});
		for (int i = 0; i < path.size(); i++) res[path[i].x][path[i].y] = true;		
		//}
		return;
	}
	if (/*graph[x][y] != '*'&& */!visited[x][y]) {
		// char temp = graph[x][y];
		visited[x][y] = true;
		//graph[x][y] = '*';
		path.push_back((Node){x, y});
		dfs(x - 1, y - 1, index + 1, str + graph[x][y]);
		dfs(x - 1, y, index + 1, str + graph[x][y]);
		dfs(x - 1, y + 1, index + 1, str + graph[x][y]);
		dfs(x, y - 1, index + 1, str + graph[x][y]);
		dfs(x, y + 1, index + 1, str + graph[x][y]);
		dfs(x + 1, y - 1, index + 1, str + graph[x][y]);
		dfs(x + 1, y, index + 1, str + graph[x][y]);	
		dfs(x + 1, y + 1, index + 1, str + graph[x][y]);
		path.pop_back();
		// visited[x][y] = false;
		// graph[x][y] = temp;
	}
	
}

int main() {
	cin >> n;
	for (int i = 0;  i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0;  i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(i, j, 0, "");
		}
	}
	for (int i = 0;  i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (res[i][j]) cout << graph[i][j];
			else cout << '*';
		}
		cout << endl;
	}
	return 0;
}

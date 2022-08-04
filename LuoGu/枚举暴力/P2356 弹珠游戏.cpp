#include <iostream>
#include <vector>
using namespace std;

// 感觉也可以用DFS来做（想了下应该不行，因为这个题是从一个点发散） 

struct Node {
	int x, y;
	Node (int x, int y) : x(x), y(y){};
	
};
vector<Node > vec;
int graph[1005][1005];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
			if (!graph[i][j]) {
				vec.push_back((Node){i, j});
			}
		}
	}
	int maxScore = -1;
	if (!vec.size()) {
		cout << "Bad Game!";
	} else {
		Node temp(0, 0);
		int tScore;
		for (int i = 0; i < vec.size(); i++) {
			temp = vec[i];
			tScore = 0;
			for (int i = 1; i <= n; i++) {
				tScore += graph[temp.x][i];
				tScore += graph[i][temp.y];
			}
			maxScore = max(maxScore, tScore);
		}
		cout << maxScore;
	}
	return 0;
}

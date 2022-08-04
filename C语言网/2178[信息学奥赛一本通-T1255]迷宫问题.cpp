#include <iostream>
#include <vector>
using namespace std;
// ��Ϊֻ��0��1���������ɧ���� 
struct Node {
	int x, y;
	Node (int x, int y) : x(x), y(y) {};
};
int minStep = 0x3FFFFFFF;
bool graph[7][7];
vector<Node > vec;
vector<Node > res;
void dfs(int x, int y, int step) {
	// ϲ���ּ��ļ�֦ 
	if (step >= minStep) return;
	if (x < 0 || x >= 5 || y < 0 || y >= 5) return;
	if (graph[x][y]) return;
	if (x == 4 && y == 4) {
		// �Ž����������������ʱ�����࣬������Ҳû�취��DFS���¼���·�� 
		res.clear();
		// û�뵽ʸ������ֱ�Ӹ�ֵ��STL IS GOD 
		res = vec;
		// ÿ�ζ�����һ����Сֵ���ټ���ǰ��ļ�֦�������޳��������·���� 
		minStep = min(minStep, step);
		return;
	}
	// ����߹����Լ����·�� 
	graph[x][y] = true;
	vec.push_back((Node){x, y});
	dfs(x + 1, y, step + 1);
	dfs(x - 1, y, step + 1);
	dfs(x, y + 1, step + 1);
	dfs(x, y - 1, step + 1);
	vec.pop_back();
	graph[x][y] = false;
}
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> graph[i][j];
		}
	}
	dfs(0, 0, 0);
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) {
		cout << '(' << res[i].x << ", " << res[i].y << ')' << endl;
	}
	// �յ㵥�������������Ҫע������,���пո��... 
	cout << '(' << 4 << ", " << 4 << ')';
	return 0;
} 

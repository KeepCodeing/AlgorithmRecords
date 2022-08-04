#include <iostream>
#include <vector>
using namespace std;

// ֮ǰ̫naive�ò��鼯д�˸���������ֲ��鼯�������ж�����ͼ����ͨ��...
// Ȼ������������strat��֪����ô�㣬�������۲�֪��ԭ������ֻ�Ǳ�
// �����Լ�����ȥ��������̫��vector�ı��������������ܻ����...

// ��̱�ˣ�������ͷ�ڵ�û�г�ʼ����Ȼ��TLE����ʼ������д���˽�ͼ֮��w
// Ȼ���ִ𰸻��ǲ��ԣ������۽�ͼ��e[idx] = vtд��e[vt] = idx...

// Ȼ����LeetCode�����������⣨������ 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
bool visited[N];
class Solution {
public:
	void add(int ut, int vt) {
		e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
	}
    bool findWhetherExistsPath(int n, vector<vector<int> >& graph, int start, int target) {
		// �ѵ��ת��Ϊͼ
		int gLen = graph.size();
		if (!gLen) return false;
		fill(head, head + N, -1);
		for (int i = 0; i < gLen; i++) add(graph[i][0], graph[i][1]);
		bool flag = false;
		dfs(start, target, flag);
		return flag;
    }
    void dfs(int cur, int ed, bool& flag) {
    	if (cur == ed) {
    		flag = true;
    		return;
		}
		visited[cur] = true;
		for (int i = head[cur]; i != -1; i = ex[i]) {
			int vt = e[i];
			if (!visited[vt]) dfs(vt, ed, flag);
		}
	}
}; 

int main() {
	return 0;
}

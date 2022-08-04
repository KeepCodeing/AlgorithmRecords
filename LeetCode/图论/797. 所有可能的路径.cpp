#include <iostream>
#include <vector> 
using namespace std;

// ���DFS����ĿҪ��ڵ�˳�����ֵ���ʵ���ϻ��ݾ����� 
// ��������Ļ���û��visited��ǣ������Ǻ�ѡ��֮��Ļ���һ������һ�ξʹ���һ���ڵ㿪ʼ�ˣ�Ҳ����
// ����Ϊ���Ǹ������޻�ͼ��Ҳ��������һ���ڵ����ֻ�ᱻ����һ�Σ�Ȼ�����ߵ�n-1�����֮��ʼ����... 

class Solution {
public:
	vector<vector<int > > res;
	// 0�����ֱ��Ĭ�ϼӽ�ȥ���� 
	vector<int > path{0};
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
		dfs(graph, 0, graph.size());
		return res;
    }
    void dfs(vector<vector<int > >& graph, int cur, int n) {
    	if (cur == n - 1) {
    		res.push_back(path);
			return; 
		}
		// dfs���ݣ����Լ�visited���Ҳ���Բ��ӣ���Ϊ���ͼ���޻�������ͼ
		// �������������б� 
		for (int i = 0; i < graph[cur].size(); i++) {
			// ȡ��������ܵ����Ǹ��� 
			path.push_back(graph[cur][i]);
			// �´δ�������������������pop_back()�ǻ��ݵĻ������� 
			dfs(graph, graph[cur][i], n);
			path.pop_back(); 
		}
	}
};

int main() {
	return 0;
}

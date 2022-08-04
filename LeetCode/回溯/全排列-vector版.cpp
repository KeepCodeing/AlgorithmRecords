#include <iostream>
#include <vector>
using namespace std;
// ��vectorʵ��һ��ȫ���У��������ظ� 
class Solution {
public:
	vector<vector<int > > result;
	vector<int > temp;
	bool *visited;
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		// ����涨��1��ʼ 
		for (int i = 1; i <= deepth; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			temp.push_back(i);
			// ��������Կ�����ȫ��������Ӽ����������ȫ������ǿ������ÿһ��Ԫ��
			// ���Ӽ�����ǿ������ÿ��ѡ���Ԫ�أ�ȫ������һ���ǻ����ȫ������Ż�����
			// һ���⣬���Ӽ�������ܵݹ�����ÿһ��·������һ���⡣ 
			dfs(level + 1, deepth);
			visited[i] = false;
			temp.pop_back();
		}
	}
	vector<vector<int > > qpl(int n) {
		if (n == 0) return result;
		// ע�⶯̬����ռ������ĳ�ʼ�����⣬��������г�ʼ�����ܻᵼ�´��� 
		visited = new bool[n]();
		dfs(0, n);
		delete[] visited;
		return result;
	}
};
int main() {
	Solution s = Solution();
	vector<vector<int > > result = s.qpl(3); 
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

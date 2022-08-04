#include <iostream>
#include <vector>
using namespace std;
// �����ǰ�����Ȼ����ͬһʱ�䣬������ͬһIDE����8���ٴθ���ұ���һ��ȫ���У��������ֵ���д��

// ȫ����Ϊʲô������level+1?����ͼ���ܿ��������ײ��Ҷ�ӽڵ���ǽ��������ѡ�񲢲���ѡһ��
// ��һ��������ѡһ����һ�������Դ�����level���������͵�����ѡһ����һ�������Դ��ĵ�i+1 
class Solution {
public:
	vector<vector<int> > result;
	void dfs(int level, int deepth, vector<int >& temp, vector<int>& nums, bool visited[]) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		for (int i = 0; i < deepth; i++) {
			if (!visited[i]) {
				visited[i] = true;
				temp.push_back(nums[i]);
				dfs(level + 1, deepth, temp, nums, visited);
				visited[i] = false;
				temp.pop_back(); 
			}
		}
	}
    vector<vector<int> > permute(vector<int>& nums) {
        if (nums.size() == 0 || nums.empty()) return result;
        vector<int> temp;
        // ע���ʼ�� 
        bool *visited = new bool[nums.size()]();
        dfs(0, nums.size(), temp, nums, visited);
        delete[] visited;
        return result;
    }
}; 

int main() {
	Solution s = Solution();
	vector<int > v;
	vector<vector<int > > r;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	r = s.permute(v); 
	for (int i = 0; i < r.size(); i++) {
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
} 

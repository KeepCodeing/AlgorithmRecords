#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �������������Ҫ���Ǽ�֦�����⣬�ο������۽�𣬶������ظ�Ԫ�ص����ļ�֦��ſ��Է�Ϊ
// ������1.�����ظ�Ԫ�ص������������2.����һ��������¼�ϴεݹ�Ľڵ�ֵ���ڵ�ǰ�ݹ��ж�
// ��ǰԪ���Ƿ�����ϴεݹ��Ԫ�أ���Ϊ�Ѿ������ˣ�����һ�����������ַ���ȥ�أ����������
// ˵�����������ķ�֧���ظ��ģ�������������ǰ�ݹ� 

// ����������ƺ�Ҳ����ֱ����setȥ�أ�Ȼ��Ч�ʼ��ͣ������� 

// ������ȫ����д��Ҳ����һֱ������д����ͬ��֮ǰ��д��û��vector������û�취ȥ��β��Ԫ��
// �⵼�����ĳ������ʱresult���±��õ���level������vector�±�дi���С� 
 
class Solution {
public:
	vector<vector<int> > result;
	vector<int > temp;
	vector<int > nums;
	int *visited;
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp);
			return; 
		}
		// һ��ʼ��� pre ֵ����������������û�г��ֵģ�����±߽� - 1 �������ϱ߽� + 1������
        // ����������� int ���͵����ֵ������Сֵ�����ܻ�������⣬����������û�м�������
		int pre = nums[0] - 1;
		for (int i = 0; i < deepth; i++) {
			// ������֦������ʹ�ù���������һ���ڵ��ظ� 
			if (visited[i] || nums[i] == pre) continue;
			visited[i] = 1;
			// ��ӽ� 
			temp.push_back(nums[i]);
			dfs(level + 1, deepth);
			visited[i] = 0;
			// ����pre��ֵ
			pre = nums[i]; 
			temp.pop_back(); 
		}
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return result;
        // ���򣬷����֦ 
        sort(nums.begin(), nums.end());
        int nLen = nums.size();
        this->nums = nums;
        visited = new int[nLen]();
        dfs(0, nLen);
        return result;
    }
};
int main() {
	Solution s = Solution();
	vector<int > t;
	t.push_back(1);
	t.push_back(1);
	t.push_back(2);
	vector<vector<int > > re;
	re = s.permuteUnique(t); 
	for (int i = 0; i < re.size(); i++) {
		for (int j = 0; j < re[i].size(); j++) {
			cout << re[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

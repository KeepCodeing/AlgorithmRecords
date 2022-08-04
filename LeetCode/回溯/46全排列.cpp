#include <iostream>
#include <vector>
using namespace std;
// ���������û����㷨����ȫ���м��ɣ�ע�������Ǹ���һ�����飬������Ԫ�ظ���
// ���Ի��ݵĲ���Ӧ�������鳤�ȣ���Ԫ��������Ԫ��
class Solution {
public:
	vector<vector<int> > result;
	void arrange(int start, int level, int visited[], vector<int>& nums, int arr[]) {
		if (start >= level + 1) {
			vector<int > temp;
			for (int i = 0; i <= level; i++) {
				temp.push_back(arr[i]);
				// cout << arr[i] << ' ';
			}
			result.push_back(temp);
			// cout << endl;
			return;
		}
		for (int i = 0; i <= level; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			arr[start] = nums[i];
			arrange(start + 1, level, visited, nums, arr);
			visited[i] = 0;
		}
	}
    vector<vector<int> > permute(vector<int>& nums) {
    	int vLen = nums.size();
    	// ���ֻ��һ��Ԫ�ػ�û��ԭ�ط��ظ�Ԫ�������� 
    	if (vLen <= 1) {
    		result.push_back(nums);
    		return result;
		}
		int *visited = new int[vLen]();
		int *arr = new int[vLen]();
		arrange(0, vLen - 1, visited, nums, arr);
		delete[] visited, arr;
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<int > v;
	int t;
	while (cin >> t) {
		v.push_back(t);
	}
	s.permute(v);
	return 0;
}

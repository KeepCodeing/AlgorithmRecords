#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ���ɺ���д�������ˣ���θ�����ao�˵㣬��ҪҲ�Ǹ�ȥ�ص����⣬����֮ǰ��vector���ַ�����ʵ��̫�� 

// ����...���������Ǹ��Ӽ����͵��⣬��֮ǰ�������ж�д�������������Ϊ���ԭ�� 

// ���ۣ���֪��Ϊʲô��ͨ���ݻ�ò��˵�һ��Ԫ�أ����Ӽ��������ֵ��鷳�� 

// �ݣ����׹�٣�Ч�ʼ��͵�м�㷨 

class Solution {
public:
	int result = 0;
	bool isAlphaUsed(string t) {
		for (int i = 0; i < t.size(); i++) {
			if (count(t.begin(), t.end(), t[i]) > 1) return true;
		}
		return false;
	}
	void dfs(int level, int deepth, vector<string>& arr, string t) {

		if (result < t.size() && !isAlphaUsed(t)) result = t.size();

		for (int i = level; i < deepth; i++) {
			dfs(i + 1, deepth, arr, t + arr[i]);
		}
	}
    int maxLength(vector<string>& arr) {
        if (arr.size() == 0 || arr.empty()) return 0;
        dfs(0, arr.size(), arr, "");
        return result;
    }
};

int main() {
	Solution s = Solution();
	vector<string > arr;
	arr.push_back("yy");
	arr.push_back("bkhwmpbiisbldzknpm");
//	arr.push_back("jnfbyktlrqumowxd"); 
//	arr.push_back("mvhgcpxnjzrdei"); 
//	arr.push_back("ue"); 
//	arr.push_back("un"); 
//	arr.push_back("iq"); 
	cout << s.maxLength(arr); 
	return 0;
}

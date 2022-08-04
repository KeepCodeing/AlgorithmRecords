#include <iostream>
#include <vector>
using namespace std;

// ˮ��w�����Ѿ�������
// ���ű������ˣ���ʱ����������д�����ˣ����ڵ���û��ô�룬����Ҳ�е㲻�˽�Ϊʲô�ĸо�... 

class Solution {
public:
	vector<string > res;
	void dfs(int left, int right, string str) {
		if (!left && !right) {
			res.push_back(str);
			return; 
		}
		// ���������ţ��������������������� 
		if (left > 0) dfs(left - 1, right, str + "(");
		// �������ţ�����Ҫע�������ŵ�����Ҫ�������Ŷ࣬��Ȼ�������������ַ��� 
		if (right > 0 && left < right) dfs(left, right - 1, str + ")");
	}
	
    vector<string> generateParenthesis(int n) {
    	if (!n) return res;
		dfs(n, n, "");
		return res;
    }
}; 

int main() {
	return 0;
}

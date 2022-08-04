#include <iostream>
#include <vector>
using namespace std;
// ���ݣ��ӵ�ǰλ��ʼ���������ַ���ÿ����һλ���ж����ǲ��ǻ����ַ���
class Solution {
public:
	vector<vector<string> > result;
	vector<string > temp;
	string str;
	bool isHuiWen(int start, int end) {
		int left = start, right = end;
		while (left < right) {
			if (str[left++] != str[right--]) return false;
		}
		return true;
	}
	void dfs(int level, int deepth) {
		if (level == deepth) {
			result.push_back(temp); 
			return; 
		}
		for (int i = level; i < deepth; i++) {
			// ���۵����˵ֱ�ӽ�ȡ���ַ����Ƚ�����ʱ�䣬��������ͨ���±�+˫ָ��Ա��Ƿ��ǻ���
			// �ַ��� 
			if (!isHuiWen(level, i)) {
				// ����level��i������ͬ�ģ���Ϊ���ݵĹ�����level�ỹԭ
				// Ҳ����˵�����ڻ��ݵĹ������ж��Ѿ�ѡ�˵��ַ����Ƿ��ǻ����ַ� 
				continue;
			}
			// ע������֮ǰд���� str.substr(level, i + 1)��������һ��������c++��
			// substrӦ���Ǵӵ�ǰ�ַ���ʼ���nλ��ȡ������Ҫд������ 
			// һ��ʼ�ǰѵ�ǰλ��ȡ�ˣ��ڻ��ݵĹ����о��ǰѵ�ǰλ������λ���ν�ȡ 
			temp.push_back(str.substr(level, i - level + 1)); 
			dfs(i + 1, deepth);
			temp.pop_back();
		}
	}
    vector<vector<string> > partition(string s) {
    	if (s.size() <= 0) return result;
    	this->str = s;
        dfs(0, s.size());
        return result;
    }
}; 
int main() {
	Solution s = Solution();
	vector<vector<string> > v = s.partition("aab"); 
	for (int i = 0; i < v.size(); i++) {
		for (int n = 0; n < v[i].size(); n++) {
			cout << v[i][n] << ' ';
		}
		cout << endl;
	}
	return 0;
}

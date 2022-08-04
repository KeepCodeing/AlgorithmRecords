#include <iostream>
#include <vector>
#include <set>
using namespace std;
// ��������Ҫ��ȥ�ز��������˵ݹ������ٺ���Ŀ�����Ĵ𰸶Աȿ��Կ�������ǵ�����
// ��һ����һ����ʽ�Ļ����ɵĴ𰸾Ͳ���ȷ����ȷ�Ĵ�Ӧ��������һ��������ʣ�µ�
// ���������ȫ���о��е����ƣ����ù���Ԫ�ر�ǣ�����ʱ�ж��Ƿ����ù���Ԫ�أ���
// ���ݵĳ��ھ�������Ԫ�ض������� 

// �����ĳ��ڶ�����ٸ�����һ����ʾ����ʱ��𰸲���Ҷ�ӽڵ㣬�������ϵ����нڵ�
// �����������͵����������Ӽ����͵ģ���֮���������͵���Ĵ𰸾ͺܿ�����Ҷ�ӽڵ� 
class Solution {
public:
	int *visited;
	vector<char > v;
	string str;
	set<string > strSet;
	void dfs(int left, int deepth) {
		// �������Ӵ𰸵ĳ��ھ��ǻ�ʣ�ַ� 
		if (left) {
			string s;
			for (int i = 0; i < v.size(); i++) s += v[i];
			// �ų����ַ� 
			if (!s.empty()) strSet.insert(s);
			// �����أ����ֱ�ӷ��ؾ�û�к����ݹ��� 
			// return;
		}
		for (int i = 0; i < deepth; i++) {
			if (visited[i]) continue;
			visited[i] = 1;
			v.push_back(str[i]);
			dfs(left - 1, deepth);
			v.pop_back();
			visited[i] = 0;
		}
	}
    int numTilePossibilities(string tiles) {
        if (tiles.size() == 0 || tiles.empty()) return 0;
        int tLen = tiles.size();
        visited = new int[tLen]();
        this->str = tiles;
        dfs(tLen + 1, tLen);
        return strSet.size();
    }
};

int main() {
	Solution s = Solution();
	cout << s.numTilePossibilities("AAB"); 
	return 0;
}

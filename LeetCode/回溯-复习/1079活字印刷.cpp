#include <iostream>
#include <vector>
#include <set>
using namespace std;

// �������������һ��������������⣿�����ǿ������� 

// ����...����û˼·���������ǿ�ͼ�������Ǹ��Ӽ��������⣬���ǻ���ûʲô�Ż���
// ����ö�������Կ��ܣ� һ����˵�������ⶼ��ѡһ����һ��������������ƺ�����
// Ԫ�ض������ظ�ʹ�ã���AAB��ABA��������Ҫ�Ǹ�ʹ�÷�����⣬���е����������
// ȫ���� 

class Solution {
public:
	set<string > result;
	void dfs(int level, int deepth, string str, bool visited[], string t) {
		if (result.count(t)) return;
		if (!t.empty()) result.insert(t);
		for (int i = 0; i < deepth; i++) {
			if (!visited[i]) {
				visited[i] = true;
				dfs(i + 1, deepth, str, visited, t + str[i]);
				visited[i] = false;
			}
		}
	}
    int numTilePossibilities(string tiles) {
        if (tiles.size() == 0 || tiles.empty()) return 0;
        vector<char > temp;
        bool *visited = new bool[tiles.size()]();
        dfs(0, tiles.size(), tiles, visited, "");
        delete[] visited;
        return result.size();
    }
};

int main() {
	Solution s = Solution();
	cout << s.numTilePossibilities("AAB"); 
	return 0;
}

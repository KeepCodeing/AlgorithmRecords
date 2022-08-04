#include <iostream>
#include <vector>
using namespace std;

// ��Ŀָ�����û���... 

int n;
void dfs(int level, int deepth, vector<int >& r, int num) {
	if (num == n && r.size() > 1) {
		int rLen = r.size();
		for (int i = 0; i < rLen; i++) {
			cout << r[i];
			if (i != rLen - 1) cout << '+';
		}
		cout << endl;
		return;
	}	
	for (int i = level; i <= deepth; i++) {
		if (num + i > n) continue;
		// ���̣������ַ��������Σ������ø�vector����
		r.push_back(i);  
		dfs(i, deepth, r, num + i);
		r.pop_back();
	}
}

int main() {
	vector<int > r;
	cin >> n;
	dfs(1, n, r, 0);
	return 0;
}

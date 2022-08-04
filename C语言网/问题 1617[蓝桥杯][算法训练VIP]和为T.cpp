#include <iostream>
#include <vector>
using namespace std;
long nums[30];
vector<vector<int > > res;
int n;
void dfs(int level, int deepth, long target, long s, vector<int > vec) {
	if (s == target && vec.size()) {
		res.push_back(vec); 
		return;
	}
	// 倒着遍历，然后倒着输出，这样就能保证下标正确，但是不幸超时（无能） 
	for (int i = level; i >= 1; i--) {
		vec.push_back(i);
		dfs(i - 1, deepth, target, s + nums[i], vec);
		vec.pop_back();
	}
	
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	long target;
	cin >> target;
	vector<int > vec;
	dfs(n, n, target, 0, vec);
	int rLen = res.size();
	for (int i = rLen - 1; i >= 0; i--) {
		for (int j = res[i].size() - 1; j >= 0; j--) {
			cout << nums[res[i][j]];
			if (j != 0) cout << ' ';
		}
		cout << endl;
	}
	cout << res.size();
	return 0;
}

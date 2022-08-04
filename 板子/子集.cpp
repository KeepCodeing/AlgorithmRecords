#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<vector<int > > vec;
void dfs(int level, int deepth, vector<int >& temp) {
	vec.push_back(temp);
	
	for (int i = level; i < deepth; i++) {
		temp.push_back(i); 
		dfs(i + 1, deepth, temp);
		temp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	vector<int > temp;
	dfs(0, 3, temp);
	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}

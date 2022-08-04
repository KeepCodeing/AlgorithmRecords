#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// ˮ... 

void printVector(vector<int >& v) {
	for (int i = 0; i < v.size(); i++) printf("%3d", v[i]);
	printf("\n");
}


void dfs(int level, int deepth, vector<int >& v, int n) {
	if (v.size() == deepth) {
		printVector(v);
		return;
	}
	for (int i = level; i <= n; i++) {
		v.push_back(i);
		dfs(i + 1, deepth, v, n);
		v.pop_back(); 
	}
}

int main() {
	int n, r;
	cin >> n >> r;
	vector<int > v;
	dfs(1, r, v, n);
	return 0;
}

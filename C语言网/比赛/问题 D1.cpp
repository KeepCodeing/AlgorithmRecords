#include <iostream>
using namespace std;
void dfs(int level, int deepth, int choose) {
	if (level == deepth) {
		return;
	}
	cout << choose << endl;
	dfs(level + 1, deepth, choose + 1);
	dfs(level + 1, deepth, choose);
}
int main() {
	dfs(1, 5, 1);
	return 0;
}

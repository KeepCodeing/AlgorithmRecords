#include <iostream>
using namespace std;

// 应该是个dfs，两种状态，选或不选，按着思路来写就行 

void dfs(string str) {
	if (str.size() == 5) {
		cout << str << endl;
		return;
	}
	dfs(str + "0");
	dfs(str + "1");
}

int main() {
	dfs("");
	return 0;
}

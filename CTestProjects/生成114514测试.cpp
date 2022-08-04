#include <iostream>
#include <vector>
using namespace std;
int numList[6] = {1, 1, 4, 5, 1, 4};
char comList[4] = {'+', '-', '*', '/'};
void dfs(int level, int deepth, string cmpStr) {
	if (cmpStr.size() == 5) {
		for (int i = 0; i < 5; i++) {
			cout << numList[i] << cmpStr[i];
		}
		cout << numList[5] << endl;
		return;
	}
	for (int i = 0; i < deepth; i++) {
		dfs(i, deepth, cmpStr + comList[i]);
	}
}
int main() {
	dfs(0, 4, "");
	return 0;
}

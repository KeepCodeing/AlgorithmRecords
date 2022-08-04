#include <iostream>
using namespace std;
int visited[11], result[11];
void dfs(int s, int level) {
	if (s >= level + 1) {
		int a, b, c;
		a = result[1] * 100 + result[2] * 10 + result[3];
		b = result[4] * 100 + result[5] * 10 + result[6];
		c = result[7] * 100 + result[8] * 10 + result[9];
		if (a * 2 == b && a * 3 == c) cout << a << ' ' << b << ' ' << c << endl;
		return;
	}
	for (int i = 1; i <= level; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		result[s] = i;
		dfs(s + 1, level);
		visited[i] = 0;
	}
}
int main() {
	dfs(1, 9);
	return 0;
}


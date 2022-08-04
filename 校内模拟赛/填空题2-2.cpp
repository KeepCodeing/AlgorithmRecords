#include <iostream>
#include <set>
using namespace std;
set<string > ss;
void dfs(int left, int right, string res) {
	if (left == 0 && right == 0) {
		cout << res << endl;
		ss.insert(res); 
		return;
	}
	if (left <= right && left > 0) dfs(left - 1, right, res + "(");
	if (right > 0) dfs(left, right - 1, res + ")");
}
int main() {
	dfs(4, 4, "");
	cout << ss.size();
	return 0;
}

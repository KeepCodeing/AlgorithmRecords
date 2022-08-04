#include <iostream>
#include <stdio.h>
using namespace std;
string nums, cs[4] = {"+", "-", "*", "/"};
FILE *f = fopen("./t.txt", "w");
void dfs(int level, int used, string str) {
	if (!used) {
		string res = "";
		for (int i = 0; i < nums.size(); i++) res += nums[i], res += str[i];
		cout << str << endl;
		fprintf(f, "%s\n", res.c_str());
		return;
	}
	for (int i = 0; i < 4; i++) dfs(i, used - 1, str + cs[i]);
}
int main() {
	cout << "ÊäÈëÊý×Ö£¬Çë£º";
	cin >> nums;
	dfs(0, nums.size() - 1, "");
	fclose(f);
	return 0;
}

#include <iostream>
#include <map>
using namespace std;

// 主要用map对应答案和题面 

map<string, string > ans;
int main() {
	int n, q;
	cin >> n >> q;
	string question, answer;
	for (int i = 0; i < n; i++) {
		cin >> question >> answer;
		ans[question] = answer;
	}
	for (int i = 0; i < q; i++) {
		char r = 'A';
		cin >> question;
		// 这里可以一次性输入答案和选项，代码可以更加直观 
		for (int j = 0; j < 4; j++) {
			cin >> answer;
			if (ans[question] == answer) {
				cout << r << endl;
			}
			r++;
		}
	}
	return 0;
}

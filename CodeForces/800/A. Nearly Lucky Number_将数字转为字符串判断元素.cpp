#include <iostream>
using namespace std;

// 看错题意w，题目要求的是一个数字包含4和7的个数是不是4或者7，而不是问一个数字是不是
// 只有4和7... 

int main() {
	int cnt = 0;
	string num;
	cin >> num;
	for (int i = 0; i < num.size(); i++) {
		if (num[i] == '4' || num[i] == '7') cnt++;
	}
	if (cnt == 4 || cnt == 7) cout << "YES";
	else cout << "NO";
	cout << endl; 
	return 0;
}

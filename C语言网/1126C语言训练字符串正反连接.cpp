#include <iostream>
using namespace std;

// 电工电子害没搞完，刷水题玩玩... 

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) cout << str[i];
	for (int i = str.size() - 1; i >= 0; i--) cout << str[i];
	return 0;
}

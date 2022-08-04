#include <iostream>
using namespace std;

// 奇妙的难度评级

int main() {
	string str;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--) cout << str[i];
	return 0;
} 

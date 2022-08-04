#include <iostream>
using namespace std;

// 水题第十九(19191919419)弹...上一个水题好像卡住了，这个要是也卡住就算了.. 

int main() {
	string str, res = "";
	bool flags[3];
	flags[0] = flags[1] = flags[2] = false;
	cin >> str;
	if (str.size() >= 5) {
		for (int i = 0; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') flags[0] = true;
			else if (str[i] >= 'A' && str[i] <= 'Z') flags[1] = true;
			else if (str[i] >= 'a' && str[i] <= 'z') flags[2] = true;
		}
	}
	if (res == "" && flags[0] && flags[1] && flags[2]) cout << "Correct";
	else cout << "Too weak";
	return 0;
}

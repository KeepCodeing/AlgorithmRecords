#include <iostream>
using namespace std;
int main() {
	int maxLen = -1;
	string temp, str;
	while(cin >> temp) {
		// 奇妙，这里直接用temp.size()对比居然不行 
		int t = temp.size();
		if (t > maxLen) {
			maxLen = t;
			str = temp;
		}
	}
	cout << str;
	return 0;
}

#include <iostream>
using namespace std;

// 因为boy和girl的字符各不相同，所以可以只要出现两者中任意字符
// 就算是一个覆盖词，为了方便统计将原单词替换 

int main() {
	string str;
	cin >> str;
	// C艹的replace太野蛮了
	for (int i = 0; i < str.size(); i++) {
		int b, g;
		if (b = str.find("boy") != str.npos) {
			str.replace(b, b + 3, "1"); 
		}
		if (g = str.find("girl") != str.npos) {
			str.replace(g, g + 4, "0"); 
		}
		if (b == str.npos && g == str.npos) break;
	} 
	cout << str; 
	return 0;
}

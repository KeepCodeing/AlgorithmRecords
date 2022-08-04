#include <iostream>
#include <vector>
using namespace std;
// 给出一个字符串如"here you are"，要求将其翻转为"are you here"
// 思路：先将单词切分开，在逆序拼接在一起
string splitStr(string str, char reg) {
	string temp, result;
	// 防止漏掉最后一串字符 
	str += reg;
	vector<string > r; 
	// 特意的“越界”，防止漏掉最后一串字符 
	for (int i = 0; i <= str.size(); i ++) {
		if (str[i] != reg) {
			temp += str[i];
		} else {
			r.push_back(temp);
			temp.clear();
		}
	}
	for (int i = r.size() - 1; i >= 0; i--) {
		result += r[i];
		if (i != 0) result += reg;
	}
	return result;
} 
 
int main() {
	cout << splitStr("here you are", ' ');
	return 0;
}

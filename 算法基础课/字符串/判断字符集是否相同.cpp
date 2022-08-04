#include <iostream>
using namespace std;
// 给定两串字符，试比较它们中出现字符是否相同 
// 思路：和变形词题相同，但是这题不要求出现次数相同，只要求字符都出现过
// 可以利用find函数寻找A串或B串的字符是否都彼此出现过，这里就不好使用辅助数组计数
// 因为就算A串字符出现次数减去B串字符出现次数为负，也不能肯定B串字符没有出现A串字符 
// 但可以使用map记录A串出现过的字符， 然后再到B串中把B串字符作为key判断value 
int main() {
	string A;
	string B;
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		if (B.find(A[i]) == B.npos) {
			cout << "can not!" << endl;
			break;
		}
	}
	return 0;
}

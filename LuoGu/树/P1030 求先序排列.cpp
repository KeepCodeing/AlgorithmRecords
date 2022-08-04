#include <iostream>
using namespace std;

// 给出现后序遍历的字符串，最后一个字符就是树的主根，根据主根，又可以将中序遍历分为两部分
// 再对中序遍历得出的左右子树进行中序遍历+后序遍历就可得出先序遍历 

void fir(string mid, string before) {
	if (mid.size() > 0) {
		char ch = before[before.size() - 1];
		cout << ch;
		int k = mid.find(ch);
		fir(mid.substr(0, k), before.substr(0, k));
		fir(mid.substr(k + 1), before.substr(k, mid.size() - k - 1)); 
	}
}
int main() {
	string mid, before;
	cin >> mid >> before;
	fir(mid, before);
	return 0;
}

#include <iostream>
using namespace std;

// 好久以前坠毁的题w，不知道现在有没有长进呢w.. 
// all right..还是WA了一发，因为没搞懂题目给的n的意思w，这个n应该只能用来标志换行，而不是说后面有n*2个元素... 

int main() {
	int tt, ct = 0;
	bool flag = false;
	int n, t, cnt = 0;;
	cin >> n;
	// 这里直接写成输入t就完事了，不一定有n*2个输入... 
	while (cin >> t) {
		while (t--) {
			// 以前太naive不知道bool也能输出（或许都不知道boolw） 
			cout << flag;
			// 换行 
			cnt++;
			if (cnt == n) {
				cout << endl;
				cnt = 0;
			}
		}
		// 转为相反字符... 
		flag = !flag;
	}
	return 0;
}


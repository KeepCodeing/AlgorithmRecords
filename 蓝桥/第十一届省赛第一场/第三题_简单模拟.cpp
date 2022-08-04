#include <iostream>
using namespace std;
int main() {
	// 把计时单位换成秒，方便得到答案 
	int n = 10000;
	// 跑步一秒损失10体力，休息一秒恢复5体力..
	int tot = 0;
	for (int i = 1;; i++) {
		for (int j = 1; j <= 60; j++) {
			n -= 10;
			// 不该把break写这里，这样的话跑完的那一秒没算进去... 
			tot++;
			if (n <= 0) break;
		}
		if (n <= 0) break;
		for (int j = 1; j <= 60; j++) n += 5, tot++;
	} 
	cout << tot << endl;
	return 0;
}

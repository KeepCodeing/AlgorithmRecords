#include <iostream>
#include <cstdio>
using namespace std;

// 水题第二十二弹，一瞬有种回到了刚学C那段时候的感觉，那时候印象深的就是这种画图题了，甚至可以对着这种题想很长时间...
// 怀念感放辣椒... 

int main() {
	int n, l, r, val = 1, line;
	scanf("%d", &n);
	l = r = line = (n / 2) + 1;
	cout << line << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= l && j <= r) cout << "D";
			else cout << "*";
		}
		// 注意执行这段代码前全是D的那一行已经输出完成了 
		if (i >= line) val = - 1;
		l -= val, r += val;
		puts("");
	}
	return 0;
}
//#include <iostream>
//#include <cstdio>
//using namespace std;
//int main() {
//	int n, l, r, val = 1, line;
//	scanf("%d", &n);
//	l = r = line = (n >> 1) + 1;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//        	cout << (j >= l && j <= r ? 'D' : '*');
//		}
//		if (i >= line) val = - 1;
//		l -= val, r += val;
//		puts("");
//	}
//	return 0;
//}

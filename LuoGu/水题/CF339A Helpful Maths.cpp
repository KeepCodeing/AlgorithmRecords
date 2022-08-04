#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
char nums[250];
int main() {
	int cnt = 0;
	char c;
	while (cin >> c) 
		if (c != '+') nums[cnt++] = c;
	sort(nums, nums + cnt);
	for (int i = 0; i < cnt - 1; i++) cout << nums[i] << '+';
	cout << nums[cnt - 1];
	return 0;
}
// 下面字符串模拟太麻烦，直接排序算了 
//#include <iostream>
//using namespace std;
//
//// 水题第十一弹..用格式化或者遍历都可以做..，这里注意到了一个只有数字1,2,3的细节，也就是只用读入的时候
//// 统计下这三个数字的个数就行了... 
//
//void printNum(int n, char c) {
//	for (int i = 0; i < n; i++) {
//		if (i == 0) cout << c;
//		else cout << '+' << c;
//	}
//}
//int main() {
//	int a = 0, b = 0, c = 0;
//	char num;
//	while (cin >> num) {
//		if (num == '1') a++;
//		else if (num == '2') b++;
//		else if (num == '3') c++;
//	}
//	printNum(a, '1'), printNum(b, '2'), printNum(c, '3');
//	return 0;
//}

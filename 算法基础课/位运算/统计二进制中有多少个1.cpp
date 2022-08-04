#include <iostream>
using namespace std;
 
// 一共有两种方法，方法一是将原数向右移，同时对比最低位与1的值，
// 这种方法无法统计负数的情况，故省略。
// 方法二是将1向左移，已知1的二进制为0..01，向左移动后即为2，也就是0..10，这样
// 就起到对比原数每一位是否为1的效果，当向左移移出了当前数据范围的二进制数时，
// 对比用的数就会因为越界变为0，循环就会就说明对比完成，循环就会结束 
int main() {
	int num = 15, cnt = 0;
	int flag = 1;
	while (flag) {
		if (flag & num) {
			cnt++;
		}
		flag <<= 1;
	}
	cout << cnt << endl;
	return 0;
}

#include <iostream>
using namespace std;
// 假设有一个天秤，且有1, 3, 9, 27...3的指数幂重量的砝码，假设砝码的数量是无限的，且砝码可以防止左边或
// 右边，现要求用户输入一个数字，给出砝码的组合方案，例：输入5，输出9-3-1

// 分析：题目的意思是一个秤，左边放任意重量的砝码，右边放任意重量的砝码，然后在左边或者右边加上用户输入
// 的值，使秤平衡。
// 暴力解法：观察数据，我们发现5<3^2，可能的方案是9-3-1,换一个数字，2<3^1，可能的方案是3-1，依次类推，
// 可以发现最大的砝码永远是重量第一个大于用户输入的重量的那个砝码，于是剩下的砝码的重量一定在平方数
// 小于最大的砝码的平方数的砝码中产生，更新重量，以此类推，就可求出答案

// 6.1,并没有学会 
int maxNum;
int getMaxIndex(int num) {
	int index = 0;
	int max_w = 1;
	while (max_w <= num) {
		max_w *= 3;
		index++;
	}
	maxNum = max_w;
	return index;
}
int result[100];
void d(int level, int r, int maxLevel, int num) {
	
	if (level >= maxLevel + 1) return;
	if (r > num) return;
	result[level - 1] = r;
	if (r == num) {
		for (int i = 0; i < 10; i++) {
			
			cout << result[i] << ' ';
		}
		return;
	}
	d(level + 1, r + r * 3, maxLevel, num);
	result[level - 1] = 0;
}
int main() {
	int num;
	cin >> num;
	int maxIndex = getMaxIndex(num);
	d(1, 1, maxIndex, maxNum - num);
	return 0;
}

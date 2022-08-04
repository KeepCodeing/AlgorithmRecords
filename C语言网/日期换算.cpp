#include <iostream>
using namespace std;

// 之前一直比较反感做日期之类的题w，然而做到蓝桥杯才发现自己不会w..
// 判断闰年是四年一闰，百年不闰，四百年又闰..看月份天数的话查日历就行.. 

typedef long long LL;
int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
	LL x, y, res = 0;
	// 注意这个格式，据说蓝桥杯输入是%I64d，不过这样写C语言网又会坠毁... 
	// 去练习系统试了下A+B Problem，似乎不这样写是可以的.. 
	scanf("%lld%lld", &x, &y);
	for (int i = 0; i < x - 1; i++) res += m[i];
	res += y;
	printf("%lld", res);
	return 0;
}

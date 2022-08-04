#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

// 试下在博客里看到的算法能不能AC... 

// 屑算法，效率过低，只能过一般的点，开O2都没救ww 

vector<int > vec;
int main() {
	int n, t, now, res = 0;
	scanf("%d", &n);
	// 主要的思想就是模拟冒泡排序的过程 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		// 找到比当前数大的数 
		now = upper_bound(vec.begin(), vec.end(), t) - vec.begin();
		// 当前数到第一个比当前数大的数间的距离就是这个数的逆序对的个数
		// 注意这里的-1，因为i是从1开始的，而vector从0开始，now就是第一个
		// 比当前数大的数的位置，另外在做完逆序对之后还要模拟交换值的过程
		// 也就是把大的放前面，小的放后面... 
		res += i - 1 - now, vec.insert(vec.begin() + now, t); 
	}
	printf("%d", res);
	return 0;
}


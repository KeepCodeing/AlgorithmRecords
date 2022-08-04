#include <iostream>
#include <cstdio>
using namespace std;

// 本来以为是个水题的，但是内存限制4MB，这就是说这个题
// 不能开个数组之类的过，但是题目类似于找重复，这就可以用异或了
// 因为所有筷子都是成对出现的，也就是说这类筷子进行异或一定得到的是
// 0，而多出来的那个筷子异或0就会得到其自身

// 然而TLE了，cin太慢... 
// 啊这...scanf也坠毁了，但是还是比cin快一些，暂且蒙古 

// 奇妙深刻，写的while(n--)居然TLE了，而且数据不知道为什么下载不能w 
// 本地测试for和while速度差不多，暂且蒙在数据里 

int main() {
	int n;
	scanf("%d", &n);
	int res = 0;
	int t;
	// 这里得用for，不然会TLE，不知道为什么 
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		res ^= t;
	}
	cout << res;
	return 0;
} 

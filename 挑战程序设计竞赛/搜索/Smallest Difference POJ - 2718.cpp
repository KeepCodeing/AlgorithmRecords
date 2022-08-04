#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 似乎在洛谷上做过类似的题？总之就是把每个状态都枚举到，爆搜...
// 另外有个数组划分两半的题，那个题是前缀和枚举.... 
// 这个题大部分题解是全排列做的，本five写个DFS算了... 

// 发现这个题不是简单的题目里的子集问题，我们考虑选出来一个子集的时候，还要通过某种方法获取这个子集的补集...
// 看来还是全排列算了w 

// 全排列的思路是将字符串分为两个部分，这两个部分均不允许出现前导0（出现了数字非法），而对于第二个部分
// 可以允许出现01的两位带前导0字符串，因为这也是合法的，但是不允许出现类似0111的字符串，这样划分出的数字就是非法的 

// CE了两次，第一次选择的评测机是C++，提示没有getline()，第二次选择的G++，提示没有getchar()，加了头文件就好了... 

const int N = 15, INF = 0x3fffffff;
int nums[N];
int n;
int myabs(int a) {
	return a < 0 ? -a : a;
}
int getNum(int st, int ed) {
	int res = 0;
	for (int i = st; i < ed; i++) res = res * 10 + nums[i];
	return res;
}
int main() {
	int idx = 0, temp, res;
	string str;
	cin >> n;
	getchar();
	while (n--) {
		idx = 0, res = INF;
		getline(cin, str);
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != ' ') nums[idx++] = str[i] - '0';
		}
		do {
			// 如果左半部分的字符串出现了前导0或者右半部分字符串出现了前导0并且字符串长度大于2（不对称），
			// 则认为这次枚举是非法的 
			if (nums[0] == 0 || (nums[idx / 2] == 0 && idx > 2)) continue;
			temp = myabs(getNum(0, idx / 2) - getNum(idx / 2, idx));
			res = min(res, temp);
		} while (next_permutation(nums, nums + idx));
		cout << res << endl;
	}
	return 0;
}

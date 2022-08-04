#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 目前的思路是先记录下前缀和，然后利用离散化标记下最大值和最小值
// 如果去掉的是最大值或最小值，就取比它们小/大的值作为前缀和里要减去
// 的值，然后依次去试就行 

// 草，不会线段树，后面把题目读懂了才发现不会求区间最小值... 
// 不过可以倒着扫一遍，每次对比当前元素和前面元素的大小，如果当前元素更小，那么最小值就是这个值
// 否则就是另一个值 

typedef long long LL;
const int N = 100010;
LL s[N];
vector<int > vec, nums;
int findNum(int x) {
	return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, t;
	cin >> n;
	s[0] = 0;
	for (int i = 1; i <= n; i++) cin >> t, vec.push_back(t), s[i] = s[i - 1] + t;
	nums = vec;
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	int vLen = vec.size();
	for (int i = 1; i <= n - 2; i++) {
		cout << s[n] - s[i] << endl;
		int now = nums[i - 1];
		// 如果当前去掉的值是最小值，下面是最大值的情况 
		if (findNum(now) == 0) {
			// 如果去掉的是最小值，那就用前缀和-原最大值-比最小值稍大的值 
		} else {
			// 如果既不是最大值，也不是最小值，直接求前缀和-原最大值-最小值的平均值即可 
			 
		}
	}
	// 我谔谔，只会去掉最小值... 
	/* else if (findNum(now) == vLen - 1) {
			// 如果去掉的是最大值，那就减比它稍小的值 
		}*/
	return 0;
}

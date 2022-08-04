#include <iostream>
#include <cstdio>
using namespace std;

// 枚举每个点，看下以这个点为分割能不能使左右两个区间的和相等
// 利用前缀和进行预处理 

// 之前还有个ACM ICPC的题，这个题也是要求分区间数，只不过那个题数据量小
// 所以可以用爆搜，这个题数据量很大，所以得用前缀和 

typedef long long LL;
const int N = 1e5 + 10;
LL s[N];
int main() {
	s[0] = 0;
	int n;
	scanf("%d", &n);
	int t;
	for (int i = 1; i <= n; i++) scanf("%d", &t), s[i] = s[i - 1] + t;
	// 枚举每个切割点，注意最后一个点不可取，因为题目要求两个区间都不能为空 
	int cnt = 0;
	for (int i = 1; i <= n - 1; i++) {
		// 依次枚举以当前点为分割点，左右两个区间的和是否相等 
		if (s[i] == s[n] - s[i]) cnt++;
	} 
	cout << cnt;
	return 0;
}

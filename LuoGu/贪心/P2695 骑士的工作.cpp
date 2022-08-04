#include <iostream>
#include <algorithm>
using namespace std;

// 和之前那个母舰的题基本差不多，那个题要求>，所以应该用upper_bound，
// 这个题要求>=，所以应该用lower_bound，坑就在于如何判断能不能砍完
// 解决方法就是对比最大值，还有就是you died!少打了个!... 

int *heads, *man;
int main() {
	int n, m;
	int money = 0;
	cin >> n >> m;
	heads = new int[n + 5];
	man = new int[m + 5];
	for (int i = 0; i < n; i++) cin >> heads[i], money += heads[i];
	for (int i = 0; i < m; i++) cin >> man[i];
	sort(heads, heads + n);
	sort(man, man + m);
	int index = 0;
	int ans = 0;
	// 坑点：只能砍<=的头，如果有任何一个头的值比能砍的值还大就
	// 不可能砍完 
	if (heads[n - 1] > man[m - 1]) {
		cout << "you died!";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		index = lower_bound(man, man + m, heads[i]) - man;
		// 奇妙，这样搞了之后数组就是无序的了，但是STL还是能查出来...，但是也可以
		// 用优秀队列来做 
		ans += man[index], man[index] = 0;
	}
	if (ans >= money) cout << ans;
	else cout << "you died!";
	delete[] heads, man;
	return 0;
}

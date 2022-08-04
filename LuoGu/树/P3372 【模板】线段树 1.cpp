#include <iostream>
using namespace std;

// 线段树第二弹，为什么第一弹不是模板题呢..大概是没看到... 
// 谔谔，突然发现是区间修改，也就是需要懒标记，所以暂时放放这个题... 

const int N = 1e5 + 10, M = N * 4 + 10;
long long arr[N], root[M];
void build(int now, int left, int right) {
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	while (m--) {
		
	}
	return 0;
}

#include <iostream>
using namespace std;

// 一眼看到数组全部元素加上x以为这个题有点难度，但转念一想全部加上x也就意味着不是
// 某个区间加上x，那么其实就相当于单点加上x，也就是输出的时候进行下操作，累加下x就行 

// 不过题意翻译似乎有点问题，操作一不是简单的赋值，而是用输入的值减去增加的值

// 饭前水题☆ 

// cin,cout关闭同步ao慢，大数据还是能用C就用C算了 

typedef long L;
const int N = 1e5 + 10;
L arr[N];
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int op, x, tot = 0, ti;
	while (m--) {
		cin >> op >> x;
		if (op == 3) cout << arr[x] + tot << endl;
		else if (op == 2) tot += x;
		else cin >> ti, arr[x] = ti - tot;
	}
	return 0;
}

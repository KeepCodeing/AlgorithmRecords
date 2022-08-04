#include <iostream>
#include <vector>
using namespace std;

// 线段树第五弹.. 
// 昨天睡觉的时候突然想到了这个题也是求区间最值，所以就想做一下，不过其想的是只求一个最值，但是这个题要求最大值
// 和最小值。想了下如果写两个查询或者两个线段树估计logn^2了，再看数据范围超时不可避w。接下来想了下怎么一次返回
// 两个值，居然想到python的元组上去了...然后看了题解才知道可以返回结果体... 

// O2续命成功...线段树做滑动窗口果然还是太慢了... 

typedef pair<int, int > PII;
// 这里这个结构体其写了个val变量用来记录叶子节点的值，不过这样做出错了，因为我们要对比的是最值
// 而赋值时只有叶子节点的父节点记录的是最值，其它情况下这个val都可能只是个没有初始化的空变量，
// 而其程序对比的就是val... 
struct Node {
	int mx, mn;
	Node (int mx, int mn) : mx(mx), mn(mn) {};
	Node () {};
};
const int N = 1e6 + 10, M = N * 4;
int arr[N];
Node root[M];
void build(int now ,int left, int right) {
	if (left == right) {
		root[now].mx = root[now].mn = arr[left];
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	// 当前节点的最大值就是左右子树的最大值，注意这里root其实存了两个最值 
	// 之前对比的val，但是这样的话只有叶子节点的父亲对比的是最值，想下其它情况的val是什么，val只有叶子节点的时候进行
	// 了赋值，而其它情况的对比都是未定义的...所以这里干脆不用val，直接把最值拿来对比... 
	root[now].mx = max(root[l_node].mx, root[r_node].mx);
	root[now].mn = min(root[l_node].mn, root[r_node].mn);
}
Node query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if (L > right || R < left) return Node(-1e9, 1e9);
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	Node lres = query(l_node, left, mid, L, R), rres = query(r_node, mid + 1, right, L, R);
	return Node(max(lres.mx, rres.mx), min(lres.mn, rres.mn));
}
vector<Node > vec;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int n, m;
	cin >> n >> m;
	// 用来模拟查询区间最值，注意这里的区间是闭区间 
	for (int i = 0; i < n; i++) cin >> arr[i];
	build(0, 0, n - 1);
	for (int i = 0; i < n - m + 1; i++) vec.push_back(query(0, 0, n - 1, i, i + m - 1));
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) cout << vec[i].mn << ' ';
	cout << endl;
	for (int i = 0; i < vLen; i++) cout << vec[i].mx << ' ';
	return 0;
}

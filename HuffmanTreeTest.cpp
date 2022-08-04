#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// huffman树本质还是个线段树，只不过跑的是排序后的序列，而且每个节点多了个标号属性 

typedef long long LL;
const int N = 1e5 * 5, M = N * 4;
set<string > res;
struct huffman {
	int l, r;
	// 用来标记当前节点是0还是1，used是为了后面先序遍历方便判断是否走过头了，说来奇妙
	// 之前做了个线段树建字符串的题，那时候似乎不是这样写的，总之这种写法更加通用... 
	bool flag, used;
	LL sum;
	// 不知道结构体里默认什么值，最好自己设一个 
	huffman(bool u = false) {
		used = u;
	}
} root[M];
int nums[N];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
	// 和普通线段树的不同点，huffman数的左右节点都会有个编号属性，非0即1，那么可以设置所有左节点为1，
	// 右节点为0... 
	root[now << 1].flag = false, root[now << 1 | 1].flag = true;
}
void build(int now, int left, int right) {
	// 建树的同时标记下当前点使用过了... 
	root[now].l = left, root[now].r = right, root[now].used = true;
	if (left == right) {
		root[now].sum = nums[left];
		return;
	}
	int mid = (left + right) >> 1;
	int ln = now << 1, rn = now << 1 | 1;
	build(ln, left, mid);
	build(rn, mid + 1, right);
	pushup(now);
}
void in_order(int now, string str) {
	if (!root[now].used) {
		// 不知道为什么会输出两次答案，总之用个set去重就完事了... 
		res.insert(str);
		return;
	}
	// 之前回溯里直接输出了w，想了下才知道回溯要保留状态的，不然会出现输出完左子树之后直接跳到
	// 右子树哪里了.. 
	str = str + (char)(root[now].flag + '0');
	// 前序遍历的套路，这里用编号代替指针... 
	in_order(now << 1, str);
	in_order(now << 1 | 1, str);
}
// 10
// 20 15 10 10 10 5 10 5 10 5
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> nums[i];
	sort(nums + 1, nums + n + 1);
	build(1, 1, n);
	in_order(1, "");
	for (set<string >::iterator it = res.begin(); it != res.end(); it++) cout << *it << endl;
	// for (int i = 1; i <= n * 4; i++) cout << "root[" << i << "] = " << root[i].sum << " flag = " << root[i].used << endl;
	return 0;
}

#include <iostream>
using namespace std;

// 试着用线段树的建树方法构想了下这个树的建造，可以试试了...

// 空间开小了WA了两个点... 
const int N = 1030;
char root[N * 4];
string str;
char getNode(string& str, int left, int right) {
	bool iszero = true, isone = true;
	for (int i = left; i <= right; i++) {
		if (str[i] == '0') isone = false;
		else if (str[i] == '1') iszero = false;
	}
	if (!iszero && !isone) return 'F';
	if (iszero) return 'B';
	return 'I';
}
// 建出来的树一定是一棵满二叉树，这里用线段树的思想建树，应该可以适用于大部分要建树额题罢（虚心） 
void build (int now, int left, int right) {
	if (left == right) {
		root[now] = getNode(str, left, right);
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	root[now] = getNode(str, left, right);
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
}
string res;
// 直接模拟后序遍历的思路就行了.. 
void pre_order(int now) {
	// 这里写成这样比较好，线段树里是left==right，这是叶子节点上的情况，这个题要遍历完整棵树所以
	// 得模拟后序遍历的思路判断当前节点是否为空 
	if (!root[now]) return; 
	// 因为不是指针所以得模拟下一个节点的编号是什么.. 
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	pre_order(l_node);
	pre_order(r_node);
	// 这里也可以直接输出 
	res += root[now];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n >> str;
	build(0, 0, str.size() - 1);
//	for (int i = 0; root[i]; i++) cout << "root[" << i << "] = " << root[i] << endl;
	pre_order(0);
	cout << res;
	return 0;
}

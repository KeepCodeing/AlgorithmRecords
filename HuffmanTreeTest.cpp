#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// huffman�����ʻ��Ǹ��߶�����ֻ�����ܵ������������У�����ÿ���ڵ���˸�������� 

typedef long long LL;
const int N = 1e5 * 5, M = N * 4;
set<string > res;
struct huffman {
	int l, r;
	// ������ǵ�ǰ�ڵ���0����1��used��Ϊ�˺���������������ж��Ƿ��߹�ͷ�ˣ�˵������
	// ֮ǰ���˸��߶������ַ������⣬��ʱ���ƺ���������д�ģ���֮����д������ͨ��... 
	bool flag, used;
	LL sum;
	// ��֪���ṹ����Ĭ��ʲôֵ������Լ���һ�� 
	huffman(bool u = false) {
		used = u;
	}
} root[M];
int nums[N];
void pushup(int now) {
	root[now].sum = root[now << 1].sum + root[now << 1 | 1].sum;
	// ����ͨ�߶����Ĳ�ͬ�㣬huffman�������ҽڵ㶼���и�������ԣ���0��1����ô��������������ڵ�Ϊ1��
	// �ҽڵ�Ϊ0... 
	root[now << 1].flag = false, root[now << 1 | 1].flag = true;
}
void build(int now, int left, int right) {
	// ������ͬʱ����µ�ǰ��ʹ�ù���... 
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
		// ��֪��Ϊʲô��������δ𰸣���֮�ø�setȥ�ؾ�������... 
		res.insert(str);
		return;
	}
	// ֮ǰ������ֱ�������w�������²�֪������Ҫ����״̬�ģ���Ȼ����������������֮��ֱ������
	// ������������.. 
	str = str + (char)(root[now].flag + '0');
	// ǰ���������·�������ñ�Ŵ���ָ��... 
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

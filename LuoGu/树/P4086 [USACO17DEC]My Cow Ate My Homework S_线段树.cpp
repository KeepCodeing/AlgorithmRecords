#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// �߶����ڰ˵������������״������׹����ww����֮����ά��������ֵ��Ȼ��
// ǰ׺��ά������ͣ�����ⲻ���ṩ�޸ĺ�����ǣ����Ǽ򵥵ĵ����߶���...��д���˸о��������߶����ڴ����Ͼ����޸�����
// ��Щ�仯�������߶����޸���Ҫ����pushdown������ҲҪ�ж����Ƿ��ߵ����޸�����... 

// д���˸о����˺�hape�Ĵ��󣬶���WA����Σ���Ҫ�о��ȣ�temp��ֵ������������ͣ�maxScore�������ִ�ȴ�������
// �𰸣�temp == maxScore���... 

typedef long long LL;
const int N = 100000 + 100, M = N * 4;
int arr[N], root[M];
LL s[N];
vector<int > res;
void build(int now, int left, int right) {
	if (left == right) {
		root[now] = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
	root[now] = min(root[l_node], root[r_node]);
}
int query(int now, int left, int right, int L, int R) {
	if (L <= left && right <= R) return root[now];
	if(L > right || R < left) return 1e9;
	int mid = (left + right) >> 1;
	int l_node = now << 1, r_node = now << 1 | 1;
	return min(query(l_node, left, mid, L, R), query(r_node, mid + 1, right, L, R));
}
int main() {
	int n;
	scanf("%d", &n);
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		s[i] = s[i - 1] + arr[i];
	}
	build(1, 1, n);
	// ���Ӵ�������maxScoreд����int��Ȼ�������temp��ֵ��Ȼ��ֱ�������������.. 
	double temp, maxScore = -1e9;
	for (int i = 1; i <= n - 2; i++) {
		// ע�������ǿת��������ʽ�Ӷ������Σ����Ҳ�����Σ����Ҫǿת��������һ��ʽ��.. 
		temp = (s[n] - s[i] - query(1, 1, n, i + 1, n) + .0) / (n - i - 1);
		// ����hape��д���˵��´𰸳���ʱ���res�����Ǿ͵��´���Զֻ��һ����Ȼ��ֻ��һ������ж��ww�� 
		if (temp > maxScore) maxScore = temp, res.clear();
		if (temp == maxScore) res.push_back(i);
	}
	int rLen = res.size();
	for (int i = 0; i < rLen; i++) printf("%d\n", res[i]);
	return 0;
}

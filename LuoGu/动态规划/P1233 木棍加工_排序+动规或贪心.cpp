#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// ���������������ϵľ���Ƕ���Ǹ��⣬�о������̰�Ļ���DP���������Ÿ���ʲô�� 

const int N = 5000 + 10;
struct Node {
	int l, w;
	bool operator<(const Node& n) const {
		if (l > n.l) return w > n.w;
	}
} s[N];
int main() {
	int n;
	scanf("%d", &n);
	// ���룬Ϊ�˷��������±��0��ʼ��̫�����ˣ�����д���ˣ�������Ǻ���ûʲô����w 
	for (int i = 0; i < n; i++) scanf("%d%d", &s[i].l, &s[i].w);
	sort(s, s + n);
	for (int i = 0; i < n; i++) printf("%d %d\n", s[i].l, s[i].w);
	return 0;
}

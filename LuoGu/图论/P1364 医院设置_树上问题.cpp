#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

// �������ݷ�Χ��С����ô����+�����������ˣ�����Ҫע����������ͨ��Ľ�ͼ��ʽ
// ��̫һ�����������ǵ�Ȩ��������Ľ�ͼ���̲���ֱ�����ڽӱ���Ϊ��Ȩ��ԭ�����
// �ṹ������ģ��...

// ��ô�ӵ�ǰ���ܸ�BFS��Ȼ����ȣ�����������·��������.. 

// һ��ʼ��Ϊ���������ģ�Ȼ�����ǵ�Ȩ��Ϊ��.. 

typedef long long LL;
typedef pair<int, int > PII;
const int N = 100 + 10; 
bool vis[N];
struct Node {
	int l, r, w, fat;
} root[N];
// �������������ĶԲ��Ե�ǰ����� 
void in_order(int now) {
	cout << root[now].w << endl;
	if (root[now].l) in_order(root[now].l);
	if (root[now].r) in_order(root[now].r);
}
LL bfs(int st) {
	memset(vis, 0, sizeof vis);
	queue<PII > que;
	que.push(PII(st, 0));
	LL res = 0;
	while (que.size()) {
		PII now = que.front(); que.pop();
		// ����ĳ����·��˼·�ˣ���Ϊ��Ȳ�֪����ô��w�����Ըɴ��ø�step�����浽��һ���ľ��� 
		int ut = now.first, step = now.second;
		if (vis[ut]) continue;
		// ��Ϊ���˫��������л����ظ����ʵ����� 
		vis[ut] = true;
		// ��� 
		res += root[ut].w * step;
		if (root[ut].l) que.push(PII(root[ut].l, step + 1));
		if (root[ut].r) que.push(PII(root[ut].r, step + 1)); 
		// ע��Ѹ��ڵ㣨��ȥ��·��Ҳ�ӽ��� 
		if (root[ut].fat) que.push(PII(root[ut].fat, step + 1));  
	} 
	return res;
}
int main() {
	int n, ut, vt, wt;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &wt, &ut, &vt);
		// ����������l��r��¼�ӽڵ��λ�ã�Ȼ��ѵ�Ȩ����������֮����
		// ������ģ�⽨ͼ... 
		root[i].l = ut;
		root[i].r = vt;
		// ע�⽨��˫��ߣ���Ȼû�취�����ߣ����ﲻ������0����Ϊ0��BFS��Ͳ����ܱ���ӣ�... 
		root[ut].fat = i;
		root[vt].fat = i;
		root[i].w = wt;
	}
	// �±�ը���˸�long long... 
	LL ans = 0x3fffffff;
	for (int i = 1; i <= n; i++) ans = min(ans, bfs(i));
	printf("%lld", ans);
	return 0;
}

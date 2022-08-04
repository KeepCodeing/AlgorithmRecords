#include <iostream>
#include <cstdio>
using namespace std;

// һ��ͼ���������ǰ�᣺���ͼ������ͼ����û�л�

// �������˼·�Ͷ�����ͼ����һ��BFS��ÿ�δ����Ϊ0�ĵ㿪ʼ�����ĳ�������Ϊ0�ˣ��Ǿ�˵�����Ѿ�����������ˣ�ֻ��
// ��Ϊ��㣬����һ������������ж����ǲ������е㶼����ˣ�����˵���е���ȶ�Ϊ0����Ϊ���һ������ȱ�Ȼ��Ϊ0����
// ������е㶼����ˣ���ô�������Ԫ�ؾ������ͼ�������򣬷����˵�����ͼ���ڻ�·�� 
// ����Ҫע�⣬һ��ͼ����������Ψһ�� 

// ע��Ϊʲô����Ҫô��ֻ��n - 1Ҫô���ǣ���Ϊ��һ�����Ϊ0�ĵ���Ӻ���൱��ɾȥ����������ߣ�Ҳ���������
// �޷��ٵ������Ҳ��ͬ��ɾһ����ͻ��ٺܶ��.. 

const int N = 1e5 + 10;
int head[N], e[N], ex[N], idx = 0;
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
int n, m; 
int rd[N];
int que[N];
bool topsort() {
	int qtop = 0, qback = -1;
	// ���������Ϊ0�ĵ������У�����Щ�㿪ʼ��չ 
	for (int i = 1; i <= n; i++) 
		if (!rd[i]) que[++qback] = i;
	while (qtop <= qback) {
		int ut = que[qtop++];
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			rd[vt]--;
			// �����ǰ�����ҲΪ0����˵����ǰ���Ѿ�������ɣ����Դ��������չ 
			if (!rd[vt]) que[++qback] = vt;
		}
	}
	// ���������е㶼����ˣ���˵�����ͼû�л�������ͱض����ڻ� 
	return qback == n - 1;
}
int main() {
	fill(head, head + N, -1);
	int ut, vt;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &ut, &vt);
		add(ut, vt);
		// ͳ����� 
		rd[vt]++;
	}
	if (topsort()) {
		// �����ͼ���������򣬶������Ԫ��˳�����������֮һ��ע��������е��±��Ǵ�0��ʼ�� 
		for (int i = 0; i < n; i++) printf("%d\n", que[i]);
	}
	return 0;
}

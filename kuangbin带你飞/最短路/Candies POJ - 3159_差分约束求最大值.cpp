#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

// ���ֵ�Ǹ����͵Ĳ��Լ�������ֵ����ĿҪ��B����ܱ�A���ö��ٿ��ǣ���ô��B����ܶ���C���ǣ����Ǿ���
// B-A<=C���������ʽӦ���кܶ������һ������ʽ�飬��ô�����ʵ�����ɳ������ˡ����ǽ���Щ������ʽ����
// ��һ������ͼ��Ȼ��������ʽ��������B <= A + C��A���ǵ�ǰ�㣬B����A��һ�����ܵ��ĵ㣬��ôC��������
// �ߵ�Ȩ�ء���������֮ǰ�Ľ��ۿ���֪�������Ҫ�����ֵ���Ǿ������·����������·���� <= ����ʽ����
// ���·����ʽ��Ҳ����˵������дʽ�ӵ�ʱ��͸���������ж��ɳ��������·���� >= ������˵�������⣬Ӧ��
// ֻ���ݲ���ʽ�����������·����B <= A + C���·���� A <= B + c֮���...��...(��Ȼ��ע�ⲻ�����·
// �������·�����Ƕ�ֻҪ��һ��·����������ˣ�Ҳ���ǲ���ʽ�ڴ�����������ǲ���=��... �ƺ������⣬�д���ȶ�� 
// Ȼ��ע��ת�������·����󣬾���Dijkstra�ܾ����ˣ�SPFA�ܿ��ܱ����������SPFA����ջ���ܹ�... 

/*
�о��е��ɣ���Ҫ��Ϊʲô�ɳڵĲ���ʽ���г����Ĳ���ʽ�෴...�ƺ������·��B <= A + C���ɳ���ͱ����B > A + C��
���·��B >= A + C���ɳ�������B < A + C�����������������ͦ�鷳�ģ���Ҳ�㲻��...��֮���ɹ�����Ӧ�þ�û����..

һ�䲩����Ļ����������...�о����Լ�����仹��һ���Ѷȣ���������w... 
���Լ��ϵͳ�����ַ�ʽ������⣬���·���·�������ǰѲ���ʽ�����d[a]+w<=d[b]ʱ���������·�������d[a]+w>=d[b]ʱ��
���������·�� 
*/

typedef pair<int, int > PII;
const int N = 30000 + 10, M = 150000 * 2 + 10;
int head[N], e[M], ex[M], w[M], idx = 0;
int dist[N];
bool visited[N];
int n, m;
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st) {
	memset(dist, 0x3f, sizeof dist);
	dist[st] = 0;
	priority_queue<PII, vector<PII >, greater<PII > > que;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (visited[ut]) continue;
		visited[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// �ɳ��������ƺ�������˵��ì���ˣ���֮���Լ����뷨�� A + C <= B���Ǿͺ�������һ������...��������������
			// �ƺ�����Ϊ���Լ�������ԣ�����С�ں�Ҫ��ʽ�ӷ�����... 
			if (wt + w[i] < dist[vt]) {
				dist[vt] = wt + w[i];
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[n];
}
int main() {
	memset(head, -1, sizeof head);
	int ut, vt, wt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		// ��������ߣ�u����A��v����B��w����C 
		add(ut, vt, wt);
	}
	printf("%d", dijkstra(1));
	return 0;
}

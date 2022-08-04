#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <vector>
using namespace std;

// ������ʵˢ�˲����⣬���������С�������ĵ�6���ˣ���ʵ֤����С�����������·�򵥺ܶ�...�����������Ҫ��ʼ��ʽ��ϰ�ˣ�
// ��Ȼ����׹��̫��������w����ô������ǽ��ڣ����������컹������һ�������棩�������һ������...��Ȼˢ��ܿ������AC
// ��ϲ��ȴ�����Դ������... 

// ��ô����ⲻ��ר���ź����뵽��С�������ɣ���ʵ�ϱ�fiveҲû�������ַ�������С������...������Ŀÿ���ַ���ֻ��7λ����ô
// Ӧ�ÿ��Ա���ö��ÿ���ַ����ԱȲ�ͬ��Ȼ��ӱߣ�������С������...һ��ʼ��Ϊÿ���ַ������2kλ��ֱ�Ӿ��ò�����ww����ô
// ö�ٲ��ֵı����㷨Ӧ����O(7*N^2)���ң�Ȼ��Ӹ�����֮���..������Ҳȷʵ�벻���õĶԱȷ�����...����˫ָ����ԣ��������
// �����������Ǿ�û��Ҫд��ww 

// ����⿨��Kruskal�����ٱ�five�������ǻ�RE�ģ��ռ俪��̫С�ˣ������˵Ļ����ض����в���...��͵�˱��˵Ĵ��뽻�ˣ�ʧ��w.. 
 
const int N = 2000 + 10, M = 1e6 * 5 + 10;
char str[N][10];
struct G {
	int u, v, w;
	G () {};
	G (int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator<(const G& g) const {
		return w < g.w;
	}
} graph[M]; // ���Կ��˴�ռ�w��RE�Ļ���������... 
// vector<G > graph;
struct unionFind {
	int bin[N];
	unionFind () {
		for (int i = 0; i < M; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		if (ask(x, y)) return;
		bin[anc(x)] = y;
	}
	bool ask(int x, int y){
		return anc(x) == anc(y);
	}
};
int main() {
	int n, diff, cnt;
	while (true) {
		scanf("%d", &n);
		if (!n) break;
		cnt = 0;
		for (int i = 1; i <= n; i++) scanf("%s", &str[i]);
		// ϲ���ּ����±�ӣ����Ӳ���w����������Ϊʲôj��i+1��ʼ����Ϊ���ͼ������ͼ��j��1��ʼ�ͻ��ظ����... 
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				// ע��diff���µ�λ�ã�Ӧ���������ַ����Ĳ�ͬһ�Ա�������ã�������֮ǰ��һ����������һ��... 
				diff = 0;
				// ���������ַ����ж��ٸ��ַ���ͬ����ͬ�ĸ�����Ϊ��Ȩ... 
				for (int c = 0; c < 7; c++) if (str[i][c] != str[j][c]) diff++;
				// �ַ���i���ַ���j�ı�Ȩ��Ϊ���ǵĲ�ͬ�ַ��ĸ���.. 
				graph[cnt++] = G(i, j, diff);
				// graph.push_back(G(i, j, diff));
			}
		}
		// ���������С������
		sort(graph, graph + cnt);
		// sort(graph.begin(), graph.end());
		unionFind uf;
		int res = 0;
		for (int i = 0; i < cnt; i++) {
			if (!uf.ask(graph[i].u, graph[i].v)) {
				uf.uni(graph[i].u, graph[i].v);
				res += graph[i].w; 
			}
		}
		// ��֭�����һ��ʼ��ûע��.. 
		printf("The highest possible quality is 1/%d.\n", res);
	}
	return 0;
}

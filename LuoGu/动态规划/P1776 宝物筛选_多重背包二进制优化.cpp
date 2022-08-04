#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// ���ر��������⣬����Ҫ����������Ż�... 

const int N = 4e4 + 10;
int f[N];
struct Node {
	int v, w;
	Node (int v, int w) : v(v), w(w) {};
	Node () {};
};
vector<Node > vec;
int main() {
	int n, m, v, w, c;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &v, &w, &c);
		// ����ȫ�������ٴ���ֱ�ӱ߶��ߴ������ 
		for (int k = 1; k <= c; k <<= 1) {
			c -= k;
			vec.push_back(Node(v * k, w * k)); 
		}
		if (c > 0) vec.push_back(Node(v * c, w * c)); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		for (int j = m; j >= vec[i].w; j--) {
			f[j] = max(f[j], f[j - vec[i].w] + vec[i].v);
		}
	}
	printf("%d", f[m]);
	return 0;
}

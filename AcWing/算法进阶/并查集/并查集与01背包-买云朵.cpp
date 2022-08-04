#include <iostream>
using namespace std;

// 题目的意思是要买一个云朵，就得把所有和这个云朵一个集合的云朵都买了
// 如果我们把云朵集合看成一个云朵，那么这就是个01背包问题了 
// 另外为了记录每个集合的总价值和总重量，需要将这些数据绑定到根节点上 

const int N = 10010;
int v[N], w[N];
int bin[N];
int f[N];
struct unionFind {
	unionFind() {for (int i = 1; i <= N; i++) bin[i] = i;}
	int anc(int x) {
		if (x != bin[x]) bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {bin[anc(x)] = anc(y);} 
	bool ask(int x, int y) {return anc(x) == anc(y);}
};
unionFind u; 
int main() {
	int n, m, money;
	cin >> n >> m >> money;
	// 先输入的是价值，后输入的是重量 
	for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
	while (m--) {
		int x, y;
		cin >> x >> y;
		int ax = u.anc(x) , ay = u.anc(y);
		// 因为可能存在祖先相同的情况，而我们合并的时候会进行价值绑定等操作，如果不判断下祖宗
		// 是否相同就会出现同一个祖宗的价值被绑定两次的情况 
		if (ax != ay) {
			// 将x的价格重量绑定到新ay上 
			w[ay] += w[ax];
			v[ay] += v[ax];
			// 将x的祖先指向y 
			u.uni(x, y);  
		} 
	}
	// 开始01背包
	for (int i = 1; i <= n; i++) {
		// 只算每个整体集合的价值 
		if (bin[i] == i) {
			for (int j = money; j >= v[i]; j--) {
				f[j] = max(f[j], f[j - v[i]] + w[i]);
			}
		}
	} 
	cout << f[money];
	return 0;
}

/*
输入样例：
5 3 10
3 10
3 10
3 10
5 100
10 1
1 3
3 2
4 2

输出样例：
1
*/

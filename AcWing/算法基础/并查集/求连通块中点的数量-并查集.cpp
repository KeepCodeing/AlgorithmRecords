#include <iostream>
#include <cstdio>
using namespace std;

// 要点就是如何统计一个集合中元素个数 

struct unionFind {
	int bin[100010], size[100010];
	unionFind() {
		for (int i = 1; i <= 100010; i++) bin[i] = i, size[i] = 1;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		// 插入的同时更新集合大小，但是要注意同一个
		// 集合互相插入不影响集合大小
		 if (anc(x) != anc(y)) {
		 	// 更新集合大小 
		 	size[anc(y)] += size[anc(x)];
		 	// 将x插入到y中 
			bin[anc(x)] = anc(y);
		 }
	}
	bool ask(int x, int y) {
		return anc(x) == anc(y);
	}
	int getSize(int x) {
		return size[anc(x)];
	}
};
unionFind u;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	char op[5];
	int a, b;
	while (n--) {
		scanf("%s", &op);
		if (op[0] == 'C') {
			scanf("%d%d", &a, &b);
			u.uni(a, b);  
			// 奇妙的输入技巧，可以发现Q1，Q2只有第二位
			// 不同，所以可以只对比第二位 
		} else if (op[1] == '1') {
			scanf("%d%d", &a, &b);
			printf("%s\n", u.ask(a, b) ? "Yes" : "No");
		} else {
			scanf("%d", &a);
			printf("%d\n", u.getSize(a));
		}
	}
	return 0;
}
/*
输入样例
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5

输出样例
Yes
2
3
*/

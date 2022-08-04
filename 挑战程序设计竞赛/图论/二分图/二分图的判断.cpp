#include <iostream>
#include <cstring>
using namespace std;

// 所谓二分图就是整个图都能用两个颜色表示，如果当前节点的颜色为红色，那么它的所有直接相连的点都该被染成蓝色，
// 相反，当前节点为蓝色与其相连的节点就要被染成红色，不允许任何一个节点的直接相连的点的颜色与当前点相同。
// 那么我们的思路就是枚举所有没被染色的点，然后进行DFS，将当前点的颜色染成color，与其相连点的颜色染成-color，
// 以此类推直到整个图都被染色了或者有任意两点的颜色产生了冲突。另外要注意给的图不一定就只有一个连通块，也
// 可能是个森林，所以color不仅可以用来标记颜色，也可以用来区分当前连通块中的点是否被染色... 

const int N = 1e5 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
int color[N];
void add(int ut, int vt) {
	e[idx] = vt, ex[idx] = head[ut], head[ut] = idx++;
}
bool dfs(int now, int c) {
	color[now] = c;
	for (int i = head[now]; i != -1; i = ex[i]) {
		int vt = e[i];
		if (color[vt] == color[now]) return false;
		// 这里的逻辑是如果当前点没有被染色（没有被访问），根据&&操作符的性质，继续前往下一个点染色，并且当
		// 当前点没被染色，但是存在颜色相同的点时，返回false  
		if (!color[vt] && !dfs(vt, -c)) return false;
//		color[vt] = -c;
//		dfs(vt, -c);
	}
	// 如果都被染色了就返回true 
	return true;
}
int main() {
	memset(head, -1, sizeof head);
	int m, ut, vt;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> ut >> vt;
		add(ut, vt), add(vt, ut);
	}
	cout << dfs(1, 1);
	return 0;
} 
/*
7
1 2
1 4
2 1
2 3
3 2
3 4
4 1
4 3
true

9
1 2
1 3
1 4
2 1
2 3
3 1
3 2
3 4
4 1
4 3
false

*/

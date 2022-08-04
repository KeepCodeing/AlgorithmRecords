#include <iostream>
using namespace std;

// 裸并查集题呢...当时还是小鬼的时候震撼我妈...不能停下来呢，虽然明天
// 依然一堆课什么的，总之这应该是今天的一道水题，也是最后一道了（写完洗澡睡觉） 

struct unionFind {
	int bin[1010]/*, sz[1010], dist[1010]*/;
//	unionFind() {
//		for (int i = 0; i < 1010; i++) bin[i] = i, sz[i] = 1, dist[i] = 0;
//	}
//	int anc(int x) {
//		if (x != bin[x]) dist[x] += dist[bin[x]], bin[x] = anc(bin[x]); // 这里写成了x=anc(bin[x])... 
//		return bin[x];
//	}
//	int uni(int x, int y) {
//		int ax = anc(x), by = anc(y);
//		dist[ax] = sz[by];
//		sz[by] += sz[ax];
//		// 这里写的也有点奇妙w，其实by的祖宗就是它自己，所以还不如直接写by，这里的意思是把ax合并到by上... 
//		bin[ax] = bin[by];
//	}
//	int getDist(int x, int y) {
//		int ax = anc(x), ay = anc(y);
//		if (ax != ay) return -1;
//		return max(0, abs(dist[ax] - dist[ay] - 1)); // 这里应该把-1写外面，不过应该没多大问题 
//	} 
	// 上面是带边权并查集的板子，写了遍（不想说默写w），有点小问题，算是理解了... 
	unionFind() {
		for (int i = 0; i < 1010; i++) bin[i] = i;
	}
	int anc(int x) {
		if (x == bin[x]) return x;
		bin[x] = anc(bin[x]);
		return bin[x];
	}
	void uni(int x, int y) {
		bin[anc(x)] = bin[anc(y)];
	}
	char ask(int x, int y) {
		return anc(x) == anc(y) ? 'Y' : 'N';
	}
};
unionFind u;
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	int x, y;
	while (m--) {
		cin >> x >> y;
		u.uni(x, y); 
	}
	while (q--) {
		cin >> x >> y;
		cout << u.ask(x, y) << endl;
	}
	return 0;
}

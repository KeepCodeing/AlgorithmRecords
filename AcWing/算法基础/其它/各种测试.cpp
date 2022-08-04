/*****单调栈******/ 
//#include <iostream>
//using namespace std;
//const int N = 100010;
//int stk[N];
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	int n;
//	cin >> n;
//	int tt = 0;
//	for (int i = 0; i < n; i++) {
//		int x;
//		cin >> x;
//		while (tt && stk[tt] > x) tt--;
//		if(tt) cout << stk[tt] << ' ';
//		else cout << -1 << ' ';
//		stk[++tt] = x;
//	}
//	return 0;
//}
/*****单链表******/ 
//#include <iostream>
//using namespace std;
//const int N = 100010;
//int head = -1, idx = 0;
//int e[N], ex[N];
//void add_to_head(int x) {
//	e[idx] = x;
//	ex[idx] = head;
//	head = idx;
//	idx++;
//}
//void add(int k, int x) {
//	e[idx] = x;
//	ex[idx] = ex[k];
//	ex[k] = idx;
//	idx++;
//}
//void removeVal(int k) {
//	ex[k] = ex[ex[k]];
//}
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0); 
//	int m;
//	cin >> m;
//	char code;
//	int x, y;
//	while (m--) {
//		cin >> code >> x;
//		if (code == 'H') {
//			add_to_head(x);
//		} else if (code == 'D') {
//			// 忘了移除头... 
//			if (!x) head = ex[head];
//			removeVal(x - 1);
//		} else {
//			cin >> y;
//			add(x - 1, y);
//		}
//	}
//	while (head != -1) {
//		cout << e[head] << ' ';
//		head = ex[head];
//	}
//	return 0;
//}
/*****双链表******/ 
//#include <iostream>
//using namespace std;
//const int N = 100010;
//int e[N], l[N], r[N];
//int idx = 2;
//
//void add(int pos, int val) {
//	e[idx] = val;
//	l[idx] = pos;
//	r[idx] = r[pos];
//	l[r[pos]] = idx;
//	r[pos] = idx;
//	idx++; 
//}
//
//void removeVal(int k) {
//	l[r[k]] = l[k];
//	r[l[k]] = r[k];
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0); 
//	r[0] = 1, l[1] = 0;
//	int n;
//	cin >> n;
//	string code;
//	int x, y;
//	while (n--) {		
//		cin >> code >> x;
//		if (code == "R") {
//			add(l[1], x);
//		} else if (code == "D") {
//			removeVal(x + 1);
//		} else if (code == "L") {
//			add(0, x);
//		} else if (code == "IL") {
//			cin >> y;
//			add(l[x + 1], y);
//		} else {
//			cin >> y;
//			add(x + 1, y);
//		}
//	}
//	int head = r[0];
//	// 注意链表结束标记... 
//	while(head != 1) {
//		cout << e[head] << ' ';
//		head = r[head];
//	}
//	return 0;
//}
/*****单调栈******/
//#include <iostream>
//using namespace std;
//const int N = 100010;
//
//int stk[N];
//
//int main() {
//	int n;
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	int tt = 0;
//	while (n--) {
//		int x;
//		cin >> x;
//		while (tt && stk[tt] >= x) tt--;
//		if (tt) cout << stk[tt] << ' ';
//		else cout << -1 << ' ';
//		stk[++tt] = x;
//	}
//	return 0;
//} 
/*****单调队列******/
//#include <iostream>
//using namespace std;
//const int N = 1000010;
//int nums[N], que[N];
//int main() {
//	int n, k;
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) cin >> nums[i];
//	int hh = 0, tt = -1;
//	for (int i = 0; i < n; i++) {
//		if (hh <= tt && i - k + 1 > que[hh]) hh++;
//		while (hh <= tt && nums[que[tt]] <= nums[i]) tt--;
//		que[++tt] = i;
//		if (i >= k - 1) cout << nums[que[hh]] << ' ';
//	} 
//	return 0;
//}
/*****Dijkstra最短路******/

// BFS可以用来求权值一样的最短路，而Dijkstra可以求任意权值的最短路
 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int INF = 0x3FFFFFFF;
struct Node {
	int v, w;
	Node (int v, int w) : v(v), w(w) {};
	bool operator<(const Node& n) const {
		if (v != n.v) return v < n.v;
		return w > n.w;
	}
};
vector<Node > graph[2550];
int *dist;
priority_queue<Node > que;
void dijkstra(int s) {
	dist[s] = 0;
	que.push((Node){s, 0});
	Node x(0, 0), y(0, 0);
	while (!que.empty()) {
		x = que.top();que.pop();
		for (int i = 0; i < graph[x.v].size(); i++) {
			y = graph[x.v][i];
			if (dist[y.v] > dist[x.v] + y.w) {
				dist[y.v] = dist[x.v] + y.w;
				que.push((Node){y.v, dist[y.v]});
			}
		}
	}
}
int main() {
	int n, m, s, t;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	dist = new int[n + 5];
	fill(dist, dist + n + 5, INF);
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		graph[u].push_back((Node){v, w});
		graph[v].push_back((Node){u, w});
	}
	dijkstra(s);
	cout << dist[t];
	delete[] dist;
	return 0;
}

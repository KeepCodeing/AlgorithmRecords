#include <iostream>
#include <cstring>
using namespace std;

// 和之前做个的一个题很类似，不过这个题有三个杯子了。那么思考下这个题有多少种操作，将C的水倒到A或B里，将A的水
// 倒到B或C里，将B的水倒到C或A里，如果A==B了，就说明能凑出来，否则就不能...
// 将C的水倒到A或B里，要么倒满A或B，要么只能倒入一部分（C的水不够了），其它操作应该也是同理... 

const int N = 2000, M = 110;
int s, n, m;
struct CUP {
	// 存放的abc的水的数量，和步数 
	int a, b, c, step;	
	CUP (int c, int a, int b, int step) : c(c), a(a), b(b), step(step) {};
	CUP () {};
} que[N];
bool checker(int a, int b) {
	return a == b && a != 0 && b != 0;
}
bool visited[M][M][M];
int bfs() {
	int qtop = 0, qback = 0;
	que[qtop] = CUP(s, 0, 0, 0);
	// 注意这里的visited，用来标记状态的 
	visited[s][0][0] = true;
	int at, bt, ct;
	while (qtop <= qback) {
		CUP now = que[qtop++];
		// cout << now.a << ' ' << now.b << ' ' << now.c << endl;
		// 注意这里的条件，是任意两个杯子能够均分就行了，之前做的题是要求两个杯子的水和给定值相同... 
		if (now.a == now.b && now.c == 0 || now.a == now.c && now.b == 0 || now.b == now.c && now.a == 0) return now.step;
		for (int i = 1; i <= 6; i++) {
			// 第一种情况，将C的水倒入A，B不变
			if (i == 1) {
				at = min(n, now.a + now.c); 
				bt = now.b;
				ct = max(0, now.c - (n - now.a));
			// 第二种情况，将C的水倒入B，A不变
			} else if (i == 2) {
					at = now.a;
				bt = min(m, now.b + now.c);
				ct = max(0, now.c - (m - now.b));
			// 第三种情况，将A的水倒入C，B不变
			} else if (i == 3) {
				at = max(0, now.a - (s - now.c));
				bt = now.b;
				ct = min(s, now.a + now.c);
			// 第四种情况，将A的水倒入B，C不变
			} else if (i == 4) {
				at = max(0, now.a - (m - now.b)); 
				bt = min(m, now.a + now.b);
				ct = now.c;
			// 第五种情况，将B的水倒入C，A不变
			} else if (i == 5) {
				at = now.a;
				bt = max(0, now.b - (s - now.c));
				ct = min(s, now.c + now.b);
			// 第六种情况，将B的水倒入A，C不变
			} else {
				at = min(n, now.a + now.b);
				bt = max(0, now.b - (n - now.a));
				ct = now.c; 
			}
			// 不要忘记入队和标记状态.. 
			if (!visited[at][bt][ct]) que[++qback] = CUP(ct, at, bt, now.step + 1), visited[at][bt][ct] = true;
		}
	}
	return -1;
}
int main() {
	while (true) {
		cin >> s >> n >> m;
		if (!s && !n && !m)	break;
		if (s % 2) {
			cout << "NO" << endl;
			continue;
		}
		memset(visited, 0, sizeof visited);
		int res = bfs();
		// 之前这里居然直接写的cout << bfs() << endl，而且还没发现... 
		if (res == -1) cout << "NO" << endl;
		else cout << res << endl;
	}
	return 0;
}

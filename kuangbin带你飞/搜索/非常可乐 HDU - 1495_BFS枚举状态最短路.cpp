#include <iostream>
#include <cstring>
using namespace std;

// ��֮ǰ������һ��������ƣ���������������������ˡ���ô˼����������ж����ֲ�������C��ˮ����A��B���A��ˮ
// ����B��C���B��ˮ����C��A����A==B�ˣ���˵���ܴճ���������Ͳ���...
// ��C��ˮ����A��B�Ҫô����A��B��Ҫôֻ�ܵ���һ���֣�C��ˮ�����ˣ�����������Ӧ��Ҳ��ͬ��... 

const int N = 2000, M = 110;
int s, n, m;
struct CUP {
	// ��ŵ�abc��ˮ���������Ͳ��� 
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
	// ע�������visited���������״̬�� 
	visited[s][0][0] = true;
	int at, bt, ct;
	while (qtop <= qback) {
		CUP now = que[qtop++];
		// cout << now.a << ' ' << now.b << ' ' << now.c << endl;
		// ע����������������������������ܹ����־����ˣ�֮ǰ��������Ҫ���������ӵ�ˮ�͸���ֵ��ͬ... 
		if (now.a == now.b && now.c == 0 || now.a == now.c && now.b == 0 || now.b == now.c && now.a == 0) return now.step;
		for (int i = 1; i <= 6; i++) {
			// ��һ���������C��ˮ����A��B����
			if (i == 1) {
				at = min(n, now.a + now.c); 
				bt = now.b;
				ct = max(0, now.c - (n - now.a));
			// �ڶ����������C��ˮ����B��A����
			} else if (i == 2) {
					at = now.a;
				bt = min(m, now.b + now.c);
				ct = max(0, now.c - (m - now.b));
			// �������������A��ˮ����C��B����
			} else if (i == 3) {
				at = max(0, now.a - (s - now.c));
				bt = now.b;
				ct = min(s, now.a + now.c);
			// �������������A��ˮ����B��C����
			} else if (i == 4) {
				at = max(0, now.a - (m - now.b)); 
				bt = min(m, now.a + now.b);
				ct = now.c;
			// �������������B��ˮ����C��A����
			} else if (i == 5) {
				at = now.a;
				bt = max(0, now.b - (s - now.c));
				ct = min(s, now.c + now.b);
			// �������������B��ˮ����A��C����
			} else {
				at = min(n, now.a + now.b);
				bt = max(0, now.b - (n - now.a));
				ct = now.c; 
			}
			// ��Ҫ������Ӻͱ��״̬.. 
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
		// ֮ǰ�����Ȼֱ��д��cout << bfs() << endl�����һ�û����... 
		if (res == -1) cout << "NO" << endl;
		else cout << res << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

// �������Ҫ�Ե�ͼ���д���..
// ��ʵ���ͼ�����з������Ϳ��Է��֣�������ʱ����ת��90�ȵģ���Ҫ��ԭֱ�Ӱ�����Ŀ
// �������ݾ���... 

const int N = 100;
bool graph[N][N];
int f[N][N];
int main() {
	int a, b, n, x, y;
	cin >> a >> b;
	cin >> n;
	while (n--) cin >> x >> y, graph[x][y] = true;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (graph[i][j]) f[i][j] = 0;
			else if (i == 1 && j == 1) f[i][j] = 1;
			else if (i == 1) f[i][j] = f[i][j - 1];
			else if (j == 1) f[i][j] = f[i - 1][j];
			else f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
	cout << f[a][b];
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

// ����fuxi��һ�����������Ǹ���ά���ñ�����ģ�� 

const int N = 510;
int f[N][N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int T;
	scanf("%d", &T);
	int sz, wei, val;
//	f[0][0] = 0; ����������Ҫ��ʼ������ͨ�������ó�ʼ�� 
	while (T--) {
		// ֱ���㣬����û��Ҫ������֮��Ķ��������� 
		scanf("%d%d%d", &sz, &wei, &val);
		// ����ѭ��д�����ˣ�д����>=1��Ȼ�����������������... 
		for (int i = n; i >= sz; i--) {
			for (int j = m; j >= wei; j--) {
				f[i][j] = max(f[i][j], f[i - sz][j - wei] + val);
			}
		}
	}
	printf("%d", f[n][m]);
	return 0;
}

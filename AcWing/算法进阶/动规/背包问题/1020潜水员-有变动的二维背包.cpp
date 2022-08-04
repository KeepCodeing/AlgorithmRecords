#include <iostream>
#include <cstring>
using namespace std;

// N��M�ֱ��ʾ�����͵��������ֵ 
const int N = 50, M = 150;

// ��������ĳ�ʼ����
// һ�������ֵ������Ĭ�ϳ�ʼ��Ϊ0���У���������Сֵ�����ⲻ��
// ��Ϊ0���ܾ�����Сֵ������һ��ѽ⼯ȫ����ʼ��ΪINF���ٰѵ�һ��
// �⼯��ʼ��Ϊ0 

int f[N][M];
int main() {
	int v, w;
	cin >> v >> w;
	int t;
	cin >> t;
	// ��ʼ���⼯ 
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	
	for (int q = 1; q <= t; q++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = N - 1; i >= a; i--) {
			for (int j = M - 1; j >= b; j--) {
				f[i][j] = min(f[i][j], f[i - a][j - b] + c);
			}
		}
	}
	// �����н⼯���ҵ���С���ѵķ��� 
	int res = 1e9;
	for (int i = v; i < N; i++) {
		for (int j = w; j < M; j++) {
			res = min(f[i][j], res);
		}
	}
	cout << res;
	return 0;
} 

/*
����������
5 60
5
3 36 120
10 25 129
5 50 250
1 45 130
4 20 119

���������
249
*/

#include <iostream>
using namespace std;

// ��ά���ñ���+��ȫ������û��ô����������Ӧ�þ��ǰ�˳��������գ����ģ� 
// �㲻����һ���ά���ñ������Ǽ�����ȫ�������ˣ���Ϊ�����������ֱ���
// �𰸶���...��������Ŀû���ر�˵�����Ǹ���ȫ����������˵����N��װ��...

// ���������ͨ��ά���ñ������Ѷ����ww 

const int N = 510;
int f[N][N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0); 
	int v, g;
	cin >> v >> g;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		// ��������������� 
		cin >> x >> y >> z;
		// ���ö����������
		for (int j = v; j >= y; j--) {
			for (int k = g; k >= z; k--) {
				f[j][k] = max(f[j][k], f[j - y][k - z] + x);
			}
		} 
//		for (int j = y; j <= v; j++) {
//			for (int k = z; k <= g; k++) {
//				f[j][k] = max(f[j][k], f[j - y][k - z] + x);
//			}
//		} 
	}
	cout << f[v][g];
	return 0;
}

#include <iostream>
#define endl '\n'
using namespace std;

// ׹�٣�˼·��������ȷ�ģ�������ô����̵ĳ�ȥ��ʱ��������...��������ļ��仯���������������ѵ�������߶�Զ�������
// ����������ܹ�������ʱ��̵����...ԭ�����������Ҫ����̰�İ������Ļ��ᶼ�����˽�ʡ�ռ䲢�Ҽ���ʱ�临�Ӷ�...�����
// ֱ�ӿ���ô�������ռ�ᱬ...�� 

const int N = 300000 + 10, M = 1000 + 10;
int f[N][M];
int m, s, tm;
int mtm = N, far = 0;
int dfs(int t, int m, int far) {
	
	if (t <= 0) return 0;
	
	if (f[t][m]) return f[t][m];
	
	if (far >= s) {
		cout << tm - t - 1<< endl;
	}
	
	// �����ʱ��Ϊt������ֵΪmʱ���ߵ���Զ���� 
	if (m - 10 >= 0) f[t][m] = max(f[t][m], dfs(t - 1, m - 10, far + 60) + 60);
	f[t][m] = max(f[t][m], dfs(t - 1, m, far + 17) + 17);
	f[t][m] = max(f[t][m], dfs(t - 1, m + 4, far));
	
	return f[t][m];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> s >> tm;
	far = dfs(tm, m, 0);
//	if (mtm != N) {
//		cout << "Yes" << endl;
//		cout << t - mtm;
//		return 0;
//	}
//	cout << "No" << endl;
//	cout << far << endl;
	
	return 0;
}

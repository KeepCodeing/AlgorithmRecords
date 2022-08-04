#include <iostream>
#include <cmath>
#include <cstring>
#define endl '\n'
using namespace std;
const int N = 1000 + 10;
typedef long long LL;

LL ct[N], we[N];
LL f[N][N];

// �������С��ƣ��ֵ������������Ҫ��������

int n, m;
LL dfs(int i, int d) {
	
	if (f[i][d] != -1) return f[i][d];
	
	// ���г��������ˣ����ﱾ��д��>n������Ϊi��0��ʼ����n��ʵ�����յ���... 
	if (i == n) return 0;
	
	// ����ʱ�䶼�����ˣ�ע�����Ｋֵ�����ã�֮ǰ����С�ˣ�����999999�����¼�ֵ�ȴ𰸻�С��󷵻صļ�ֵ... 
	// ע���������д��m + 1�����ܺ�i == n���ж�λ���й�... 
	if (d > m) return 1e9;
	 
	// d-1���ߵ�i + 1�������  �ڵ�i��������Ϣ��ע�������i + 1����Ϊi��0��ʼ������Ŀ˵�Ļ���
	// ��i-1�����ƶ���i�����ڵ�j�����ʱ�Ļ��� 
	return f[i][d] = min(dfs(i + 1, d + 1) + ct[i + 1] * we[d], dfs(i, d + 1));

} 

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ct[i];
	for (int i = 1; i <= m; i++) cin >> we[i];
	memset(f, -1, sizeof f);
	// ������Ǵ�0�㿪ʼ����Ȼ�󻨷������+1.... 
	cout << dfs(0, 1);
	return 0;
}


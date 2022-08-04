// �±��0��ʼ��LCS 
//#include <iostream>
//#include <cstring>
//#define endl '\n'
//using namespace std;
//
//string a, b;
//const int N = 2000 + 10;
//int f[N][N];
//
//int dfs(int i, int j) {
//	
//	if (i == -1 || j == -1) return 0;
//	
//	if (f[i][j] != -1) return f[i][j];
//	
//	int c = 0;
//
//	// ���i��jλ�õ��ַ���ȣ���ô����������еĳ��Ⱦ���+1�����򲻱� 
//	if (a[i] == b[j]) c = 1;
//	
//	return f[i][j] = max(max(dfs(i - 1, j), dfs(i, j - 1)), dfs(i - 1, j - 1) + c);
//}
//
//int main() {
//	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//	memset(f, -1, sizeof f);
//	int n, m;
//	cin >> n >> m;
//	cin >> a >> b;
//	int aLen = a.size(), bLen = b.size();
//	cout << dfs(aLen - 1, bLen - 1);
//	return 0;
//}

// �±��1��ʼ��LCS 
#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

const int N = 2000 + 10;
char a[N], b[N];
int f[N][N];

int dfs(int i, int j) {
	
	if (i == 0 || j == 0) return 0;
	
	if (f[i][j] != -1) return f[i][j];
	
	int c = 0;

	// ���i��jλ�õ��ַ���ȣ���ô����������еĳ��Ⱦ���+1�����򲻱� 
	if (a[i] == b[j]) c = 1;
	
	return f[i][j] = max(max(dfs(i - 1, j), dfs(i, j - 1)), dfs(i - 1, j - 1) + c);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	memset(f, -1, sizeof f);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	cout << dfs(n, m);
	return 0;
}

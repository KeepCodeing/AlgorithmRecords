#include <iostream>
#include <cstring>
#define endl '\n'
using namespace std;

// �����������±����⣺��ô�1��ʼ����Ϊ��0��ʼ�߽�ͱ��-1�ˣ����������ʵ��ͻ�re֮���...
// ��������dp����±���ö���1��ʼ... 

string a, b;
const int N = 2000 + 10;
int f[N][N];

int dfs(int i, int j) {
	
	// ����Ҫд����ǰ�棨����±겻����ô�����ǺϷ��ģ� 
	if (f[i][j] != -1) return f[i][j];
	
	// ��������ַ���Ϊ�գ���ô��Ҫ��Ϊ��һ���ַ����ķ������ǽ���һ���ַ��������ƹ�����Ҳ��Ҫ��һ��
	// �ַ����ĳ��ȴβ���
	if (i == 0) return f[i][j] = j;
	if (j == 0) return f[i][j] = i;
	
	// if (f[i][j] != -1) return f[i][j];
	
	int c = 1;
	
	if (a[i] == b[j]) c = 0;
	
	// �ֿ�д�ƺ������... 
	return f[i][j] = min(min(dfs(i - 1, j) + 1, dfs(i, j - 1) + 1), dfs(i - 1, j - 1) + c);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> a >> b;
	// ��֪��Ϊʲô�±��0��ʼ�ò�����ȷ�𰸣�������ǰ����˸����ַ����±��1��ʼ��... 
	// ���ܵ�ԭ����i = -1ʱj = -1֮��ģ����ֻ�re������Ҫ��֤�±겻����ô�����ܷ���...
	a = " " + a;
	b = " " + b;
	int aLen = a.size(), bLen = b.size();
	
	memset(f, -1, sizeof(f));
	cout << dfs(aLen, bLen) << endl;
	// ��ͨ��dp��õ���ֱ��ͨ�������ƺ�Ҳ�ǿ��Ե�... 
	// cout << f[aLen][bLen];
	return 0;
}

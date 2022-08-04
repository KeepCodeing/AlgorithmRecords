#include <iostream>
#include <vector>
using namespace std;

// ���ر������⣬�ؼ���������жϳ��˶��ٸ����⣬�Լ���ζ���Ƿ�ﵽ��m 
// ׹��... 

const int N = 20010;
typedef pair<int, int > PII;

int f[N];
struct cookie {
	int v, w;
	cookie(int v, int w) : v(v), w(w) {};
};
vector<cookie > vec;
int main() {
	int n, v;
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		int vi, ci;
		cin >> vi >> ci;
		for (int j = 1; j <= ci; j <<= 1) {
			vec.push_back(cookie(vi * j, 1));
			// �����̣�����д����/=��Ӧ������һ������һ���� 
			ci -= j;
		}
		if (ci > 0) vec.push_back(cookie(vi * ci, 1)); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		for (int j = v; j >= vec[i].v; j--) {
			f[j] = min(f[j], f[j - vec[i].v] + 1);
		}
	}
	cout << f[v];
	return 0;
} 

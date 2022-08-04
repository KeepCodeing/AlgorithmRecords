#include <iostream>
#include <cstdio> 
#include <vector>
#include <cmath>
using namespace std;

// �·�ϱ���������Ҫת����ʱ�䣬����ѵ�λͳһΪ���ӣ�Ȼ����scanf��ʽ������ 
// ϸ�ھ����ɰܣ������� 

const int N = 10010;
struct Cherry {
	int v, w, kind;
	Cherry(int v, int w, int kind) : v(v), w(w), kind(kind) {};
}; 
vector<Cherry > vec;
int f[N];
int main() {
	int t1, t2, m1, m2, n;
	int v; 
	scanf("%d:%d %d:%d %d", &t1, &m1, &t2, &m2, &n);
//	cout << endl;
//	printf("%d:%d %d:%d %d", t1, m1, t2, m2, n);
	// ��ȡ�����ݻ� 
	// ��ʲô��Ц��UDK���ɣ���֮ǰ�������㶼û�����ţ���A��һ���㣨��Ц�� 
	v = abs((t1 * 60 + m1) - (t2 * 60 + m2));
//	cout << endl << v << endl << endl;
	// ���ۣ���ֵ���������� 
	int t, c, p;
	for (int i = 1; i <= n; i++) {
		cin >> t >> c >> p;
		if (p == 0) {
			// ��ȫ����
			 vec.push_back(Cherry(t, c, 0)); 
		} else {
			if (p > 1) {
				// ���ر��� 
				for (int k = 1; k <= p; k <<= 1) {
					vec.push_back(Cherry(t * k, c * k, 1));
					p -= k; 
				}
				if (p > 0) vec.push_back(Cherry(t * p, c * p, 1)); 
			} else {
				// 01���� 
				vec.push_back(Cherry(t, c, 1)); 
			}
		}
	}
	// ��ģ��
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		// ����01�����Ͷ��ر��� 
		if (vec[i].kind) {
			for (int j = v; j >= vec[i].v; j--) {
				f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
			}
		} else {
			// ������ȫ���� 
			for (int j = vec[i].v; j <= v; j++) {
				f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
			}
		}
	} 
	cout << f[v];
	return 0;
}

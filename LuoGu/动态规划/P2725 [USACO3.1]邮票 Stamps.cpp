#include <iostream>
#include <vector>
using namespace std;

// էһ���Ǹ����ر����󷽰��������ǿ��԰Ѷ��ر���ֱ�Ӹĳ�01����������ֱ����ܿ��ܻᳬʱw 

const int N = 500010;
vector<int > vec;
int f[N];
int main() {
	int k, n;
	cin >> k >> n;
	// ���ر���ת01��������������涼���ø��ṹ��Ѽ�ֵ�������������������ֻ�ô��ֵ 
	for (int i = 1; i <= n; i++) {
		int x, t = k;
		cin >> x;
		// for (int j = 1; j <= t; j++) vec.push_back(x); 
		for (int j = 1; j <= t; j <<= 1) {
			vec.push_back(x * j);
			t -= j;
		}
		if (t > 0) vec.push_back(x * t); 
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) cout << vec[i] << endl;
	int num = 1;
	while (true) {
		fill(f, f + num + 10, 0);
		f[0] = 1;
		for (int i = 0; i < vLen; i++) {
			for (int j = num; j >= vec[i]; j--) {
				f[j] += f[j - vec[i]];
			}
		}
		if (num == 14) cout << f[num] << endl;
		if (!f[num]) break;
		num++;
	}
	cout << num;
	return 0;
}

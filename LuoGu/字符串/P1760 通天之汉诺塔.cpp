#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

// ��֪��ŵ�����ƶ�����Ϊ2^n - 1�������Ŀ�������ϴ���Ҫ�߾��ȼӷ����������ԼӸ�
// ������

// ���������Ĳ���ˣ��ܽ��¾���q^n��n�ж���λ1��q�ͳ��Լ����ٴ� 
void ksm(int n) {
	int r = 2, q = n;
	int res = 1;
	while (q) {
		if (q & 1) res = res * 1ll * r;
		q >>= 1;
		r = r * 1ll * r;
	} 
	cout << res;
} 

int main() {
	int n;
	cin >> n;
	// ���ӿ�ݵķ������������ڼ���2^n��|n|<2^14
	// �����ַ�����ת��
	stringstream ss;
	ss.precision(0);
	ss << fixed << pow(2.0L, n);
	// ת��Ϊ�ַ��� 
	string s = ss.str();
	s[s.size() - 1]--;
	cout << s << endl;
	return 0;
}

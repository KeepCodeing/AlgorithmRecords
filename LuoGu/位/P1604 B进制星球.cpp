#include <iostream>
using namespace std;

// ������˼·����ת����ʮ���ƣ�Ȼ�����������ת����ȥ... 
// �ݣ�����⻹Ҫ��߾�w����ֻ��py��w... 

typedef long long LL;
LL any2d(string str, int n) {
	LL res = 0, pf = 1;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] >= 'A' && str[i] <= 'Z') res += (10 + str[i] - 'A') * pf;
		else res += (str[i] - '0') * pf;
		pf *= n;
	}
	return res;
}
void d2any(LL d, int m) {
	string res;
	int temp;
	while (d) {
		temp = d % m;
		// ע�������-10����Ϊ����10֮���ģ����ʵҪ�����ĸ�Ǵ�0,1,2..֮��Ŀ�ʼ�ģ�����Ҫ��10.. 
		if (temp > 9) temp = 'A' + temp - 10;
		else res += temp + '0';
		d /= m;
	}
	// ��ʵ���Բ��÷��أ�ֱ�ӵ��������������w... 
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
}
int main() {
	int B;
	string a, b;
	cin >> B >> a >> b;
	d2any(any2d(a, B) + any2d(b, B), B);
	return 0;
}

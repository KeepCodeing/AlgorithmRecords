#include <iostream>
#include <algorithm>
using namespace std;

// ˼·���Ȱ�ԭ������ת��Ϊʮ��������Ȼ�����ö̳�����ʮ����תΪ�𰸽���.. 

// ���������ת��Ϊ10���ƣ�ת����ʽΪA���ƴӺ���ǰ��i��Ԫ�� * A^(i - 1)������ѭ��...������1010(B)ת10���ƣ�
// ����1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 = 10 
int any2d(string str, int n) {
	int sLen = str.size(), res = 0, pf = 1;
	for (int i = sLen - 1; i >= 0; i--) {
		if (str[i] >= 'A' && str[i] <= 'F') str[i] = str[i] - 'A' + '0' + 10;
		res += (str[i] - '0') * pf;
		pf *= n;
	}
	return res;
}
// ��ʮ����ת��Ϊ������ƣ���Ҫ�õ����Ƕ̳�����Ҳ���� 10 % m -> 10 / m...ע���ַ���ת��... 
string d2any(int d, int m) {
	string res = "";
	int temp;
	while (d) {
		temp = d % m;
		if (temp > 9) temp = 'A' + temp - 10;
		else temp += '0';
		res += (char)temp;
		d /= m;
	}
	int l = 0, r = res.size() - 1;
	// ���õ��Ĵ��ǵ��ŵģ�����Ҫת������... 
	while (l < r) swap(res[l++], res[r--]);
	return res;
}
int main() {
	int n, m;
	string str;
	cin >> n >> str >> m;
	// ��A����תΪ10���ƣ��ٰ�10����תΪB���� 
	cout << d2any(any2d(str, n), m);
	return 0;
}

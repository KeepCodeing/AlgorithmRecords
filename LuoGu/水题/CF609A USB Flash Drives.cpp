#include <iostream>
#include <algorithm>
using namespace std;

// ˮ����ߵ�����һ��ˮ����Ϊ��������Լ�̫�����˳ٳ�δ���...��ô�������Ǹ��������̰���ˣ�������ʹ���
// �й�̰�ĵ���Ŀ���������൱����... 

const int N = 110;
int usb[N];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> usb[i];
	sort(usb, usb + n);
	int res = 0;
	while (m > 0) m -= usb[--n], res++;
	cout << res;
	return 0;
}

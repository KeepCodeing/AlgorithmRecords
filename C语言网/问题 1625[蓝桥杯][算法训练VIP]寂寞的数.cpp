#include <iostream>
using namespace std;

// һ����ˢ��ü�į����
// �³�����map���ˣ����Ǻ����ֲ��ã��ж�ÿλ�������ֺ͵�ʱ���ж����Ƿ񳬹�n������ȥ
// ����Ҫ�ı�� 

int getNum(int x) {
	int res = 0;
	int xt = x;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	// ���̣�֮ǰ�����ˣ���Ȼ���ص���res+x����x�Ѿ�������... 
	return res + xt;
}
bool nums[10010];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	// ��ĿҪ�����С��n�ļ�į���� 
	for (int i = 1; i < n; i++) {
		int r = getNum(i);
		if (r >= n) continue;
		nums[r] = true;
	}
	for (int i = 1; i < n; i++) {
		if (!nums[i]) cout << i << endl;
	}
	return 0;
}

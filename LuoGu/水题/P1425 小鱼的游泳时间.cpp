#include <iostream>
using namespace std;

// ˮ�⣬Ȼ����Ц������֮ǰ����û�����Ҫ��..�������������w 

int my_abs (int m) {
	return m < 0 ? -m : m;
}
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	// ͳһת��Ϊ���ӣ���ת��ΪСʱ/���� 
	a *= 60, c *= 60;
	a += b, c += d;
	int m = my_abs(a - c);
	// ǰ��תΪСʱ������ȡ���õ�����... 
	cout << (int)(m / 60) << ' ' << m % 60;
	return 0;
}

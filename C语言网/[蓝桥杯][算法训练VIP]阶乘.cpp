#include <iostream>
using namespace std;

// ���µ�˼·���ǲ�������λ����������Ϊ����Ҫд�߾��ȣ�����ֱ��ֻ����%10000���������������Ա�֤�𰸲��ᱬint��
// Ȼ���Ȼ��ĿֻҪ���һ������������ô��ֱ�Ӱ�0ȥ��������...��֪��Ϊʲô��������Ӱ��𰸣���֮������������w.. 

typedef long long LL;
int main() {
	LL ans = 1;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		// ֻ����4λ���� 
		ans = (ans * i) % 10000;
		// ��λ��0ȥ��.. 
		while (!(ans % 10)) ans /= 10;
	}
	cout << ans % 10;
	return 0;
}

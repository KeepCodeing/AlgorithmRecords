#include <iostream>
using namespace std;

// ��Ŀ����˼��������������������ȷ��һ����Ŀ�Ľ⣬��ô�Ϳ��Խ��������⣬�����
// һ���ܽ�����ٸ�����... 

int main() {
	int n, a, b, c, res = 0;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		if (a + b + c >= 2) res++;
	}
	cout << res << endl;
	return 0;
}

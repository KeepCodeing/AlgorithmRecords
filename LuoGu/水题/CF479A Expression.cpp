#include <iostream>
using namespace std;

// ˮ��ڶ�ʮ������һ������ˮ��������5/22����������6/22��...��֮����һ���£���̫�ǵ��ϸ��²���ˮ��ȥ
// ��ʲô�ˣ���֮��������Ǹ�...�⼸�����ˮ����Ⱥ��ˣ���֪��ʲôʱ�������һ����ʼ... 

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(a + b + c, max(a + b * c, max(a * b + c, max((a + b) * c, max(a * (b + c), a * b * c))))) << endl;
	return 0;
}

#include <iostream>
#include <set>
using namespace std;

// ˮ���ʮ�ŵ�...��������������󲿷���ģ�壬�������Ǳ��Ƿ�ǿ... 

set<int > s;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	s.insert(a);
	s.insert(b);
	s.insert(c);
	s.insert(d);
	cout << 4 - s.size();
	return 0;
}

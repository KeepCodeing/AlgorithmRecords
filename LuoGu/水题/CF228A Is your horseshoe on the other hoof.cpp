#include <iostream>
#include <set>
using namespace std;

// 水题第十九弹...今天搞了下树，大部分套模板，不过还是比颓废强... 

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

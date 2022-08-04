#include <iostream>
using namespace std;

// 水题第二十弹，上一个做的水题正巧是5/22，而今天是6/22呢...总之又是一个月，不太记得上个月不做水题去
// 做什么了，总之其惯例的那个...这几天就用水题过度好了，不知道什么时候才是下一个开始... 

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << max(a + b + c, max(a + b * c, max(a * b + c, max((a + b) * c, max(a * (b + c), a * b * c))))) << endl;
	return 0;
}

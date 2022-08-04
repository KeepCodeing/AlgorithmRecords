#include <iostream>
#include <sstream>
using namespace std;

// 似乎是以前觉得麻烦give up了的题w，在刷洛谷讨论的时候又看到了...
// 总之各种作业还有课程都没搞的样子，等下又要上课了，或许是这别样的疫情
// 本five才有时间刷这些算法题吧... 

// 迫真模拟，倒是有点好久以前初学的时候写程序的感觉了，只不过现在考虑的比当初多多了就是了
// 通过字符流反复变换，将一开始的字符串搞成数字，然后判断运算符，用两个转成数字的变量进行
// 对应的操作，再把结果转成字符串，方便统计长度...，代码出乎意料不多，算是进步了罢... 

// 通过奇妙的输入处理可以省去很多不必要的操作，比如类型转换... 
 
// 字符串转数字，输入是当成字符串的 
int str2num(string n1) {
	int t;
	stringstream ss;
	ss << n1, ss >> t;
	return t;
}
// 数字转字符串，主要用来处理运算后的结果 
string num2str(int n1) {
	string t;
	stringstream ss;
	ss << n1, ss >> t;
	return t;
}
// 输出答案，一开始写发现输出这里一堆重复，所以就搞成一个函数了 
void printRes(int n, string n1, string n2, char op) {
	string re = num2str(n);
	int rLen = n1.size() + n2.size() + re.size() + 2;
	cout << n1 << op << n2 << '=' << re << endl;
	cout << rLen << endl;
}
// 核心函数，通过运算符进行对应操作并输出结果 
void solve(string op, string n) {
	string n1 = n, n2;
	if (n == "") cin >> n1;
	cin >> n2;
	// 对应操作符进行操作，就是在传参的时候传结果和操作符不同罢了 
	if (op == "a") printRes(str2num(n1) + str2num(n2), n1, n2, '+');
	else if (op == "b") printRes(str2num(n1) - str2num(n2), n1, n2, '-');
	else if (op == "c") printRes(str2num(n1) * str2num(n2), n1, n2, '*');
}
int main() {
	int T;
	cin >> T;
	string op, n1, pre = "";
	while (T--) {
		cin >> op;
		// 两种情况，一种是运算符开头，一种是数字开头，但是这两种情况的不同只有第一个输入
		// 的字符串是操作符还是数字，所以可以在solve()里做下判断，另外pre的更新也不是每一轮
		// 输入都更新，不然pre可能会变成数字，所以只要在输入是操作符时才进行更新 
		if (op == "a" || op == "b" || op == "c") pre = op, solve(op, "");
		else solve(pre, op); // 这里池沼了，多写了个输入... 
	}
	return 0;
}

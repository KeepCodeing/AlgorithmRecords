#include <iostream>
#include <sstream>
using namespace std;
int main() {
	stringstream ss;
	string result;
	// 字符串实数转实数 
	ss << "114.514";
	ss >> result;
	cout << result << endl;
	return 0;
}

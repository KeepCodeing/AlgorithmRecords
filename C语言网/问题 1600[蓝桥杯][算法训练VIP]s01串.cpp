#include <iostream>
using namespace std;

// 另外这个题也可以递推来解，当n>=3时，新的字符串就是Sn-2 + Sn-1 

int main() {
	int n;
	cin >> n;
	string res = "0";
	while (n--) {
		int rLen = res.size();
		for (int i = 0; i < rLen; i++) {
			if (res[i] == '0') res.replace(i, 1, "1");
			// 注意这里的replace方法，它的功能是从当前元素位置起，替换后k个元素，
			// 那么经过替换后，字符串的长度就改变了，比如n = 4时，由n = 3 -> 101
			// 可得变换后的字符串应该为01101，而当程序遇到第一个1时，会得到0101，
			// 这时字符串长度已经为4了，而下次替换也应该从第二个0开始，所以要把
			// 下标自增一次，再把字符串长度自增一次，不然会跳过后面的元素，也就是
			// 相当于一次平移操作 
			else res.replace(i, 1, "01"), i++, rLen++;  
		}	
	}
	cout << res;
	return 0;
}

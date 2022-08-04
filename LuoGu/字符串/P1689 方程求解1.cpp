#include <iostream>
#include <sstream>
using namespace std;

// 啊啊，颓废的一天呢...
// 正如上一个字符串模拟题，这个题本five蜜汁爆0了w，看了下那时候的代码还是比较
// naive的，当然那时候应该已经有一点题量了...另外作业等等也都堆起来了（电工和
// 高数），大概都很难罢...那么不考虑更久远的事，现在开心就好罢（然而到现在不会贪心） 
// 爆0可能是getline的原因...总之用cin读入算了 

// 坠毁... 

bool checker(char c) {
	return c >= '0' && c <= '9';
}
long str2num(string str) {
	long t;
	stringstream ss;
	ss << str, ss >> t;
	return t;
}
int main() {
	string str, temp;
	while (cin >> temp) str += temp;
	// cout << str;
	int sLen = str.size();
	int idx = str.find("+"), idx2 = str.find("=");
	if (idx == str.npos) idx = str.substr(0, idx2).find_last_of("-");
	// cout << endl;
	string s1 = str.substr(0, idx), s2 = str.substr(idx, idx2 - 1), s3 = str.substr(idx2 + 1);   
	long t;
	if (s1.find("?") != s1.npos) {
		t = str2num(s3) - str2num(s2);
		if (s1.find("-") != s1.npos) t *= -1;
		cout << t;
	} else if (s2.find("?") != s2.npos) {
		t = str2num(s3) - str2num(s1);
		if (s2.find("-") != s2.npos) t *= -1;
		cout << t;
	} else {
		t = str2num(s1) + str2num(s2);
		if (s3.find("-") != s3.npos) t *= -1;
		cout << t;
	}
	// cout << s1 << ' ' << s2 << ' ' << s3 << endl;  
	return 0;
}

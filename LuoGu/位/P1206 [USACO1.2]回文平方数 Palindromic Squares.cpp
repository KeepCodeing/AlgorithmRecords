#include <iostream>
#include <algorithm>
using namespace std;

// 趁热打铁，多A几道进制题... 
// 发现自己题意都搞错了..题目要求的是一个十进制数i，它的M进制数的平方是不是回文数... 
// 正确的题意：把i和i*i都转换为M进制的数，然后判断i*i在M进制下是不是回文数，如果是回文数，输出M进制下的i和i*i...

// 每行两个 B 进制的符合要求的数字，第二个数是第一个数的平方，且第二个数是回文数。意思就是转成B进制数判断其平方是不是回文... 

string d2any(int d, int m, bool flag) {
	// 短除法，要注意字母的转换什么的..
	int temp;
	string res;
	while (d) {
		temp = d % m;
		d /= m;
		if (temp > 9) temp = 'A' + temp - 10;
		else temp += '0';
		res += (char)temp;
	} 
	int l = 0, r = res.size() - 1;
	// 翻转答案的同时判断是否是回文串，不是就直接中断操作，是的话最后就会输出... 
	while (l < r) {
		if (res[l] != res[r] && flag) return "";
		swap(res[l++], res[r--]);
	}
	// 如果当前十进制数i转为M之后是个回文数，那么返回它的M进制形式，然后再判断i * i是不是回文数... 
	// 将该数转换为M进制后将其返回，然后再判断下这个数的平方是不是也是回文数... 
	// 然后又WA了w，题目不要求i是回文，只要求把i转成M进制的数，然后判断i * i转换为M进制之后是不是回文... 
	return res;
}
int main() {
	int B;
	string ra, rb;
	cin >> B;
	for (int i = 1; i <= 300; i++) {
		ra = d2any(i, B, false), rb = "";
		if (ra != "") rb = d2any(i * i, B, true);
		if (rb != "") cout << ra << ' ' << rb << endl;
	}
	return 0;
}
/*
1 1
2 4
3 9
11 121
22 484
101 10201
111 12321
121 14641
*/

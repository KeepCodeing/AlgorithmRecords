#include <iostream>
#include <map>
using namespace std;
map<char, char > mp;
int main() {
	// 是用加密后的字符串还原...，就是说输入的是加密后的字符串..之前映射的是原字符->加密字符.. 
	char c;
	for (int i = 0; i < 26; i++) {
		cin >> c;
		mp[c] = 'a' + i;
		mp[toupper(c)] = 'A' + i;
	} 
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen; i++) cout << mp[str[i]];
	return 0;
}
/*
y
x
m
d
a
c
i
k
n
t
j
h
q
l
g
o
u
f
s
z
p
w
b
r
e
v
*/

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

// TLE了一个点（绝望 ，不知道为什么w... 

const int N = 5 * 1e6 + 10;
vector<int > vec;
int nums[N];
int main() {
	int n, m, t, vLen, cnt = 0;
	char op;
	scanf("%d%d", &n, &m);
	while (n--) scanf("%1d", &nums[cnt++]);
//	while (n--) scanf("%1d", &t), vec.push_back(t);
	while (m--) {
		cin >> op;
		switch(op) {
//			case '*': vec.push_back(0); break;
//			case '/': vec.pop_back(); break; 
			case '*': cnt++; break;
			case '/': cnt--; break; 
			case '+':
				// 进位：如果当前位置为1，那么它加1就变成了0，依次类推，直到出现第一个0元素为止 
				vLen = cnt - 1;
				while (nums[vLen] == 1) nums[vLen--] = 0;
				nums[vLen] = 1;
//				vLen = vec.size() - 1;
//				while (vec[vLen] == 1) vec[vLen--] = 0;
//				vec[vLen] = 1;
				break;
			case '-':
				// 退位：如果当前位置为0，那么它-1就会变成1，以此类推，直到出现第一个1元素为止 
				vLen = cnt - 1;
				while (nums[vLen] == 0) nums[vLen--] = 1;
				nums[vLen] = 0;
//				vLen = vec.size() - 1;
//				while (vec[vLen] == 0) vec[vLen--] = 1;
//				vec[vLen] = 0;
				break;
		}
	}
	for (int i = 0; i < cnt; i++) cout << nums[i];
//	for (int i = 0; i < vec.size(); i++) cout << vec[i];
	return 0;
}
/*
4 2
1000
++
*/

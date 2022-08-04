#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

// 这个题目很坑的样子，按照日期来对比也没说明白是什么对比规则，或许
// 就是7~14位数字的大小

// 奇妙，TLE了... 

struct date {
	string str;
	string birthday;
	date (string str, string birthday) : str(str), birthday(birthday) {};
	bool operator<(const date& d) {
		if (birthday != d.birthday) return birthday > d.birthday;
		return str < d.str;
	}
};
vector<date > vec;
int main() {
	int n;
	cin >> n;
	while (n--) {
		string card;
		// 格式输入坠毁，还是截取罢了 
		// scanf("%.6s%.8s%.4s", &a, &b, &c);
		// 用scanf输入C++字符串需要先resize空间再从第1个地址输入..，依然TLE了 
		card.resize(19); 
		scanf("%s", &card[0]);
		// cout << card.substr(6, 8) << endl;
		// 截了十次甚至九次才截对的池沼 
		vec.push_back((date){card, card.substr(6, 8)});
	}
	sort(vec.begin(), vec.end());
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i].str; 
		if (i != vLen - 1) cout << endl;
	}
	return 0;
}

/*
5 
466272 30750327 1156 
215856 47220709 7978 
234804 58040107 8365 
404475 72770003 4980 
710351 40880309 3165 
*/

/*
404475 72770003 4980
234804 58040107 8365
215856 47220709 7978
710351 40880309 3165
466272 30750327 1156
*/

/*
710351 40880309 3165
404475 72770003 4980
466272 30750327 1156
215856 47220709 7978
234804 58040107 8365
*/

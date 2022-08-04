#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 还是模拟，用个map记录下对应关系就行 
// 似乎也可以用数组做，不过麻烦点 

map<int, string > mp;
// 用个矢量方便输出 
vector<string > vec;
void initMap() {
	mp[0] = "zero", mp[1] = "one", mp[2] = "two", mp[3] = "three";
	mp[4] = "four", mp[5] = "five", mp[6] = "six", mp[7] = "seven";
	mp[8] = "eight", mp[9] = "nine", mp[10] = "ten", mp[11] = "eleven";
	mp[12] = "twelve", mp[13] = "thirteen", mp[14] = "fourteen", mp[15] = "fifteen";
	mp[16] = "sixteen", mp[17] = "seventeen", mp[18] = "eighteen", mp[19] = "nineteen";
	// 谔谔，30~50不是和上面的数据连着的，考虑了下20~50之间有x0的情况，不过这些数都有映射了，不用
	// 担心出现x0 - 0的情况 
	mp[20] = "twenty", mp[30] = "thirty", mp[40] = "forty", mp[50] = "fifty";
}
int main() {
	initMap();
	int h, m;
	cin >> h >> m;
	if (mp.count(h)) {
		vec.push_back(mp[h]);
	} else {
		// 分解成字符串，注意这里insert的pos是个迭代器 
		// 在开始位置插入，先插入个位，然后减去个位，这样
		// 就能保证输出顺序，然而下面也这样搞反而不行，还是push_back罢了
		// 不知道当时是怎么想的，总之按顺序来就行 
		vec.push_back(mp[(h - h % 10)]);
		vec.push_back(mp[h % 10]);
		
//		vec.insert(vec.begin(), mp[h % 10]);
//		vec.insert(vec.begin(), mp[(h - h % 10)]);
	}
	if (mp.count(m)) {
		// 处理分为0的情况
		if (m == 0) vec.push_back("o'clock");
		else vec.push_back(mp[m]);
	} else {
		vec.push_back(mp[(m - m % 10)]);
		vec.push_back(mp[m % 10]);
		
	}
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i];
		if (i != vLen) cout << ' ';
	}
	return 0;
}

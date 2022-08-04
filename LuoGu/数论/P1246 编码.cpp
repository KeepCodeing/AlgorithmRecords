#include <iostream>
using namespace std;

// 想到了个前缀和做法，先试试 

// 我谔谔，思路都错了，其只能过类似abcd的字符串，而cde之类的不行，从一开始其就以为这个是按顺序来的（无能） 

typedef long long LL;
const int N = 1e5 + 10;
LL nums[N];
int main() {
	nums[0] = 0;
	for (int i = 1; i <= 1e5 + 10; i++) nums[i] += nums[i - 1] + i;
	string str;
	cin >> str;
	int sLen = str.size();
	for (int i = 0; i < sLen - 2; i++) {
		if (str[i] != str[i + 1] - 1) {
			cout << 0;
			return 0;
		}
	}
	if (str.size() > 6) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < sLen; i++) cnt += (int)str[i];
	int cal /* = 96 +  72 * (sLen - 1)*/;
	//if (sLen > 2) cal += 2 * (sLen - 2);
	//cout << cal << endl;
	// a + z - ab
	switch (sLen) {
		case 1 : cal = 96;break;
		case 2 : cal = 168;break;
		case 3 : cal = 242;break;
		case 4 : cal = 318;break;
		case 5 : cal = 396;break;
		case 6 : cal = 476;break;
	}
	cout << nums[cnt - cal] - nums[cnt - cal - 1];
	return 0;
} 

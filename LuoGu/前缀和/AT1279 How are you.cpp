#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 想到了一个排序+前缀和的做法，但是可能会超时，如果读写速度不行的话 

// 然而思路错了w，可能两个区间会断开，这样就没办法用上一次的值了 

typedef pair<int, int > PII;
vector<PII > vec;
int main() {
	int T;
	cin >> T;
	int s, t;
	while (T--) {
		cin >> s >> t;
		vec.push_back(PII(s, t)); 
	}
	sort(vec.begin(), vec.end());
	int vLen = vec.size();
	for (int i = 0; i < vLen; i++) {
		cout << vec[i].first << ' ' << vec[i].second << endl;
	}
	return 0;
} 

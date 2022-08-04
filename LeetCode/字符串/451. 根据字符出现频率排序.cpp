#include <iostream>
#include <algorithm>
using namespace std;

// 桶排，注意大小写字母混用，而且要降序排序，所以桶里的元素默认值应该为-1，然后对桶进行排序，再
// 按照下标输出...

// 第三道一次AC的题，今天不知不觉就成了加把劲骑士...AC了八个题，还有三个题没搞出来，总的来说今天没有痿
// 算是进步罢，虽然做的题都很水...然后就是口琴到现在还没送过来，希望明天能送过来，不然真只有等开课了才能
// 上手了.. 

class Solution {
public:
	typedef pair<int, char > PII;
    string frequencySort(string s) {
		int sLen = s.size(), INF = 0x3fffffff;
		if (!sLen) return "";
		string res = "";
		PII bucket[256];
		// 因为这里要搞个降序排序，所以把pair的first（计数）默认为无穷了，然后在后面进行桶排的时候
		// 判断下当前字母的first是不是INF，如果是INF，就把它改成0，然后计数为负数，这样可以少写个排序函数 
		for (int i = 0; i <256; i++) bucket[i].first = INF, bucket[i].second = (char)i;
		for (int i = 0; i < sLen; i++) {
			// 没排过，搞成负数，-1<-2<-3... 
			if (bucket[s[i]].first == INF) bucket[s[i]].first = 0;
			bucket[s[i]].first--;
		}
		sort(bucket, bucket + 256);
		for (int i = 0; i < 256; i++) {
			if (bucket[i].first == INF) break;
			// 桶输出... 
			while (bucket[i].first < 0) res += bucket[i].second, bucket[i].first++;
		}
		return res;
    }
}; 

int main() {
	Solution s = Solution();
	string str;
	cin >> str;
	cout << s.frequencySort(str); 
	return 0;
}

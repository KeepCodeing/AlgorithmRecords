#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 来一手离散化...
// 事实上桶排也可以，数组开的下... 
// 另外map默认按照key进行升序排序，所以也可以用map，map要是想用key排序的话可以把key和value抽离成一个
// pair，然后用vector存起来，再对这个vector按照value进行排序，就能得到相应的key的顺序了，也就是说sort
// 不能直接对map排序，但是我们可以将按value排序后的key拿来访问map 
 
typedef pair<int, int > PII;
vector<int > nums, temp;
// 二分，这里规定下标从1开始 
int findNum(int x) {
	return lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
}
PII cnts[1010];
int main() {
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) cin >> t, nums.push_back(t);
	// 把原数组做个备份，用temp来映射下标，nums来统计元素数量 
	temp = nums;
	// 排序和去重，离散化的核心步骤之一 
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end()); 
	int tLen = temp.size();
	// 利用二分将各位数字映射成下标，这里还用了count()函数来统计nums里要找的元素的数量 
	for (int i = 0; i < tLen; i++) cnts[findNum(temp[i])] = PII(temp[i], count(nums.begin(), nums.end(), temp[i]));
	for (int i = 1; i <= tLen; i++) cout << cnts[i].first << ' ' << cnts[i].second << endl;
	return 0;
}

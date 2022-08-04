#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 分析下，一共只存在两种情况，一种是两个区间完全不相干，另一种情况是
// 两个区间有一部分重叠或者被包含

// 第一种情况就意味着一个区间结尾值小于另一个区间开头值，这时是没办法进行合并操作的
// 而进行排序后就可以认为这个较靠前的区间可以舍弃掉，进而以接下来这个区间作为对比标准
// 继续重复操作 
// 而第二种情况就意味着两个区间可以合并，合并的操作就可以抽象为更新区间末尾值 

vector<pair<int, int > > segs;

void mergeVec(vector<pair<int, int > >& segs) {
	vector<pair<int, int > > res;
	// pair默认会按照first排序，这也方便了接下来合并、剔除区间的操作 
	sort(segs.begin(), segs.end());
	int st = -2e9, ed = -2e9;
	for (vector<pair<int, int > >::iterator it = segs.begin(); it != segs.end(); it++) {
		// 第一次ed<first其实就是初始化了第一个区间的长度，然后用第一个区间的末尾元素和后面的
		// 区间开头元素进行对比，如果第一个区间的末尾元素小于接下来这个区间的开头，说明这个区间
		// 整体小于接下来的这个区间，那么就把区间长度更新为这个更靠后的区间，因为这里无法进行合并
		// 所以还要把当前这个区间添加到结果里，表示多了一个区间没办法合并 
		if (ed < it->first) {
			// 考虑到只有一个区间的情况，这里需要判断下区间开头是否更新过，没更新就说明
			// 目前只有一个区间 
			if (st != -2e9) res.push_back({st, ed}); 
			st = it->first, ed = it->second;
		} else {
			// 相反，如果当前这个区间的结尾正好等于接下来的区间的结尾或者这个区间直接被接下来 
			// 的区间包含了，那么就意味着这两个区间可以合并，合并就指的是更新区间末尾值 
			ed = max(ed, it->second);	
		}
	}
	// 只有一个区间的情况特殊添加，对应上面的判断，如果结尾没变就说明只有一个区间，这时st只会被
	// 赋值一次，并且这样还能剔除掉区间为空的情况 
	if (st != -2e9) res.push_back({st, ed});
	segs = res; 
}

int main() {
	int n;
	cin >> n;
	int l, r;
	while (n--) {
		cin >> l >> r;
		segs.push_back({l, r}); 
	}
	mergeVec(segs);
	cout << segs.size();
	return 0;
}
/*
5
1 2
2 4
5 6
7 8
7 9

3
*/

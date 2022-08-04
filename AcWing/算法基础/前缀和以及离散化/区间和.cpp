#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 离散化，适用于区间求和问题，它的作用是将需要的数映射到数组的下标里
// 当值域较大但是所需原数个数较少时就可以使用。 

// 如何离散化：考虑下桶排，它利用下标映射相同值的元素，当元素值过大的时候
// 就用不了了，那么为什么要用桶排呢？因为桶排的效率高，查询只需要取下标即可
// 而离散化就是在此基础上进行了二分查找，经过排序去重，离散化基本上可以存储任意
// 大小的元素并且也能快速查找。我们可以将10映射到下标1,20到2,100到3,50000到4...
// 排序加去重后只需要用次二分就能找到对应元素的下标，然后执行后续操作 

// 用来存放所有元素 
vector<int > alls;
// 用来存放添加操作，pair可以简单的映射两对元素 
vector<pair<int, int > > add, query; 
const int N = 300010;
int a[N], s[N];
int find(int x){
    int l = 0, r = alls.size() - 1;
    while (l < r){
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	int x, c;
	while (n--) {
		cin >> x >> c;
		add.push_back({x, c}); 
		alls.push_back(x); 
	} 
	while (m--) {
		// 输入查询区间
		int l, r;
		cin >> l >> r;
		query.push_back({l, r});  
		// 这里之所以把查询区间的值也添加进去了，是因为添加操作的区间不一定就是完全包含了
		// 查询区间的数字，而我们要进行查询就得至少保证要有区间两端的数字 
		alls.push_back(l);
		alls.push_back(r);  
	}
	// 排序 
	sort(alls.begin(), alls.end());
	// 去重，unique()函数可以伪去重，它可以将重复元素移到数组最后，然后
	// 返回一个迭代器，指向第一个重复元素，那么利用erase方法即可删除重复元素
	alls.erase(unique(alls.begin(), alls.end()), alls.end());  
	// 处理插入 
	for (vector<pair<int, int > >::iterator it = add.begin(); it != add.end(); it++) {
		// 等查询和要添加的元素都去重完了再进行添加操作，这样可以避免重复 
		// 离散化后把值加上去 
		a[lower_bound(alls.begin(), alls.end(), it->first) - alls.begin() + 1] += it->second;
	}
	// 处理前缀和
	s[0] = 0;
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	} 
	// 处理询问
	for (vector<pair<int, int > >::iterator it = query.begin(); it != query.end(); it++) {
		int l = lower_bound(alls.begin(), alls.end(), it->first) - alls.begin() + 1;
		int r = lower_bound(alls.begin(), alls.end(), it->second) - alls.begin() + 1;
		cout << s[r] - s[l - 1] << endl;
	} 
	return 0;
}
/*
3 3
1 2
3 6
7 5
1 3
4 6
7 8
输出样例：
8
0
5
*/

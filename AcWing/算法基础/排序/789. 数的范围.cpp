#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 根据视屏里的两个模板来看，这两个模板分别对应了STL里的
// lower_bound和upper_bound，一个用来找第一个出现的该数
// 一个用来找第一个比该数大的数 

vector<int > vec;
int main() {
	int n, q;
	cin >> n >> q;
	int temp;
	while (n--) cin >> temp, vec.push_back(temp);
	int vLen = vec.size();
	while (q--) {
		cin >> temp;
		// 先找这个数的起始位置
		int sIndex = lower_bound(vec.begin(), vec.end(), temp) - vec.begin();
		// 如果这个数没有出现过，后面也不用找了 
		if (vec[sIndex] != temp) {
			cout << "-1 -1" << endl;
			continue;
		} 
		int eIndex = upper_bound(vec.begin(), vec.end(), temp) - vec.begin();
		if (eIndex >= vLen) {
			// 特判，如果这个数就是最大的数，upper_index会返回一个出界的下标
			// 踩坑二：如果末尾只有一个最大值，那么确实其起点位置和终点
			// 位置是一样的，但是如果有多个的话最后那个位置的最大值的位置才是我们要的位置 
			cout << sIndex << ' ' << vLen - 1 << endl;
			continue; 
		}
		// 踩坑一：看着运行完了就以为答案是正确的，然后坠毁了，结果
		// 发现没减一（因为找到的是第一个更大的值）... 
		cout << sIndex << ' ' << eIndex - 1 << endl;
	}  
	return 0;
}

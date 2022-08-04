#include <iostream>
#include <map>
using namespace std;

// 突然想到可以用map来做，因为去重和判断是否连续正好其都可以完成
// 而set只能完成去重 

// 不过题目给出的多余空格似乎是在暗示用字符串获取，但是数据范围没有
// 问题，不必多此一举 

// 不过感觉这个题也可以用异或来 

// 键连续表示数据默认排序过了，所以只用对比前一个键和
// 后一个键的差值即可 
map<int, int > mp;
int main() {
	int n;
	cin >> n;
	int t;
	while(cin >> t) {
		mp[t]++;
	} 
	int br, un;
	// 先取出第一个键，看下是不是重复了，不过题目说了
	// 最大号和最小号不会重复，所以这里其实不用判断 
	map<int, int >::iterator it = mp.begin();
	int last = it->first;
	if (mp[last] > 1) un = last;
	it++;
	// 再依次对比前一个键是不是比后一个键小1 
	while(it != mp.end()) {
		if (it->first - 1 != last) {
			br = last;
		}
		if (it->second > 1) {
			un = it->first;
		}
		last = it->first;
		it++;
	}
	// 最后还要把断掉的键补全 
	cout << br + 1 << ' ' << un;
	return 0;
}

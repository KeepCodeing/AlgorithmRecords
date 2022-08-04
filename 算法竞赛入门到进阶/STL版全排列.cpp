#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printPermutation(vector<int >& r) {
	for (int i = 0; i < r.size(); i++) cout << r[i] << ' ';
		cout << endl;
}
int main() {
	vector<int > r;
	r.push_back(1);
	r.push_back(2);
	r.push_back(3);
	// 使用bool next_permutation()函数可以按字典序一次生成一个全排列，如果
	// 还有全排列，就会返回true，否则返回false，所以而想要保住生成的顺序一定
	// 是从小到大，需要对排序集先进行一次排序，每次排序该函数都会将结果更新到
	// 原数组 
	sort(r.begin(), r.end()); 
	// 由于用while循环会直接进行排序，所以需要提交输出一下原排序集 
	printPermutation(r);
	while(next_permutation(r.begin(), r.end())) {
		printPermutation(r);
	}
	return 0;
}

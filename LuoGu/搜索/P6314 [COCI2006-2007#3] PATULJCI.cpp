#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// ao不容易写了个二分想水题解来着..结果发现已经满了...

// 题目的意思是给9个数，要去掉两个数使数列和为100，思路就是用二分，看下元素-100-当前数是不是能找到另一个数
// 如果能找到，就说明这两个数要被减去，记录这两个数原来的位置，输出即可.. 

const int N = 9;
typedef map<int, int >::iterator mit;
map<int, int > nums;
int ns[N];
int main() {
	int sn = 0;
	for (int i = 0; i < N; i++) cin >> ns[i], nums[ns[i]] = i, sn += ns[i];
	mit n1, n2, mt;
	for (mit it = nums.begin(); it != nums.end(); ++it) {
		// 假如和是160，要减去20和40，这里如果找到了20，也就是160 - 100 - 20，得到的就是40，就说明这两个数是多余的 
		mt = nums.lower_bound(sn - 100 - it->first);
		// 当然可能找不到另一个数返回的迭代器就是个错误的，所以这里还要验证下这两个数是不是真的多余了... 
		if (mt->first + it->first + 100 == sn) {
			n1 = it, n2 = mt;
			break;
		}
	}
	for (int i = 0; i < N; i++) {
		if (i == n1->second || i == n2->second) continue;
		cout << ns[i] << endl;
	}
	return 0;
}

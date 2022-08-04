#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

// 题目的意思应该是给一组数据，求出一个k使得所有数据模k的结果唯一
// 也就是和求公约数相反 

// 这题似乎和约数没有关系，当然也和本five推不出来有关系w，目前打算
// 先写个暴力，枚举k，然后看是不是有重复... 
// 果不其然TLEw，过了几个点拿了40...加了个小优化，成功拿到50w 

 
 
set<int > nset;
const int N = 5010;
int nums[N];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &nums[i]);
	}
	for (int i = 1;; i++) {
		nset.clear();
		for (int j = 1; j <= n; j++) {
			if (nset.count(nums[j] % i)) break;
			nset.insert(nums[j] % i); 
		} 
		if (nset.size() == n) {
			cout << i;
			break;
		} 
	}
//	while (n--) {
//		scanf("%d", &num);
//		for (int i = 2; i <= num / i; i++) {
//			if (!(num % i)) {
//				nset.insert(i);
//				if (i != num / i) nset.insert(num / i);  
//			}
//		}
//	}
//	for (set<int >::iterator it = nset.begin(); it != nset.end(); it++) {
//		cout << *it << ' ';
//	}
	return 0;
}

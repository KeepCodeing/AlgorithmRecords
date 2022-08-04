#include <iostream>
#include <bitset>
#include <cmath>
#include <map>
#include <set>
using namespace std;

// 想到了个最nt的暴力解法，不过数据范围是可以过的...
// 先算出最大的b是多少，也就是枚举的范围是[0, 2^b]（因为是递增输出的，所以可以这样），然后把这个范围里的十进制数转换为
// 二进制数，再来个n^2的枚举对比d，然后统计答案w... 
// 这里十进制转二进制应该不用自己写，直接bitset就行，注意转出来只保留b位... 
// 几个要注意的地方：bitset除了直接初始化的时候指定数字，也可以通过=赋值的方式指定数字，然后就是它不能用一个变量来指定
// 位数，必须用个常量，那么就可以写个循环，然后当i == b时搞一个常量（然而发现这样变量范围就有问题了w，干脆直接赋值给
// 一个常量，然而发现也不行，还是直接搞8位算了）.. 

map<int, set<int > > mp;
const int N = 300;
string strs[N];
int main() {
	int n, b, d, t;
	cin >> n >> b >> d;
	t = pow(2, b);
	bitset<8 > s;
	for (int i = 0; i < t; i++) {
		s = i;
		// 从头往后截取 
		strs[i] = s.to_string().substr(8 - b);
	}
	
	for (int i = 0; i < t; i ++) {
		bool flag = false;
		for (int j = 0; j < t; j++) {
			if (i != j) {
				int dt = 0;
				for (int k = 0; k < b; k++) {
					if (strs[i][k] != strs[j][k]) dt++;
				}
				if (dt >= d) {
					mp[i].insert(j);
//					cout << j << endl;
//					cout << strs[i] << ' ' << strs[j] << endl;
//					flag = true;
//					break;
				}
			}
		}
//		break;
//		if (!flag) cout << i << endl;
	}
	set<int > tres, res;
	for (int i = 1; i < t; i++) {
		if (mp[0].count(i)) tres.insert(i); 
		if (mp[i].count(0)) tres.insert(0); 
	}
	for (int i = 2; i < t; i++) {
		if (tres.count(mp[i])) res.insert(i); 
		if (mp[i].count(0)) res.insert(0); 
	}
//	for (set<int >::iterator it = res.begin(); it != res.end(); ++it) cout << *it << endl;
//	for (int i = 0; i < t; i++) {
//		bool flag = true;
//		for (int j = i + 1; j < t; j++) {
//			if (i != j) {
//				if (mp[i].count(j)) res.insert(j); 
//				if (mp[j].count(i)) res.insert(i); 
//			}
//		}
//		for (set<int >::iterator it = res.begin(); it != res.end(); ++it) cout << *it << endl;
//		break;
//		if (flag) cout << i << endl;
//	}
//	for (map<int, set<int > >::iterator it = mp.begin(); it != mp.end(); ++it) {
//		cout << it->first << ' ' << it->second << endl;
//	}
	return 0;
}

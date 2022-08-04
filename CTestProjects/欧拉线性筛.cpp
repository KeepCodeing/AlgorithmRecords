#include <iostream>
using namespace std;

// 区别于埃氏筛，欧拉筛的效率接近于O(n)，但是埃氏筛的话可以用下标存放元素是否是素数

// 谔谔，其实欧拉筛的标记数组也可以做到这种效果，而用一个result其实存的是所有的素数
// 但是这样的话没办法做到打表的效果，因为不能用下标取了 

int main() {
	// cnt用来更新素数 
	int n, cnt = 0;
	int *result, *visited;
	cin >> n;
	result = new int[n + 1]();
	visited = new int[n + 1]();
	// visited用来标记当前数是否是素数 
	for (int i = 2; i <= n; i++) {
		if (!visited[i]) {
			result[cnt++] = i;
		}
		for (int j = 0; j < cnt; j++) {
			// 防止标记出界，因为某个数的倍数可能大于n 
			if (i * result[j] > n) break;
			// 如果当前数是i的倍数，说明可以整除，即不为素数 
			visited[i * result[j]] = true;
			// 如果当前数可以整除某个素数，同样说明该数不为素数，这样即
			// 省去了重复访问的选择 
			if (i % result[j] == 0) break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) cout << i << endl;
	}
	delete[] visited;
	delete[] result;
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// 其似乎不知道公式：(最大值 - 最小值) / 公差 + 1就能得到等差数列的项数w，甚至一度以为
// 这个题只能暴力...那么排个序，然后算出最小公差就能使得项数最多..（这里应该是不能自己
// 加项的，不然长度就无穷大了..）.. 

int main() {
	int n;	
	scanf("%d", &n);
	// 其还疑惑没有数据范围怎么开数组w，没想到直接动态开了.. 
	int arr[n + 10];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int md = 0x3fffffff;
	sort(arr, arr + n);
	// 算最小公差，注意得先排序 
	for (int i = 1; i < n; i++) md = min(md, arr[i] - arr[i - 1]);
	if (md == 0) {
		printf("%d", n);
		return 0;
	}
	printf("%d", (arr[n - 1] - arr[0]) / md + 1);
	return 0;
}

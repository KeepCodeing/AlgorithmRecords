#include <iostream>
using namespace std;

// 突然感觉动规也有不少套路题... 

// 完全背包求方案数... 
// 又栽在了数据范围上，真有我的，题目说答案不超过2^64，所以本five以为int就够了（int只能够2^32-1）... 

const int N = 30, M = 10010;
int money[N];
long long f[M];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> money[i];
	f[0] = 1;
	// 套模板，n是货币类型数量，m是要凑的数，不管是01背包还是完全背包，这两层循环都是一个意思，只不过
	// 01背包从大到小，完全背包从小到大... 
	
	// 即要区分题目里给的“物品数量”，还有就是“物品价值与代价” 
	for (int i = 1; i <= n; i++) {
		for (int j = money[i]; j <= m; j++) {
			f[j] += f[j - money[i]];
		}
	}
	cout << f[m];
	return 0;
}

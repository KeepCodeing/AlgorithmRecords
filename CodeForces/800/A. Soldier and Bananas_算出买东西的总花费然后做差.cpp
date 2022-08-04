#include <iostream>
using namespace std;

// 洛谷上见过，不知道为什么在洛谷上不想刷，不知道是不是因为AC率之类的东西，总之为了这些可有可无的东西放弃思考了
// 很多题... 

int main() {
	// 买w个香蕉，第i个香蕉要i*w元，手上有n元 
	int k, n, w;
	cin >> k >> n >> w;
	int cost = 0, res = 0;
	for (int i = 1; i <= w; i++) cost += i * k;
	res = n - cost;
	// 手上的钱能买完就不用找朋友借钱，即借的钱为0，否则就是其相反数... 
	if (res >= 0) res = 0;
	else res = -res;
	cout << res << endl;
	return 0;
}

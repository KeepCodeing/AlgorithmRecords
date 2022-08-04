#include <iostream>
using namespace std;

// 补充下欧拉筛和埃氏筛的效率问题：当n = 10^6时，两个筛法差不多，埃氏筛略慢
// 当n = 10^7时，欧拉筛可以比埃氏筛快一倍左右 

int main() {
	// 1 1 2 3 5 8 13 21
	int n;
	cin >> n;
	bool flag = false;
	cout << n << '=';
	// 优化i <= n / i（不优化就是n），这样可以把时间复杂度降到logn到根号n，但是无法在循环里输出这个数字自身，因此
	// 需要判断这个数是否被除完了 
	for (int i = 2; i <= n / i; i++) {
		while (!(n % i)) {
			if (!flag) cout << i;
			else cout << '*' << i;
			n /= i;
			flag = true;
		}
	}
	// 如果这个数是一个较大的质因子 
	if (n > 1) cout << n; 
	return 0;
}

//#include <iostream>
//using namespace std;
//
//// 记得高中刷C语言题的时候刷过这种题，完完全全的不会就是了（无能），
//// 现在才知道所谓质因子就是指某一个数的因子能由若干个质数的乘积组成
//// 例如8 = 2*2*2... 
//
//// 这里写一个质素筛版本的，玩点有意思的，搞个链表存素数...
//
//const int N = 1000010;
//
//int head = -1, idx = 0, e[N], ex[N];
//void add_to_head(int x) {
//	e[idx] = x;
//	ex[idx] = head;
//	head = idx++;
//}
//// 无用的函数，只是为了让自己fuxi下单双链表的添加 
//void add(int k, int x) {
//	e[idx] = x;
//	ex[idx] = ex[k];
//	ex[k] = idx++;
//}
////void add2(int k, int x) {
////	e[idx] = x;
////	l[e] = k;
////	r[e] = r[k];
////	l[r[k]] = idx;
////	r[k] = idx;
////}
//
////bool primes[N];
////void getPrimes() {
////	primes[0] = primes[1] = true;
////	for (int i = 2; i <= 1000010; i++) {
////		if (primes[i]) continue;
////		add_to_head(i);
////		for (int j = i * 2; j <= 1000010; j += i) {
////			primes[j] = true;
////		}
////	}
////}
//
//int main() {
//	// getPrimes();
//	int n;
//	ios::sync_with_stdio(false);
//	cin.tie(0); 
//	
//	
//// 我谔谔，头添加的链表居然是反着来的（池沼），还是老老实实搞算了 
////	int cnt = 0;
//
////	while (head != -1) {
////		cout << e[head] << endl;
////		head = ex[head];
////		if (cnt > 20) break;
////		cnt++;
////	}
//	return 0;
//} 

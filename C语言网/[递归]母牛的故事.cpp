#include <iostream>
using namespace std;

// 似乎得看清楚问题的本质，这个题的本质就是变形的fib数列.. 
// 然而其想的是错的w，还是得打表验证... 

typedef unsigned long long ULL;
const int N = 60;
ULL f[N];
int main() {
	f[1] =  1, f[2] = 2, f[3] = 3, f[4] = 4;
	for (int i = 5; i < N; i++) f[i] = f[i - 1] + f[i - 3];
	int n;
	while (cin >> n, n) cout << f[n] << endl;
	return 0;
}

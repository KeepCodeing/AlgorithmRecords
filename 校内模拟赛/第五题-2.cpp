#include <cstdio>
using namespace std;
int main() {
	int n, a, b, c, cnt = 0;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	// cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; i++) 
		if (i % a && i % b && i % c) cnt++;
	printf("%d", cnt);
	return 0;
}

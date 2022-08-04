#include <iostream>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	if (!t) return 0;
	main();
	printf("%d ", t);
	return 0;
}

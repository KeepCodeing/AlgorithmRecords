#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int > st;
int main() {
	int num;
	while (scanf("%d", &num), num) st.insert(num);
	printf("%d\n", *(--(--st.end())));
	return 0;
}

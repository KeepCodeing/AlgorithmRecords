#include <iostream>
#include <cstdio>
using namespace std;
const int N = 10000 + 10;
int nums[N];
int main() {
	int sz, n, l, r, cnt = 0;
	scanf("%d%d", &sz, &n);
	while (n--) {
		scanf("%d%d", &l, &r);
		for (int i = l; i <= r; i++) nums[i] = 1;
	}
	// �ǵúþ�֮ǰ��һֱWA�������벻����Ϊʲô��Ȼ��ŷ�������0��ʼ������ȴ�Ǵ�1��ʼ��w.. 
	for (int i = 0; i <= sz; i++) {
		if (!nums[i]) cnt++;
	}
	printf("%d", cnt);
	return 0;
}

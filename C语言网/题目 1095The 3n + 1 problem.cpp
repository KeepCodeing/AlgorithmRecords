#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// ��ˢ��C�����������ˣ�ʹ���У���֮ǰ�ܾ��ü򵥣�һ������ʮ��������ʵ���������ű�����֮��о����̶ֳȵ���������ˢ��... 

int main() {
	int l, r;
	while (scanf("%d%d", &l, &r) != EOF) {
		printf("%d %d ", l, r);
		// �ӣ���Ŀû����������l < jʱ��Ҫ������л���... 
		if (l > r) swap(l, r);
		int mlen = 0, tlen = 0;
		for (int i = l, temp = l; i <= r; i++, temp = i) {
			tlen = 1;
			while (temp != 1) {
				
				if (temp % 2) temp = temp * 3 + 1;
				else temp /= 2;
				tlen++;
			}
			mlen = max(mlen, tlen);
		}
		printf("%d\n", mlen);
	}
	return 0;
}

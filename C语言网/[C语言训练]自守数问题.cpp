#include <iostream>
using namespace std;
const int N = 100;
int nums[N];
int numsz(int x) {
	int cnt = 0, res = 1;
	while (x) x /= 10, cnt++;
	while (cnt--) res *= 10;
	return res;
}
int main() {
	int cnt = 0;
	nums[cnt++] = 0;
	for (int i = 1; i <= 200000; i++) {
		// ƽ����Ȼ��ȡģ�ú�λ...����û�뵽������Ȼֱ�ӰѴ𰸸�������... 
		if ((i * 1ll * i) % numsz(i) == i) nums[cnt++] = i;
	}
	for (int i = 0; i < cnt; i++) {
		cout << nums[i];
		// ��������ո�w... 
		if (i != cnt - 1) cout << "  ";
	}
	return 0;
}

#include <iostream>
using namespace std;

// ԭ������һ��x�����10�����Ķ����ƾ��� 1010������ȡ�����õ� 0110�����룬
// 0101 + 1 = 0110��ԭ��ȡ����һ���������Ϳ���ʹx�ĵ�һλ1��������ж���������ȫ�෴���Ӷ�
// �ﵽ��ȡ��һ��1��Ŀ�ġ�������ԭ����ȥ���һ��1������ͳ��x>0ǰ�ж��ٸ�1���� 
 
int lowbit(int x) {
	return x & -x;
}
// ģ��̳���Ҳ������ 
int getOne(int x) {
	int t, cnt = 0;
	while (x) {
		t = x % 2;
		//x %= 2;
		if (t) cnt++;
		x >>= 1;
	}	
	return cnt;
} 
int main() {
	int n;
	cin >> n;
	int t, cnt;
	while (n--) {
		cnt = 0;
		cin >> t;
		// while (t) t -= lowbit(t), cnt++;
		cout << getOne(t) << ' ';
	}
	return 0;
}

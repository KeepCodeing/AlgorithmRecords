#include <iostream>

using namespace std;

// ������ĳ��18��ѧ����Ⱥ���ʵ��⣬���� 
// ��Ŀ��Ȼû�����ݷ�Χ���� 
// ��Ȼ�����ˣ�û��0��1... 

// ���˿�2min��ȷʵֻ�м����� 
int getPow(int n) {
	return n * n * n * n * n;
}
int main() {
//	int t, sumNum = 0;
//	for (int i = 0; i <= 2 * 0x3FFFFFFF; i++) {
//		t = i, sumNum = 0;
//		while (t) {
//			sumNum += getPow(t % 10);
//			t /= 10;
//		}
//		if (sumNum == i) cout << i << endl;
//	}
	cout << 4150 << endl << 4151 << endl <<
			54748 << endl <<
			92727 << endl <<
			93084 << endl <<
			194979;
	return 0;
}

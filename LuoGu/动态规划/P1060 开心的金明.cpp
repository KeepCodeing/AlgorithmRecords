#include <iostream>
#include <algorithm>
using namespace std;

// �����Ǹ������⣬����Ӧ�ÿ�����̰������׹��ww�������ǹ��˼����㣬��ʵ���������󣬿��Ա��ѣ�����û��Ҫ�� 

// ����...���Ǹ����˸����ӵ�01�������ˣ�������������xx���ޣ�Ҫ������ֵ�����͵���Ŀ��������01������
// ����Ҫ�ҶԱ�����������Ʒ�������money���Ǳ�������Ϊ�������������ֵ��ô���ģ�����Ʒ������Ҫ��
// �ĳ˻�������Ʒ 
 
struct elements {
	int value, level;
	int tot;
	bool operator<(const elements& e) {
		return level > e.level;
	}
	elements(int v = 0, int l = 0, int t = 0) {
		value = v, l = level, tot = t;
	}
};


// ��������һά�����Ż���д�� 
int f[50000];
int main() {
	int money, n;
	cin >> money >> n;
	elements *e = new elements[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> e[i].value >> e[i].level;
		// ����Ʒ��ֵ�����ȼ�ת��Ϊ��˻� 
		e[i].tot = e[i].value * e[i].level;
	}
	// ����ģ��дӦ�þ����� 
	for (int i = 1; i <= n; i++) {
		for (int j = money; j >= 0; j--) {
			// һά�����Ż�д����ֻ��¼����������ƺ�û��̫��ı� 
			// ���������money���������ۣ�����Ʒ�ļ�ֵ��������ֵ�������ȼ��ͼ۸�ĳ˻� 
			if (j >= e[i].value) {
				f[j] = max(f[j], f[j - e[i].value] + e[i].tot);
			} 
		}
	}
	cout << f[money];
	delete[] e;
	return 0;
}

//int main() {
//	int money, n;
//	long result = 0;
//	cin >> money >> n;
//	elements *e = new elements[n];
//	for (int i = 0; i < n; i++) {
//		cin >> e[i].value >> e[i].level;
//	}
//	sort(e, e + n);
//	for (int i = 0; i < n; i++) {
//		// �ȿ������ȼ�������ǰ����Ǯ����
//		int tV = e[i].value, tL = e[i].level; 
//		if (money >= tV) {
//			result += tV * tL;
//			money -= tV;
//		} 
//	}
//	cout << result;
//	delete[] e;
//	return 0;
//}

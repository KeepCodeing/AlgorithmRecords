#include <iostream>
using namespace std;
// ������һ����ӣ�����1, 3, 9, 27...3��ָ�������������룬������������������޵ģ���������Է�ֹ��߻�
// �ұߣ���Ҫ���û�����һ�����֣������������Ϸ�������������5�����9-3-1

// ��������Ŀ����˼��һ���ӣ���߷��������������룬�ұ߷��������������룬Ȼ������߻����ұ߼����û�����
// ��ֵ��ʹ��ƽ�⡣
// �����ⷨ���۲����ݣ����Ƿ���5<3^2�����ܵķ�����9-3-1,��һ�����֣�2<3^1�����ܵķ�����3-1���������ƣ�
// ���Է�������������Զ��������һ�������û�������������Ǹ����룬����ʣ�µ����������һ����ƽ����
// С�����������ƽ�����������в����������������Դ����ƣ��Ϳ������

// 6.1,��û��ѧ�� 
int maxNum;
int getMaxIndex(int num) {
	int index = 0;
	int max_w = 1;
	while (max_w <= num) {
		max_w *= 3;
		index++;
	}
	maxNum = max_w;
	return index;
}
int result[100];
void d(int level, int r, int maxLevel, int num) {
	
	if (level >= maxLevel + 1) return;
	if (r > num) return;
	result[level - 1] = r;
	if (r == num) {
		for (int i = 0; i < 10; i++) {
			
			cout << result[i] << ' ';
		}
		return;
	}
	d(level + 1, r + r * 3, maxLevel, num);
	result[level - 1] = 0;
}
int main() {
	int num;
	cin >> num;
	int maxIndex = getMaxIndex(num);
	d(1, 1, maxIndex, maxNum - num);
	return 0;
}

#include <iostream>
using namespace std;

// ��ˮ�⣬������ȫ����Ӳ��Ҳ����д������...�����õı���... 

// ����ACM ICPC���������ɻ����Ŀ���Ⱳ�Ӷ��μӲ������ֱ����ˣ�������һ�¸о�
// ������֮��Ĳ��ֻ�����ֳ����˲Ż����˸е���ν�İûڸ�...��������...�������ѷ��� 

int nums[10];
bool flag = false;
void dfs(int s1, int s2, int used1, int used2, int level) {
	if (used1 == 3 && used2 == 3) {
		if (s1 == s2) flag = true;
		return;
	}
	// 1��λ������ѡ���˲���ѡ����λ�����֣���ʱ2��λ�����ִ�1��λѡ���
	// �������￪ʼѡ 
	if (used1 < 3) dfs(s1 + nums[level], s2, used1 + 1, used2, level + 1);
	if (used2 < 3) dfs(s1, s2 + nums[level], used1, used2 + 1, level + 1);
}
int main() {
	for (int i = 1; i <= 6; i++) cin >> nums[i];
	dfs(0, 0, 0, 0, 1);
	if (flag) cout << "YeS";
	else cout << "nO";
	cout << endl;
	return 0;
}

#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
char nums[250];
int main() {
	int cnt = 0;
	char c;
	while (cin >> c) 
		if (c != '+') nums[cnt++] = c;
	sort(nums, nums + cnt);
	for (int i = 0; i < cnt - 1; i++) cout << nums[i] << '+';
	cout << nums[cnt - 1];
	return 0;
}
// �����ַ���ģ��̫�鷳��ֱ���������� 
//#include <iostream>
//using namespace std;
//
//// ˮ���ʮһ��..�ø�ʽ�����߱�����������..������ע�⵽��һ��ֻ������1,2,3��ϸ�ڣ�Ҳ����ֻ�ö����ʱ��
//// ͳ�������������ֵĸ���������... 
//
//void printNum(int n, char c) {
//	for (int i = 0; i < n; i++) {
//		if (i == 0) cout << c;
//		else cout << '+' << c;
//	}
//}
//int main() {
//	int a = 0, b = 0, c = 0;
//	char num;
//	while (cin >> num) {
//		if (num == '1') a++;
//		else if (num == '2') b++;
//		else if (num == '3') c++;
//	}
//	printNum(a, '1'), printNum(b, '2'), printNum(c, '3');
//	return 0;
//}

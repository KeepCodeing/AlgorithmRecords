#include <iostream>
using namespace std;
// λ�����ж�����ż��
// ԭ�����������������λ��Ϊ1��ż�������λ��Ϊ0,Ҳ����num & 1 == 1��Ϊ�������෴Ϊż�� 
bool checkNum(int num) {
	return num & 1;
}
int main() {
	int num;
	cin >> num;
	cout << checkNum(num) << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
// ����һ���ַ�����acbac�����ַ�������߶�����ұ߶���һ������Ϊ���Ĵ�
// д�����ж�ĳ���ַ��Ƿ��ǻ��Ĵ� 
// �ж��ַ��Ƿ��ǻ��Ĵ�ֻ��Ҫ���䷭ת�ٶԱ��Ƿ���ԭ�ַ�����ͬ���� 
bool hwStr(string s) {
	string temp = s;
	reverse(temp.begin(), temp.end());
	return (s == temp);
}
// ����1221�����ֳ�Ϊ�������֣�Ҫ�������λ��������������ʽ����
// ˼·�����԰���������Ϊijji��ʽ�����Կ��ɣ�i��Ϊ��ͷ���ܵ���0
// ���Կ���д����ѭ�������i*1000+j*100+j*10+i�������
// ���⿼�ǵ���Ҫ�ǻ��Ĵ�����ʽ����������ô����������Ĵ� 
void printHwNum() {
	for (int i = 1; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << (i*1000 + j * 100 + j * 10 + i) << endl; 
		}
	}
} 
int main() {
	printHwNum();
	return 0;
}

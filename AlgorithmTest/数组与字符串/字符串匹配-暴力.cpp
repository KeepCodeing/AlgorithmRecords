#include <iostream>
using namespace std;

// �����ⷨ��ʱ�临�Ӷ�ΪO(m*n) 
int strCmp(const char *str, const char *target) {
	if (!*target) return -1;
	char *p = (char*)str;
	int index;
	while (*p) {
		index = 1;
		char *start = p, *temp = (char*)target;
		while (*start && *temp && *start == *temp) {
			start++, temp++, index++;
		}
		if (!*temp) return index;
		p++;
	}
}
// ����hash���Ա��ַ������㷨��ʱ�临�Ӷ�ΪO(m+n)
// ˼·������ԭ�ַ���Ϊ"1234"��Ҫƥ����ַ���Ϊ"23"��
// ȡhash("12")��hash("23")�����жԱȣ����hash��ͬ��
// ����׼ȷ�İ�λ�Աȣ���hash��ͬ������ƶ�Ϊhash("23")��
// �Դ����ƣ�ֱ���Ա���ɡ�
// ���Կ���һ���������ڣ����ڴ�СΪn��ÿ����󻬶�1����λ
// Ȼ��Ա�hashֵ����ͬ������Աȴ������� 
int main() {
	cout << strCmp("Hello World", "World");
	return 0;
}

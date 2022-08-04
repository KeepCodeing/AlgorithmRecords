#include <iostream>
using namespace std;
// ������ƥ���ַ������ȴ��ַ���A��ͷ������ÿ�ζ��жϵ�ǰ�ַ��Ƿ���B�Ŀ�ͷ�ַ���ͬ��
// ��ͬ�����ƥ�䣬���ƥ��ʧ�ܣ��ͼ������������Ч��̫�� 
// RabinKarp�㷨�������Աȣ����Ȼ�ȡB�ַ�����hashֵ���ٴ�A�ַ���ͷ��ȡB�ַ������ȵ��ַ�
// �Ա����ǵ�hashֵ����ͬ��A�еĶԱȾ�����󻬶�һλ������㷨�����ܶ�����Ч���кܴ��
// ����������˼��ֵ��ѧϰ 
const int seed = 31;
// �Զ����hashֵ�㷨�������������������²��ܱ�֤hashֵΨһ 
long getHashCode(string str) {
	long hash = 0;
	for (int i = 0; i < str.size(); i++) hash = hash * seed + (int)str[i]; 
	return hash % 1145141919;
} 
// string ���Դ���substr������ЩС���⣬�ַ���"12345" ����substr(0,2)����"12"������substr(1,2)����"23"
// �����Լ�д��һ�� ��substr�����ƺ���ȡ���Ǵ�a��������b����λ���Ӵ����������±�a���±�b... 
string strSub(string str, int start, int end) {
	string result;
	for (int i = start; i <= end; i++) {
		result += str[i];
	}
	return result;
}
bool matchStr(string a, string b) {
	// ƥ���ַ��ĺ����㷨��ÿ����󻬶��Ա�hashֵ
	int aSize = a.size(), bSize = b.size(); 
	for (int i = 0; i < aSize - bSize + 1; i++) {
		// cout << i << ' ' << i + bSize << endl;
		// cout << strSub(a, i, i + bSize - 1) << endl;
		// subStr��������<=end���ʼ�һ 
		if (getHashCode(strSub(a, i, i + bSize - 1)) == getHashCode(b)) return true;
	}
	return false;
}
int main() {
	string a, b;
	 cin >> a >> b;
	 cout << matchStr(a, b) << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
// ����һ��offset����һ���ַ�����Ҫ�����һ���ַ��ƶ���ǰ��offset��

// ˼·��������ƺ����ƣ��ؼ�Ҫע��offset��ֵ����������0��������n��Ҳ���ܴ��ڻ���С��n��
// ��Բ�ͬ�������д��ͬ�Ĵ��� 

string offsetLow(string str, int offset) {
	// offsetС���ַ�������ʱ�����԰Ѻ�offset���ַ���ת��Ȼ�����
	// ǰn - offset���ַ�
	string result;
	for (int i = offset - 1; i <= str.size() - 1; i++) {
		result += str[i];
	} 
	for (int i = 0; i <= str.size() - offset - 1; i++) {
		result += str[i];
	}
	return result;
} 

string offsetHigh(string str, int offset) {
	// oHell
	// loHel
	// lloHe
	// elloH
	// Hello
	// oHell 
	// loHel
	// lloHe
	// elloH
	// Hello
	// ���offset����n�� ��ôֻ��Ҫ����offset%n�����ʷ�ǰ�漴��
	// ����Ϊoffset%n == 0������Ѿ����ų��ˣ� 
	string result;
	for (int i = str.size() - offset % str.size(); i <= str.size() - 1; i++) {
		result += str[i];
	}
	for (int i = 0; i <= str.size() - offset % str.size() - 1; i++) {
		result += str[i];
	}
	return result;
}

string rotateString(string str, int offset) {
	if (offset == 0) return str;
	if (offset % str.size() == 0) {
		reverse(str.begin(), str.end());
		return str;
	}
	if (offset < str.size()) return offsetLow(str, offset);
	if (offset > str.size()) return offsetHigh(str, offset);
}

int main() {

	cout << rotateString("Hello", 7);
	return 0;
}

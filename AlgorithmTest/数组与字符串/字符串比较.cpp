#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// �ַ����Աȷ���1������ 
// ʱ�临�Ӷ�O(nlogn) 
bool checkStrSort(string str1, string str2) {
	if (str1.length() != str2.length()) return false;
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());
	return str1 == str2;
}


// �ַ����Աȷ���2��Mapͳ���ַ�����
// �����ַ�����Ϊm��������ҪO(n)������ʱ�临�Ӷ�ΪO(m + n)
bool checkStrMap(string str1, string str2) {
	if (str1.length() != str2.length()) return false;
	map<char, int> m, m2;
	for (int i = 0; i < str1.length(); i++) {
		m[str1[i]]++, m2[str2[i]]++;
	}
	if (m.size() != m2.size()) return false;
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second != m2[it->first]) return false;
	}
	return true;
}

int main() {
	cout << checkStrMap("Hello", "Hello");
	return 0;
}

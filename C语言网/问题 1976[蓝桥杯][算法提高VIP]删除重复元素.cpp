#include <iostream>
#include <algorithm>
using namespace std;

// ���˻ᷢ�ֻ�ͳ���ַ��������ǲ�֪����ô��˳�����
// ���ڿ���Ͱ�żƴ���Ȼ���ٰ�ԭ�ַ������������ 

int bucket[300];
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) bucket[str[i]]++;
	for (int i = 0; i < str.size(); i++) if (bucket[str[i]] <= 1) cout << str[i];
	return 0;
}

#include <iostream>
using namespace std;

// ��Ϊ�Ѷ����ռ�-������û�зֵ�ˮ����...˼·������HashTable����Ͱ������Ȼ���ж��Ƿ��ܸպ����꼴�� 

int bucket[30];
int main() {
	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < a.size(); i++) bucket[a[i] - 'A']++;
	for (int i = 0; i < b.size(); i++) bucket[b[i] - 'A']++;
	for (int i = 0; i < c.size(); i++) bucket[c[i] - 'A']--;
	for (int i = 0; i < 26; i++) {
		if (bucket[i] != 0) {
			cout << "NO"; // Ҫ���������������ַ�... 
			return 0;
		}
	}
	cout << "YES";
	return 0;
}

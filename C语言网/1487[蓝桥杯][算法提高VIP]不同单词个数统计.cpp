#include <iostream>
#include <set>
using namespace std;

// ������map���ģ����о�û��Ҫ��ֻҪ����ȥ�ع��ܾ��� 
// ���ڿո�ֱ��while cin���У���getline���ܻ���������Ļ��з� 

set<string > st;
int main() {
	string str;
	while (cin >> str) {
		if (!st.count(str)) st.insert(str); 
	}
	cout << st.size();
	return 0;
}

#include <iostream>
using namespace std;

// Ӧ���Ǹ�dfs������״̬��ѡ��ѡ������˼·��д���� 

void dfs(string str) {
	if (str.size() == 5) {
		cout << str << endl;
		return;
	}
	dfs(str + "0");
	dfs(str + "1");
}

int main() {
	dfs("");
	return 0;
}

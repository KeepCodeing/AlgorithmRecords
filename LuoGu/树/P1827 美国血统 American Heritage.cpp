#include <iostream>
using namespace std;

// ����˼·���ȸ�����������õ����ڵ㣬�ٸ����������
// �õ����ҽڵ㣬Ȼ���ٸ�����������������ҽڵ� 

void dfs(string a, string b) {
	if (!b.size()) return;
	int pos = a.find(b[0]);
	// �ȴ����������ҵ���ǰ������Ȼ��ͨ��������ȡ����������
	// ���������� 
	dfs(a.substr(0, pos), b.substr(1, pos));
	// ���������� 
	dfs(a.substr(pos + 1), b.substr(pos + 1));
	cout << b[0]; 
}

int main() {
	string mid, fir;
	cin >> mid >> fir;
	dfs(mid, fir);
	return 0;
}

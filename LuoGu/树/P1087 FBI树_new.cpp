#include <iostream>
using namespace std;

// �������߶����Ľ���������������������Ľ��죬����������...

// �ռ俪С��WA��������... 
const int N = 1030;
char root[N * 4];
string str;
char getNode(string& str, int left, int right) {
	bool iszero = true, isone = true;
	for (int i = left; i <= right; i++) {
		if (str[i] == '0') isone = false;
		else if (str[i] == '1') iszero = false;
	}
	if (!iszero && !isone) return 'F';
	if (iszero) return 'B';
	return 'I';
}
// ����������һ����һ�������������������߶�����˼�뽨����Ӧ�ÿ��������ڴ󲿷�Ҫ��������գ����ģ� 
void build (int now, int left, int right) {
	if (left == right) {
		root[now] = getNode(str, left, right);
		return;
	}
	int mid = (left + right) / 2;
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	root[now] = getNode(str, left, right);
	build(l_node, left, mid);
	build(r_node, mid + 1, right);
}
string res;
// ֱ��ģ����������˼·������.. 
void pre_order(int now) {
	// ����д�������ȽϺã��߶�������left==right������Ҷ�ӽڵ��ϵ�����������Ҫ����������������
	// ��ģ����������˼·�жϵ�ǰ�ڵ��Ƿ�Ϊ�� 
	if (!root[now]) return; 
	// ��Ϊ����ָ�����Ե�ģ����һ���ڵ�ı����ʲô.. 
	int l_node = now * 2 + 1, r_node = now * 2 + 2;
	pre_order(l_node);
	pre_order(r_node);
	// ����Ҳ����ֱ����� 
	res += root[now];
}
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n >> str;
	build(0, 0, str.size() - 1);
//	for (int i = 0; root[i]; i++) cout << "root[" << i << "] = " << root[i] << endl;
	pre_order(0);
	cout << res;
	return 0;
}

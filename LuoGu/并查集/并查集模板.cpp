#include <iostream>
using namespace std;
struct unionFind {
	int *bin;
	// ��ʼ����ѯ���� 
	unionFind(int len) {
		bin = new int[len + 1];
		for (int i = 1; i <= len; i++) bin[i] = i;
	}
	// ��ѯ���ڽڵ㣬���������·��ѹ����������·��ѹ�������鼯�����Ч�ʿ��ܵ��³�ʱ
	// ����·��ѹ�������鼯��Ч�ʿ��Խӽ�O(n) 
	int anc(int x) {
		if (bin[x] == x) return x;
		// �����·��ѹ�����������һ�����ݹ��̣����������еĵ��binֵ��ֱ��ָ�����յĴ���Ԫ�ء� 
		return bin[x] = anc(bin[x]);
	}
	// �ϲ��ڵ�
	void uni(int x, int y) {
		bin[anc(x)] = anc(y);
	} 
	// ��ѯ�ڵ�
	void ask(int x, int y) {
		if (anc(x) == anc(y)) cout << "Yes" << endl;
		else cout << "No";
	} 
	// �ͷ��ڴ� 
	~ unionFind() {
		delete[] bin;
	}
};
int main() {
	return 0;
}

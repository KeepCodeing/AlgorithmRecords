#include <iostream>
using namespace std;

// ������ⷢ�־��Ǹ���ͨ���ѣ�������Ŀ�뵽֮����񿴵������Ƶ��⣬�뵽��ȫ����֮��ģ�����һ������˵
// ����һ��λ���������ֵĲ�̫����...�����������ֻ��дʮ��λ����Ϊunsigned long long����ʮ��λw��Ȼ����
// ���Ǹ���ͨ�����ˣ�˼����һλ�����Ƶ�������޷Ǿ���0,1��Ȼ������Ҫ������0����ôһλ�������ֻ��1��
// ��������λ���������Ϊһλֻ����1�������λҲֻ����10������11�ˣ���ôһ�����ɾͳ����ˣ����Ǹ�����w 
// ǰ��˵����Щ̫���ˣ�ʵ���Ͽ��Ի����ݹ��������Է�����ڵ����10���ҽڵ����11���������ƣ��ܸ�ǰ��
// ����˳�㹹��ڵ������... 

int x;
bool flag;
// ��unsigned long long��ֹ���... 
void dfs(unsigned long long val, int deepth) {
	if (deepth > 19 || flag) return;
	if (!(val % x)) {
		cout << val << endl;
		flag = true; // ������Ϻ����ĵݹ� 
		return;
	}
	dfs(val * 10, deepth + 1);
	dfs(val * 10 + 1, deepth + 1);
}
int main() {
	while (true) {
		flag = false;
		cin >> x;
		if (!x) break;
		dfs(1, 0);	
	}
	return 0;
}

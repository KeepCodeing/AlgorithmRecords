#include <iostream>
#include <vector>
using namespace std;

// ��ϱ��������ǰ�01��������ȫ���������ر��������һ��..
// �������ģ�弴�ɣ���Ϊ���ر�������ת��Ϊ01����������ʵ��������ֻ��
// ����������� 

const int N = 1010;
struct Good {
	int s, v, w;
	// ����...����v(v)д����v(s)... 
	Good(int s, int v, int w) : s(s), v(v), w(w) {};
};
vector<Good > vec;
int f[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		int vi, wi, si;
		cin >> vi >> wi >> si;
		if (si == -1) {
			// 01����ֱ��װ
			vec.push_back(Good(si, vi, wi));  
		} else if (si == 0) {
			// ��ȫ����Ҳ����ֱ��װ������Ҫ�����si�������ֱ������Ǵ����ʱ��ģ��
			vec.push_back(Good(si, vi, wi));
		} else {
			// ���ر���Ҫ�����01�����������ö������Ż�����
			for (int k = 1; k <= si; k <<= 1) {
				si -= k;
				vec.push_back(Good(-1, vi * k, wi * k)); 
			} 
			// ����Ӧ�ò���͵��д��if(si)��si���Ϊ��ifҲ��ִ�� 
			if (si > 0) vec.push_back(Good(-1, vi * si, wi * si)); 
		}
		
	}
	// �ֱ����������
	int vLen = vec.size();
	// ��0��ʼ����Ϊ�±� 
	for (int i = 0; i < vLen; i++) {
		// ������ر��� 
		if (vec[i].s == 0) {
			for (int j = vec[i].v; j <= v; j++) f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
		} else {
			// ����01���� 
			for (int j = v; j >= vec[i].v; j--) f[j] = max(f[j], f[j - vec[i].v] + vec[i].w);
		}
	}
	cout << f[v];
	return 0;
}

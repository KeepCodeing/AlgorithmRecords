#include <iostream>
#include <vector>
#include <set> 
using namespace std;
struct ele {
	int v, w;
	ele(int v, int w) : v(v), w(w) {};
};
// �����̣���Ȼ���˰�����ô����Ʒ��vector<vecotr> >������ʽʵ�ڲ�����⣬���ڻ�������vector��ͼ... 
vector<ele > vec[110];
set<int > ss;
int f[1010];
int main() {
	int n, v;
	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		int val, wei, g;
		cin >> val >> wei >> g;
		ss.insert(g); 
		vec[g].push_back(ele(val, wei)); 
	}
	// ����֮ǰֱ��д��n��������û�����ж�����ģ�����RE�������㣬��set���ж����飬�����˵�Ƚ��ݳޣ���ΪͰ
	// �͹��� 
	int vLen = ss.size();
	// ����Ҫע�⣬i��ʾ���ǵ�ǰ����һ�飬����Ŀ�������Ǵ�1��ʼ�ģ���������iҲҪ��1��ʼ 
	for (int i = 1; i <= vLen; i++) {
		int eLen = vec[i].size();
		// ����ö�٣���ö��Ǯ����ö����Ʒ 
		for (int j = v; j >= 1; j--) {
			for (int k = 0; k < eLen; k++) {
				// ע��Ҫ�ж��³���
				if (j >= vec[i][k].v) {
					// ���̣�����д����f[k]�������оٵĲ��ǵ�i����Ʒ�����Ž⣬���Ǽ۸�Ϊjʱ�����Ž�
					// ������ô˵�����01���������෴��˳���ϵ 
					f[j] = max(f[j], f[j - vec[i][k].v] + vec[i][k].w);
				} 
			}
		}
	}
	cout << f[v];
	return 0;
}

#include <iostream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;

// ������ƺ�����һ��������������Щ���� ��һ����ָ������������Ȩֵ�������û��ָ����㣬��Ҳ����˵������
// �������͵Ļ��ҽ��жһ���ֻҪ��һ������������...���������ƺ�ָ����ÿ����ĳ�ʼ��Ȩ��Ϊ1����ô����ֻ�е�ǰ��
// �ġ����롱Ϊ1��������ġ����롱Ϊ0���Ϳ��Կ����ɳ������ˣ�����ָ���ɳ�����Ϊ�������롱���ӲŽ����ɳڣ�������
// �ƺ�����һ�������ơ�
// ������һ��ʼ�ɻ���ɳ������ǡ����ÿ����ĳ�ʼֵ���ȵ�ǰ���1���ϻ��ʻ������ɳڲ����޷������ˡ��������������� 
// û����������ĳ�ʼֵ�趨����Ŀ˵1��Ԫ��0.5Ӣ������˼����һ��ʼ����ֻ��1��Ԫ��Ҫ���С��ɳڡ������õ�0.5Ӣ��... 
// Ȼ��������ô���ַ���תΪ�㣬��Ŀ���ıȽ����ģ���ֱ�Ӹ������ж����ַ�������ô��һ��mapӳ���¾�����... 

map<string, int > gp;
// ��Ŀ���ĵ���ͼ������Ϊ�˱������Կ��ĺܴ���w 
const int N = 3000 + 10, M = N * 2;
int head[N], e[M], ex[M], idx = 0;
bool visited[N];
double dist[N];
double w[M];
void add(int ut, int vt, double wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
bool spfa(int st) {
	// ������ݣ����Ҫ��γ�ʼ������Ȼ�͵�һ�����ݵ��������� 
	memset(dist, 0, sizeof dist);
	memset(visited, 0, sizeof visited);
	// ����һ��ʼ��1��λst���͵�Ǯ 
	dist[st] = 1.0;
	queue<int > que;
	que.push(st);
	while (que.size()) {
		int ut = que.front();que.pop();
		visited[ut] = false;
		// ���ͨ����·�ص��˵�ǰ�㲢�����ϵ�Ǯ�ܱ���˵���𰸴��� 
		if (ut == st && dist[st] > 1.0) return true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// ����һ��ʼд��ʱ����Щ�ɻ����š��򡱵����Ǹ�ʲô��˼����ָ����Ǯ���ٻ���˵��ǰ�ߵ�ֱֵ�Ӿ���
			// ����һ�ξ�����ֵ���������˼�ǵ�ǰ��һ��ʼΪ0��û��ֵ�������ֵ��ʲôȷ������Ȼ�������¼�Ȼ���
			// ֵ��1�������������ڽӱߵ�ֵ��ʵ����1*�Լ���ֵ...��ô�������Ǹ����㹫ʽ������...����������дЩ�ж�
			// ʲô�ģ������о��������Ի�׹����w����Ϊ����ֲ���ֻ�ᾭ��һ��w... 
			double wt = dist[ut] * w[i];
			if (dist[vt] < wt) {
				dist[vt] = wt;
				if (!visited[vt]) {
					visited[vt] = true;
					que.push(vt); 
				}
			} 
		}
	} 
	return false;
}
int main() {
	int n, m;
	string ut, vt;
	double wt;
	for (int T = 1;; T++) {
		cin >> n;
		if (!n) break;
		// ϲ���ּ��ĳ�ʼ��
		memset(head, -1, sizeof head);
		idx = 0; 
		// ����ӳ������� 
		for (int i = 1; i <= n; i++) cin >> ut, gp[ut] = i;
		cin >> m;
		// ��ͼ
		while (m--) {
			cin >> ut >> wt >> vt;
			// �����... 
			add(gp[ut], gp[vt], wt);
		} 
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			// ���������һ�ֻ��ҿ�����������˵���������� 
			if (spfa(i)) {
				cout << "Case " << T << ": Yes";
				flag = true;
				break;
			}
		}
		// ���л��Ҿ��������� 
		if (!flag) cout << "Case " << T << ": No";
		cout << endl;
	}
	return 0;
}

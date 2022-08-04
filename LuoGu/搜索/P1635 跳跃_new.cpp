#include <iostream>
#include <queue>
#include <map>
using namespace std;

// ��д����ǰ�İ취������õ����������·��д������queue���������飬ԭ���Ǹ�д������
// ����״̬�����±��������ò���������ջ��Ԫ�ظ�������Ϊ���ܵ�ǰ״̬��û�ߵ��˳��Ĳ�����
// �����״̬�Ͷ��������ˣ�ͬ������дҲ���ܻ���һЩ״̬�����˳�����û�е����⡣ 

typedef unsigned long long LL;
typedef pair<LL, int > PII; 
const int mod = 1000000007, out = 100000;
queue<PII > que;
map<LL, bool > vis;
int bfs(int start) {
	que.push(PII(start, 0)); 
	while (que.size()) {
		PII now = que.front(); que.pop();
		LL d = now.first;
		int step = now.second;
		// ����״̬������������ 
		if (step > out) continue;
		// ����ط��ܹ��˳�������Ӧ�þ���d == 1e9 + 7����d == 0... 
		if (!(d % mod)) return step;
		// ��ȡģ��������״̬��������Ϊֻ��1e9 + 7�ı��������յ㣬��ô����
		// 1e9 + 7����û�������.. 
		int nx1 = (d * 4 + 3) % mod, nx2 = (d * 8 + 7) % mod;
		// ��map��ɢ����� 
		if (!vis[nx1]) que.push(PII(nx1, step + 1)), vis[nx1] = true;
		if (!vis[nx2]) que.push(PII(nx2, step + 1)), vis[nx2] = true;  
	}
	return -1;
}
int main() {
	LL start;
	cin >> start;
	cout << bfs(start);
	return 0;
} 

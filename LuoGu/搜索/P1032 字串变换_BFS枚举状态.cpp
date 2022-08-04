#include <iostream>
#include <queue>
#include <map>
using namespace std;
     ;p
// һ��BFS����mapȥ�أ�Ȼ��find�ң�replace�滻������ȥʮ����״̬... 
// ���ǳ��˺ܶ�����w�������ǹ��ڵ�ǰ״̬�ı�Ƿ񣬵�ǰ״̬Ӧ����ö�������п���״̬��Ž��б�ǣ���������ö�ٵĹ���
// ��ֱ�ӱ���ˣ�����Ҳ���ܺ�����Ƚ������й�ϵ����ʵ��ǰ״̬�������֮ǰ����Ŀ�ﶼû�й��ģ���Ϊ�ӵ�ǰ״̬һ������
// ������״̬�����û��״̬��ô��ǰ״̬�����һ���ģ�������״̬���ܻ��ٲ�����ǰ״̬�����Ա������һ���ġ�
//       ... 

typedef pair<string, int > PII;
typedef pair<string, string > RPII;
const int N = 10;
map<string, bool > vis;
queue<PII > que;
int cnt = 0;
RPII rule[N]; 
int bfs(string st, string target) {
	queue<PII > que;
	que.push(PII(st, 0));
	while (que.size()) {
		PII now = que.front(); que.pop();
		if (now.first == target) return now.second;
		for (int i = 0; i < cnt; i++) {
			// Ҫ�滻�ɵ��ַ��� 
			string rs = rule[i].second;
			// ��ȡ�����ַ��ĳ��ȣ���ǰ���� 
			int ridx = rule[i].first.size(), step = now.second;
			// ע�����п��ܵĹ���Ҫö�٣�����aaaa b -> baaa, abaa, aaba, aaab... 
			for (int j = 0; j < now.first.size(); j++) {
				string ns = now.first;
				// �ҵ�ԭ�����ַ���λ�ã�ע������ĵڶ�������j������ʾ��j~�ַ���ĩβ���ң�Ҳ����˵ö������λ���ϵ�״̬... 
				int idx = ns.find(rule[i].first, j);
				// ������ܲ�����״̬����ֱ������ö�� 
				if (idx == ns.npos) break;
				// ��һ����ʵ���൱�ڻ����nx��ny... 
				ns.replace(idx, ridx, rs); 
				// ��֦�������ǰ������8��������(�ټ�һ���ͱ��9���ˣ���0��ʼ����10��������û�б�ʹ�ù��Ϳ������... 
				if (step <= 8 && !vis[ns]) que.push(PII(ns, step + 1)), vis[ns] = true;
			}
		}		
		// ע�⵱ǰ�ַ�������ǵ������Ӧ���������������й����滻�󣬶��������滻�Ĺ����оͱ����... 
		// ��������ǰд�����Ƶ���Ĵ��룬��û�ж�ԭ״̬���б�ǣ�����Ӧ��Ҳû���⣬��ǰ״̬����������״̬��������û����
		// �ٴ���ӣ�������״̬���ܻ��ٲ�����ǰ״̬������Ӧ��Ҳûʲô�󰭣���Ϊ��״̬������ǹ���... 
		vis[now.first] = true;
	} 
	return -1;
}
int main() {
	string a, b, ra, rb;
	cin >> a >> b;
	while (cin >> ra >> rb) rule[cnt++] = RPII(ra, rb);
	int res = bfs(a, b);
	if (res == -1) cout << "NO ANSWER!";
	else cout << res;
	return 0;
} 
//!vis[ns] && ע������жϣ�����������ģ���������Ǹ�vis[ns] = true���ǵ�ǰ����ַ�����ֻ�ᱻ
//Ӧ��һ������...�ɴ˿����뵽��AC���������ž���û�𰸵ĵ�w... 
//if (idx != ns.npos) {
//���ҵ���λ����ƫ��ԭ�ַ��������ȣ�Ȼ�����滻Ϊ���ַ���..��ע�����ȱ�ǵ�ǰ�ַ����������Ǳ���滻���... 
//vis[ns] = true;
//ns.replace(idx, ridx, rs);  
//if (step <= 8 && !vis[ns]) que.push(PII(ns, step + 1)), vis[ns] = true;
//}

#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// �о��Ǹ�BFSö��״̬��������ô�������Ǻ���˼·..
// �������㵼��׹����w... 
// map��״̬�ؿɻ�������һ�Σ�������˵���������κ������ 

#define x first
#define y second
typedef pair<string, int > PII;
// �������������Ա�Ƿ��ʷ񣬹ʶ���map��.. 
map<string, bool > visited;
int n;
int bfs(string str) {
	queue<PII > que;
	que.push(PII(str, 0));
	visited[str] = true;
	while (que.size()) {
		PII p = que.front();que.pop();
		// ����ҵ��˺Ϸ�״̬���������·����.. 
		if (p.x.find("2012") != p.x.npos) return p.y;
		// ����������ö��
		for (int i = 0; i < n - 1; i++) {
			// ������һ���ˣ�������ǳ�����β�����ַ��������ַ����������ֻ�����һ���ǻ���ߵģ�һ���ǻ��ұߵ�
			// Ȼ���д�����������������Ǹ�����...�����׹���ˣ���Ϊ�����û����֤�������������ȷ��.. 
//			string temp = p.x;
//			swap(temp[i - 1], temp[i]);
//			if (visited[temp]) continue;
//			visited[temp] = true;
//			que.push(PII(temp, p.y + 1)); 
			// ��ȷ������Ӧ����ֱ�Ӻ��ұߵ��ַ����жԱȾ����ˣ���Ϊ��ǰ�ַ�����߻���ʵ�Ǻ���һ���ַ��������ұ߻���
			// �ȼ۵ģ��ʶ�����ֱ��ʡȥ... 
			string temp = p.x;
			swap(temp[i + 1], temp[i]);
			if (visited[temp]) continue;
			visited[temp] = true;
			que.push(PII(temp, p.y + 1)); 
		}
	}
	return -1;
}
int main() {
	// ����n�;����������ˣ���Ȼ������Ϊʲô��Ҫָ��������w... 
	cin >> n;
	string str;
	cin >> str;
	cout << bfs(str);
	return 0;
}

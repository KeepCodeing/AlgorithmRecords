#include <iostream>
#include <algorithm> 
#include <queue>
#include <map>
using namespace std;

// ��֪������BFSö��״̬�᲻��ը...�ϴ����ĸ���ը��w.. 
// ��û��ըw�������û˵�ַ������ȣ����ҹ���.. 

typedef pair<string, int > PII;
string str, target;
map<string, bool > vis;
int bfs() {
	queue<PII > que;
	que.push(PII(str, 0));
	vis[str] = true;
	int sLen = str.size();
	while (que.size()) {
		PII now = que.front();que.pop();
		string ns = now.first;
		int nd = now.second;
		if (ns == target) return nd;
		// ö������״̬w..м����.. 
		for (int j = 0; j < sLen; j++) {
			if (ns[j] != '*') {
				if (j - 1 >= 0 && ns[j - 1] == '*') {
					string temp = ns;
					swap(temp[j], temp[j - 1]);
					if (!vis[temp]) que.push(PII(temp, nd + 1)), vis[temp] = true; 
				}
				if (j + 1 < sLen && ns[j + 1] == '*') {
					string temp = ns;
					swap(temp[j], temp[j + 1]);
					if (!vis[temp]) que.push(PII(temp, nd + 1)), vis[temp] = true; 
				}
				if (j - 2 >= 0 && ns[j - 2] == '*') {
					string temp = ns;
					swap(temp[j], temp[j - 2]);
					if (!vis[temp]) que.push(PII(temp, nd + 1)), vis[temp] = true; 
				}
				if (j + 2 < sLen && ns[j + 2] == '*') {
					string temp = ns;
					// ����д��j+1��.. 
					swap(temp[j], temp[j + 2]);
					if (!vis[temp]) que.push(PII(temp, nd + 1)), vis[temp] = true; 
				}
				if (j - 3 >= 0 && ns[j - 3] == '*') {
					string temp = ns;
					swap(temp[j], temp[j - 3]);
					if (!vis[temp]) que.push(PII(temp, nd + 1)), vis[temp] = true; 
				}
				if (j + 3 < sLen && ns[j + 3] == '*') {
					string temp = ns;
					swap(temp[j], temp[j + 3]);
					if (!vis[temp]) que.push(PII(temp, nd + 1)), vis[temp] = true; 
				}
			}
		}
	} 
	return 0;
}
int main() {
	cin >> str >> target;
	cout << bfs();
	return 0;
} 

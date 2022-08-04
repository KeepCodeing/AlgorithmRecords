#include <iostream>
#include <algorithm> 
#include <queue>
#include <map>
using namespace std;

// 不知道单纯BFS枚举状态会不会炸...上次做的个题炸了w.. 
// 并没有炸w，这个题没说字符串长度，侥幸过了.. 

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
		// 枚举所有状态w..屑代码.. 
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
					// 这里写成j+1了.. 
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

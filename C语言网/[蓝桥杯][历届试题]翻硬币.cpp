#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// ³¬Ê±×¹»ÙÁËw... 

typedef pair<string, int > PII;
queue<PII > que;
map<string, bool > vis;
int bfs(string str, string target) {
	int sLen = str.size();
	que.push(PII(str, 0));
	vis[str] = true;
	while (que.size()) {
		PII now = que.front();que.pop();
		string ns = now.first;
		int nt = now.second;
		if (ns == target) return nt;
		for (int i = 0; i < sLen - 1; i++) {
			string temp = ns;
			swap(temp[i], temp[i + 1]);
			if (vis[temp]) continue;
			vis[temp] = true;
			que.push(PII(temp, nt + 1)); 
		}
	} 
	return 0;
}
int main() {
	string str, target;
	cin >> str >> target;
	cout << bfs(str, target);
	return 0;
}

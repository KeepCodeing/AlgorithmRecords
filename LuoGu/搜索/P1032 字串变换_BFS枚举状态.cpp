#include <iostream>
#include <queue>
#include <map>
using namespace std;
     ;p
// 一眼BFS，用map去重，然后find找，replace替换，最后剪去十步的状态... 
// 还是出了很多问题w，首先是关于当前状态的标记否，当前状态应该在枚举完所有可能状态后才进行标记，而不是在枚举的过程
// 中直接标记了，不过也可能和这题比较特殊有关系，其实当前状态表不标记在之前的题目里都没有关心，因为从当前状态一定产生
// 的是新状态（如果没新状态那么当前状态表不标记一样的），而新状态可能会再产生当前状态，所以表不标记是一样的。
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
			// 要替换成的字符串 
			string rs = rule[i].second;
			// 获取规则字符的长度，当前步数 
			int ridx = rule[i].first.size(), step = now.second;
			// 注意所有可能的规则都要枚举，比如aaaa b -> baaa, abaa, aaba, aaab... 
			for (int j = 0; j < now.first.size(); j++) {
				string ns = now.first;
				// 找到原规则字符的位置，注意这里的第二个参数j，它表示从j~字符串末尾查找，也就是说枚举所有位置上的状态... 
				int idx = ns.find(rule[i].first, j);
				// 如果不能产生新状态，就直接跳出枚举 
				if (idx == ns.npos) break;
				// 这一步其实是相当于获得了nx，ny... 
				ns.replace(idx, ridx, rs); 
				// 剪枝，如果当前步数在8步及以内(再加一步就变成9步了，从0开始就是10步）而且没有被使用过就可以入队... 
				if (step <= 8 && !vis[ns]) que.push(PII(ns, step + 1)), vis[ns] = true;
			}
		}		
		// 注意当前字符串被标记的情况，应该是在它被用所有规则替换后，而不是在替换的过程中就标记了... 
		// 看了下以前写的类似的题的代码，都没有对原状态进行标记，这样应该也没问题，当前状态产生不了新状态，那它就没可能
		// 再次入队，否则新状态可能会再产生当前状态，不过应该也没什么大碍，因为新状态都被标记过了... 
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
//!vis[ns] && 注意这个判断，它是有问题的，结合下面那个vis[ns] = true，那当前这个字符串就只会被
//应用一个规则...由此可以想到其AC的两个点大概就是没答案的点w... 
//if (idx != ns.npos) {
//从找到的位置起偏移原字符串个长度，然后将它替换为新字符串..，注意是先标记当前字符串，而不是标记替换后的... 
//vis[ns] = true;
//ns.replace(idx, ridx, rs);  
//if (step <= 8 && !vis[ns]) que.push(PII(ns, step + 1)), vis[ns] = true;
//}

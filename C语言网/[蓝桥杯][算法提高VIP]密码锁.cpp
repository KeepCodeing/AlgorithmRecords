#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// 感觉是个BFS枚举状态，具体怎么样还不是很有思路..
// 画蛇添足导致坠毁了w... 
// map存状态必可活用于下一次（按理来说其适用于任何情况） 

#define x first
#define y second
typedef pair<string, int > PII;
// 估计用数组难以标记访问否，故而用map了.. 
map<string, bool > visited;
int n;
int bfs(string str) {
	queue<PII > que;
	que.push(PII(str, 0));
	visited[str] = true;
	while (que.size()) {
		PII p = que.front();que.pop();
		// 如果找到了合法状态，返回最短路步数.. 
		if (p.x.find("2012") != p.x.npos) return p.y;
		// 接下来进行枚举
		for (int i = 0; i < n - 1; i++) {
			// 这里多此一举了，其想的是除了首尾两个字符，其它字符都是有两种换法，一种是换左边的，一种是换右边的
			// 然后就写了这个东西和下面的那个东西...结果就坠毁了，因为其根本没有验证过这个做法的正确性.. 
//			string temp = p.x;
//			swap(temp[i - 1], temp[i]);
//			if (visited[temp]) continue;
//			visited[temp] = true;
//			que.push(PII(temp, p.y + 1)); 
			// 正确的做法应该是直接和右边的字符进行对比就行了，因为当前字符和左边换其实是和上一个字符和它的右边换是
			// 等价的，故而可以直接省去... 
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
	// 输入n就觉得有蹊跷了，既然是数字为什么还要指定长度呢w... 
	cin >> n;
	string str;
	cin >> str;
	cout << bfs(str);
	return 0;
}

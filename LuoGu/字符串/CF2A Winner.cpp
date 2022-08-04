#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 坠毁w，用map只能统计分数始终为正的情况，也就是说如果当前的最大分
// 那个元素被减分了，这个最大分是不会更新的，如果要更新需要加上如当前
// 加分是否为负，当前更新的名字是不是答案名字等等，然而这样更新了也会导致
// 答案更新，而这样更新并没什么用，因为可能加上负分之后别的名字的分就
// 更高了... 

vector<string > names;
map<string, int > scores;
int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string nm;
	int sc;
	int res = -0x3fffffff;
	string rname;
	while (n--) {
		cin >> nm >> sc;
		// if (!scores.count(nm)) names.push_back(nm);
		if (sc < 0) {
			if (rname == nm)
		}
		scores[nm] += sc; 
		if (scores[nm] > res) res = scores[nm], rname = nm;
	} 
//	int nLen = names.size();
//	int res = -0x3fffffff;
//	string rname;
//	for (int i = 0; i < nLen; i++) {
//		if (scores[names[i]] > res) res = scores[names[i]], rname = names[i];
//	}
	cout << rname << endl;
	return 0;
}

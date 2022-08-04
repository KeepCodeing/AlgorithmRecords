#include <iostream>
using namespace std;

// 大水题，可以用全排列硬怼，也可以写个爆搜...这里用的爆搜... 

// 不过ACM ICPC真是让人疑惑的题目，这辈子都参加不了这种比赛了（悲），一下感觉
// 人与人之间的差距只有体现出来了才会让人感到所谓的懊悔感...，啊啊啊...（语言匮乏） 

int nums[10];
bool flag = false;
void dfs(int s1, int s2, int used1, int used2, int level) {
	if (used1 == 3 && used2 == 3) {
		if (s1 == s2) flag = true;
		return;
	}
	// 1号位的数字选完了才能选二号位的数字，这时2号位的数字从1号位选完的
	// 数字那里开始选 
	if (used1 < 3) dfs(s1 + nums[level], s2, used1 + 1, used2, level + 1);
	if (used2 < 3) dfs(s1, s2 + nums[level], used1, used2 + 1, level + 1);
}
int main() {
	for (int i = 1; i <= 6; i++) cin >> nums[i];
	dfs(0, 0, 0, 0, 1);
	if (flag) cout << "YeS";
	else cout << "nO";
	cout << endl;
	return 0;
}

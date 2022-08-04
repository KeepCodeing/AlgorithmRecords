#include <iostream>
#include <algorithm>
using namespace std;

// 题目的意思就是要求将对方母舰的防御系统全部
// 破掉，破掉防御系统的规则是己方攻击力大于等于
// 地方防御力，高出的伤害不算，地方防御系统没了
// 才能造成伤害

// 可以考虑的贪心策略是用刚刚大于或者等于敌方
// 母舰防御力的攻击力攻击 

// 似乎是要大于才行 

// 主要是没考虑到0，以及两重循环暴力太低效了 

int *enemy, *me; 
int main() {
	int m, n;
	cin >> m >> n;
	enemy = new int[m];
	me = new int[n];
	for (int i = 0; i < m; i++) cin >> enemy[i];
	for (int i = 0; i < n; i++) cin >> me[i];
	// 排序，否则无法二分查找 
	sort(enemy, enemy + m);
	sort(me, me + n);
	// 谔谔，这里的暴力枚举可以优化，不然还会TLE，还有就是没考虑到0的情况 
	int index = 0;
	for (int i = 0; i < n; i++) {
		// 为0说明没有防御力，如果直接拿去减就浪费了攻击力 
		if (enemy[index] == 0) {
			index++;
			continue;
		}
		if (me[i] > enemy[index]) me[i] = 0, index++; 
	}
//	for (int i = 0; i < m; i++) {
//		// 二分查找应该刚好符合题目要求，大于或者等于的值（不行，
//		// 题目说的是大于...，如果有多个等于就会坠毁） 
//		// index = lower_bound(enemy, enemy + m, enemy[i]) - enemy;
//		// 直接暴力找 
//		for (int j = 0; j < n; j++) {
//			if (enemy[i] < me[j]) {
//				me[j] = 0;
//				break;
//			}
//		}
//	}
	int ans = 0;
	// 特判一下，如果打不完
	if (index < m) {
		cout << 0;
	} else {
		for (int i = 0; i < n; i++) ans += me[i];
		cout << ans;
	}
	delete[] enemy, me;
	return 0;
}

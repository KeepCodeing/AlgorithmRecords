#include <iostream>
using namespace std;

// 题目给出了个提示，说路长绝对是速度的公倍数，所以
// 可以先取到兔子不算睡觉时间的秒数和乌龟的秒数，然后关于兔子会睡几次
// 可以模拟下 

// 公倍数不是求膜，是除
 
int main() {
	int v1, v2, t, s, l;
	cin >> v1 >> v2 >> t >> s >> l;
	// 几个可能出现的坑 
	if (l <= 0) {
		cout << "D" << endl << 0;
		return 0;
	}
	// 如果兔子领先但是不睡觉，直接输出谁走的快即可 
	if (s == 0) {
		if (l / v1 > l / v2) {
			cout << "T" << endl << l / v2;
		} else if (l / v1 < l / v2){
			cout << "R" << endl << l / v1;
		} else {
			cout << "D" << endl << l / v2;
		}
		return 0;
	}
	// 如果兔子走不动，但是乌龟走的动，乌龟必赢 
	if (v1 <= 0 && v2 > 0) {
		cout << "T" << endl << l / v2;
		return 0;
	}
	// 如果乌龟走不动，这大概不可能，否则兔子也走不动，但是可能
	// 兔子一步就能到终点，就没有睡觉的情况了 
	if (v2 <= 0 && v1 > 0 && v1 >= l) {
		cout << "R" << endl << 1;
		return 0;
	}
	// 获取它们的基本秒数 
	int tuCnt = l / v1, guiCnt = l / v2;
	int l1 = 0, l2 = 0;
	int vt = v1, st = s;
	int sCnt = 0;
	bool flag = false;
	while (l1 < l || l2 < 1) {
		l2 += v2;
		l1 += vt;
		// 如果兔子领先了，让它睡觉 
		if (l1 - l2 >= t) {
			vt = 0;
			flag = true;
			// 这里因为一设置完就自减了，所以要加1 
			st = s + 1;
			// 兔子睡觉秒数自增 
			sCnt++;
		}
		// 兔子睡st秒 
		if (flag) st--;
		// 睡完了恢复行动力 
		if (st <= 0) vt = v1, flag = false;
	}
	tuCnt += sCnt * s;
	// 三种情况，时间相同，乌龟更快，兔子更快 
	if (tuCnt == guiCnt) cout << "D" << endl << tuCnt;
	else if (tuCnt > guiCnt) cout << "T" << endl << guiCnt;
	else cout << "R" << endl << tuCnt;
	return 0;
} 

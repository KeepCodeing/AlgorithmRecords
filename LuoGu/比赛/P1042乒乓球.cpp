#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// 数据量还蛮大的，但是感觉可以在输入的过程中处理 
struct score {
	int w;
	int l;
	// 结构体初始化方法变量名似乎不能一样 
	score(int w1 = 0, int l1 = 0) {
		w = w1, l = l1;
	}
};
class Solution {
public:
	vector<score > result1, result2;
	void resolve() {
		char c;
		score s1, s2;
		s1.w = s2.w = 0;
		s1.l = s2.l = 0;
		while ((c = getchar()) != 'E') {
			if (c != '\n') {
				if (c == 'L') s1.l++, s2.l++;
				if (c == 'W') s1.w++, s2.w++;
				if (s1.l == 11 || s1.w == 11) {
					result1.push_back(s1); 
					s1.l = s1.w = 0;
				} 
				if (s2.l == 21 || s2.w == 21) {
					result2.push_back(s2); 
					s2.l = s2.w = 0;
				} 
			}
		}
		for (int i = 0; i < result1.size(); i++) cout << result1[i].w << ':' << result1[i].l << endl;
		cout << s1.w << ':' << s1.l << endl;
		cout << endl;
		for (int i = 0; i < result2.size(); i++) cout << result2[i].w << ':' << result2[i].l << endl;
		cout << s2.w << ':' << s2.l;
	}
};
int main() {
	Solution s = Solution();
	s.resolve();
	return 0;
}

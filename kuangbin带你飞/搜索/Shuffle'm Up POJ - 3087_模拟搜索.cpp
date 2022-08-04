#include <iostream>
using namespace std;

// 大概是个模拟题，不过要自己判断是否真的完全无法得出答案，可以设置个计数器什么的... 
// 看错题了导致第二个样例过不去w，又看了遍才发现原字符串不能发生改变，后面s1,s2都是从原字符串衍生的... 

// 幸运数字w 
const int N = 777;
int main() {
	int T, len, cnt;
	string s1, s2, s12;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> len;
		cin >> s1 >> s2 >> s12;
		// 看错题为了过样例改成了1过w... 
		cnt = 0; 
		while (cnt < N) {
			// 如果新字符串相等，就退出，注意这里是先判断的相等，后进行自增，因为如果一开始s1+s2==s12变换的次数就是0... 
			if (s1 + s2 == s12) {
				cout << i << ' ' << cnt << endl;
				break;
			}
			// 构造新串，这里不能改原串，得用个新串暂存下... 
			string temp = "";
			for (int i = 0; i < len; i++) temp = temp + s2[i] + s1[i];
			s1 = temp.substr(0, len), s2 = temp.substr(len);  
			cnt++;
		}
		if (cnt == N) cout << i << ' ' << -1 << endl;
	}
	return 0;
}

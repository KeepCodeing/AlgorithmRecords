#include <iostream>
using namespace std;

// 记得以前群里似乎发过这个题..
// 设F(i, j, k)表示第i秒，魔法值为j时的第k种状态（休息或不休息，这里应该要区分休息和不休息以及使用魔法）所走的最大距离 
// F(i, j, k)有以下几种决策， 
// 设F(i, PII(j, k, m))表示第i秒，走的最远距离为j，第k种状态法力值为m的情况
// 之类应该把状态单独作为一维使用.. 
// F(i, PII(j, 0, m)) = max{F(i - 1, PII(j, 0, m + 4)), F(i - 1, PII(j, 1, m + 4)), F(i - 1, PII(j, 2, m + 4))}，不走的情况，距离不变，但是法力值+4
// F(i, PII(j, 1, m)) = max{F(i - 1, PII(j, 0, m)), F(i - 1, PII(j, 1, m)), F(i - 1, PII(j, 2, m))} + 17，走的情况，从上一秒走/不走/用魔法走的距离里选个最大的
// F(i, PII(j, 1, m)) = max{F(i - 1, PII(j, 0, m - 10)), F(i - 1, PII(j, 1, m - 10)), F(i - 1, PII(j, 2, m - 10))} + 60用魔法走的情况，同样是在上一秒的三个
// 状态里选 

// 又想复杂了w，正确做法是直接贪心，先无限闪现，然后法力不够了再休息。跑完闪现的逻辑之后再对原数组跑遍徒步的逻辑...详情见下面的代码...用神奇的方式骗了40分w 

const int N = 300000 + 10;
struct Status {
	int far, m, tm;
	Status (int far, int m, int tm) : far(far), m(m), tm(tm) {};
	Status () {};
} f[N][3];
Status my_max(Status s1, Status s2, Status s3, int flag, int tm) {
	Status m_s;
	if (s1.far > s2.far) m_s = s1;
	else m_s = s2;
	if (m_s.far < s3.far) m_s = s3;
	if (flag == 0) m_s.m += 4;
	else if (flag == 1) m_s.far += 17;
	else if (flag == 2) {
		// 如果可以用魔法，就用魔法（忘了-10，直接写成>=0了w） 
		if (m_s.m - 10 >= 0) m_s.m -= 10, m_s.far += 60;
		// 如果不能用魔法，那么可以选择徒步还是休息，注意，这里都是对m_s这个状态而言的，也就是说是修改当前的这个m_s，而不是s1和s2... 
		// 想了下似乎仅仅对于m_s这个状态而言，它是休息还是徒步取决于能否使得距离更远，但这样就又有多种考虑了，如果当前休息能使得下一次
		// 能够使用魔法，那么这是会比直接选择徒步划得来的，但是如果选择了休息，却没有时间使用，那么也就没徒步划得来了w..这里还是贪心一下
		// 只选徒步试试...试了下这样果然是不合理的.. 
		else if (m_s.m + 4 >= 10) {
			m_s.m = m_s.m + 4 - 10;
			m_s.tm = tm + 1;
			m_s.far += 60;
			return m_s;
		}
		else m_s.far += 17;
//		else if (s3.far + 17 > s2.far)
//		else if (s1.far > s2.far) s3.far += 17, m_s = s3;
//		else s3.m += 4, m_s = s3;
	}
	m_s.tm = tm;
	return m_s;
}
int main() {
	int m, s, t;
	cin >> m >> s >> t;
	f[0][0] = f[0][1] = f[0][2] = Status(0, m, 0);
	for (int i = 1; i <= t; i++) {
		// 休息的情况，将上一秒的三种情况的最大距离的状态拿过来，然后把法力值恢复 
		f[i][0] = my_max(f[i - 1][0], f[i - 1][1], f[i - 1][2], 0, i);
		// 徒步走的情况，同样将上一秒三种情况的最大距离的状态拿过来，然后将距离增加 
		f[i][1] = my_max(f[i - 1][0], f[i - 1][1], f[i - 1][2] , 1, i);
		// 使用魔法的情况，这种情况要判断下是否有足够的魔法，如果有，则可以用魔法，如果没有，可以选择徒步走或者休息，当然这也是取决于
		// 最大距离的
		f[i][2] = my_max(f[i - 1][0], f[i - 1][1], f[i - 1][2] , 2, i); 
	}
	int res = 0;
	bool flag;
	for (int i = 1; i <= t; i++) {
		flag = false;
		for (int j = 0; j < 3; j++) {
			if (f[i][j].tm == i) res = max(res, f[i][j].far);
			else flag = true;
		}
		if (flag) i++;
		if (res >= s) {
			cout << "Yes" << endl;
			cout << i << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	cout << res << endl;
//	for (int i = 1; i <= t; i++) {
//		cout << f[i][0].far << ' ' << f[i][1].far << ' ' << f[i][2].far << endl;
//		cout << f[i][0].tm << ' ' << f[i][1].tm << ' ' << f[i][2].tm << endl;
//		cout << f[i][0].m << ' ' << f[i][1].m << ' ' << f[i][2].m << endl;
//		cout << endl;
//	}
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[300001];
int main(){
    int m,s,t;
    scanf("%d%d%d",&m,&s,&t);
    for(int i=1;i<=t;i++){//处理闪烁法术
        if(m>=10)dp[i]=dp[i-1]+60,m-=10;//如果能用，就用
        else dp[i]=dp[i-1],m+=4;//否则休息
    }
    for(int i=1;i<=t;i++){dp[i]=max(dp[i],dp[i-1]+17);//处理跑步，dp[i]为使用法术和跑步的最大值（最优）
    if(dp[i]>=s){printf("Yes\n%d",i);return 0;}//如果超过了距离s，就成功了，输出yes
    }printf("No\n%d",dp[t]);//没成功，输出no
    return 0;
}
*/

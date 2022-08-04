#include <iostream>
#include <cstdio>
using namespace std;

// 首先可以确定的是这个题是最大子段和的变体，它给出了两个序列...那么我们能否对两个序列同时求最大子段和呢？应该是不可以的w
// 继续分析问题，可以发现题目要求子段和不能小于零，考虑普通最大子段和的题，它的状态转移方程是F(i) = max{F(i - 1) + nums[i], f(i - 1)}
// 也就是说选当前数能不能使的F(i - 1)处的子段和递增..那么对它进行改造，就可以得到：当当前子段和小于零时，它的字段和应该是F(i - 1)，明确
// 了这个问题后就可以对题目进行分析了..前面提到不能同时求两个序列的最大子段和，那也就是说只能对两个序列分别求最大子段和..我们可以发现，
// 当我们求的是序列A的最大字段和时，序列B不存在“最大子段和” 这个概念，它的和只要满足大于等于零就行..同理，对于B序列也是如此...但是要
// 注意，当A序列作为主序列时，会出现的两种情况：一：A序列的最大子段和<0，这种情况就要套用前面的公式对它进行“回档”了，同时，B序列也要
// 进行“回档”...同理，当B序列出现负值时，一样要对两个序列进行回档...知道了上面的信息后，就可以得到B序列也是一样的想法了..
// 这里针对A序列求最大和时B序列的和进行一些讨论，可以发现，当A序列的最大和不是负数时，B序列只需要将当前位置数和前面累计的和加起来就行，
// 而当A序列出现了负数，则两者同时“回档”.. 
// 那么因为这个题同样存在两种本质不同的状态，故而DP数组也要开两维... 
// 然而并不是最大子段和...坠毁... 

#define x first
#define y second
typedef pair<int, int > PII;
const int N = 110;
PII nums[N];
PII f[N][2];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &nums[i].x, &nums[i].y);
	// 分别求智商和情商两个序列的最大子段和... 
	f[1][0] = f[1][1] = PII(nums[1].x, nums[1].y);
	cout << "---------------" << endl;
	for (int i = 2; i <= n; i++) {
		int x = nums[i].x, y = nums[i].y;
		// 智商求最大和，情商就直接加就行 
		f[i][0].x = max(f[i - 1][0].x + x, f[i - 1][0].x);
		f[i][0].y = f[i - 1][0].y + y;
		// 如果有非法值就回档 
		if (f[i][0].x < 0 || f[i][0].y < 0 || f[i][0].x == f[i - 1][0].x) f[i][0] = f[i - 1][0];
		// 求情商的最大和，同理 
		f[i][1].y = max(f[i - 1][1].y + y, f[i - 1][1].y);
		f[i][1].x = f[i - 1][1].x + x;
		if (f[i][1].y < 0 || f[i][1].x < 0 || f[i][1].y == f[i - 1][1].y) f[i][1] = f[i - 1][1];
	}
//	for (int i = 2; i <= n; i++) {
//		int x = nums[i].x, y = nums[i].y;
//		if (f[i].x + x > 0) {
//			f[i].x = max(f[i - 1].x + x, f[i - 1].x);	
//		} else {
//			f[i].x = f[i - 1];
//		}
//		if (f[i].y + y > 0) {
//			f[i].y = max(f[i - 1].y + y, f[i - 1].y);	
//		} else f[i].y = f[i - 1];
//		
//		
////		if (f[i].x < 0 || f[i].y < 0) f[i] = f[i - 1];
//	} 
//	for (int i = 1; i <= n; i++) cout << f[i].x << ' ' << f[i].y << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			cout << f[i][j].x << ' ' << f[i][j].y << endl;
		}
		cout << "---------------" << endl;
	}
	return 0;
}

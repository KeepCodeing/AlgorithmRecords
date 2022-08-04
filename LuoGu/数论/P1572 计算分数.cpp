#include <iostream>
#include <cstdio>
using namespace std;

// 学了GCD加上之前看过紫书上的解法，算是有点思路了w，首先考虑分母是什么，
// 分母一定要相同两个等式才能进行加减，所以得先把分母化为相同的数。那么如何
// 使得分母相同呢，一般都是乘上某个数，比如2与6，可以让2*3->6，同样也可以乘上
// 别的数，但这不能使得分母最简。多试几个就发现乘上他们的最小公倍数就行...
// 对于分母，注意符号即可，最后全加起来，然后判断是否能够约分。 

// 这里还要提下怎么输入，其一开始打算直接读入处理的，但是很明显这样非常麻烦，
// 正确的方式是直接用scanf格式化读入... 

const int N = 120;
int fz[N], fm[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int cnt = 0, t = 1;
	while (scanf("%d/%d", &fz[cnt], &fm[cnt++]) != EOF) {
		if (t == 1) t
	}
	t = fm[0];
	for (int i = 1; i < cnt; i++) {
		t = t * fm[i] / gcd(t, fm[i]);
	}
	cout << t;
	return 0;
}
//#include<stdio.h>
//int gcd(int a,int b)
//{
//    return b?gcd(b,a%b):a;
//}
//int main()
//{
//    int a[10010],n,m,i,z;
//    int k;
//    i=0;
//    while(~scanf("%d",&n))
//    {
//        scanf("%d",&a[0]);
//        k=a[0];
//        for(i=1;i<n;i++)
//        {
//            scanf("%d",&a[i]);
//         	if (k == 1) k = a[i];
//		    z=gcd(k,a[i]);
//            k=k*a[i]/z;
//        } 
//        printf("%d\n",k);
//    }
//    return 0;
//}

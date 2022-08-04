#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// 好像也做过的样子，就是完全背包计数...，当然以前是用回溯搞这种题的，不过数据范围不可能总是那么小... 
// 物品个数：给出的整数n
// 物品价值：从1~n之间的任意数
// 为什么是完全背包+方案数：方案数就不说了，完全背包是从样例看出来的，一个数可以被无限选...
 
// 我谔谔，跑到洛谷上找原题，原来是求幂次方个数的组合方案，不是从1~n的组合方案，一瞬以为自己背包模型都忘了... 

// 不知道为什么超时坠毁了w，看起来完全背包也有点忘了（无能） 
 
 // 看到数据范围就来欲望了（指开long long） 
typedef long long LL;
const int N =  1000000 + 10;
LL f[N];
int ksm(int m) {
	int p = 2, q = m;
	LL res = 1;
	while (q) {
		if (q & 1) res = res * 1ll * p;
		// 快速幂往后移写成了往前移.. 
		q >>= 1;
		p = p * 1ll * p;
	}
	return res;
}
int sq[25] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
int main() {
	int n;
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 0; i < 20; i++) {
		for (int j = sq[i]; j <= n; j++) {
			f[j] += f[j - sq[i]];
			f[j] %= 1000000000;
		}
	}
	cout << f[n];
	return 0;
}
/*

 #include<stdio.h>
unsigned long long  number[1000005];
void get_number()
{
    number[0]=0;
    number[1]=1;
    number[2]=2;
    number[3]=2;
    for(int i=4;i<1000005;i++)
    {
        if(i%2==0)
        {
            number[i]=(number[i-2]+number[i/2])%1000000000;
 
        }
        if(i%2==1)
        {
            number[i]=number[i-1]%1000000000;
        }
    }
    return ;
}
int main ()
{
    get_number();
    int n;
    scanf("%d",&n);
    printf("%lld",number[n]);
    return 0;
}
*/

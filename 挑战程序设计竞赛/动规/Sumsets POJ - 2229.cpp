#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

// ����Ҳ���������ӣ�������ȫ��������...����Ȼ��ǰ���û��ݸ�������ģ��������ݷ�Χ������������ôС... 
// ��Ʒ����������������n
// ��Ʒ��ֵ����1~n֮���������
// Ϊʲô����ȫ����+���������������Ͳ�˵�ˣ���ȫ�����Ǵ������������ģ�һ�������Ա�����ѡ...
 
// �����̣��ܵ��������ԭ�⣬ԭ�������ݴη���������Ϸ��������Ǵ�1~n����Ϸ�����һ˲��Ϊ�Լ�����ģ�Ͷ�����... 

// ��֪��Ϊʲô��ʱ׹����w����������ȫ����Ҳ�е����ˣ����ܣ� 
 
 // �������ݷ�Χ���������ˣ�ָ��long long�� 
typedef long long LL;
const int N =  1000000 + 10;
LL f[N];
int ksm(int m) {
	int p = 2, q = m;
	LL res = 1;
	while (q) {
		if (q & 1) res = res * 1ll * p;
		// ������������д������ǰ��.. 
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

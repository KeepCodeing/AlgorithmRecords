#include <iostream>
#include <cstdio>
using namespace std;

// ѧ��GCD����֮ǰ���������ϵĽⷨ�������е�˼·��w�����ȿ��Ƿ�ĸ��ʲô��
// ��ĸһ��Ҫ��ͬ������ʽ���ܽ��мӼ������Ե��Ȱѷ�ĸ��Ϊ��ͬ��������ô���
// ʹ�÷�ĸ��ͬ�أ�һ�㶼�ǳ���ĳ����������2��6��������2*3->6��ͬ��Ҳ���Գ���
// ����������ⲻ��ʹ�÷�ĸ��򡣶��Լ����ͷ��ֳ������ǵ���С����������...
// ���ڷ�ĸ��ע����ż��ɣ����ȫ��������Ȼ���ж��Ƿ��ܹ�Լ�֡� 

// ���ﻹҪ������ô���룬��һ��ʼ����ֱ�Ӷ��봦��ģ����Ǻ����������ǳ��鷳��
// ��ȷ�ķ�ʽ��ֱ����scanf��ʽ������... 

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

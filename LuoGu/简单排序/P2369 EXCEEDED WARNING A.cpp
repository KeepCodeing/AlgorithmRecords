#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

// ˮ...����Ѿ����ˣ�����С���ѱ����ѿ��԰����ָĳɸ�������Ϊ
// ֻ������������ 
// Ȼ����STL��Ĵ���Ѳ�֧��βɾ�������Ը���map���ˣ���ΪmapĬ�����򣬶������map����һ������ѵĻ�
// ������end()ȡ�����һ��pair��Ȼ��ά�����map�Ĵ�С���� 

// �ܿӵ��⣬������Ӻܶ�... 

// ����Ϊ�Լ�̫���ӵ��Ǿ�Ȼ������������...

// û����������Ϊ����Ĳ���ʱ����ѣ������Ļ�����Ԫ�ش�С���Ѷ�һ�������Ԫ��
// ��Ԫ�ظ�������m��ʱ��ɾ���Ѷ������Ԫ�أ���ʱ��ʣm - 1��СԪ�أ�Ȼ��������
// Ԫ�أ���ʱ����ֻ��m��Ԫ�أ��ظ����ϲ��������ʣ�����ľ�����С��m��Ԫ��
 
// m = 5
// 2 4 6 8 10 1 3 5 7 9
// ������Ԫ��С��m��ʱ��ֱ�Ӱ�����Ԫ�طŽ�ȥ����
// ����ȥ����ǰ������������
// 10 8 6 2 4 --> 1
// 8 6 4 2 1 --> 3
// 6 4 3 2 1 --> 5
// 5 4 3 2 1 --> 7
// 7 5 4 3 2 1 --- 5 4 3 2 1
// 9 5 4 3 2 1 --- 5 4 3 2 1

/*
��¼��ķ���룬�������� 
#include<bits/stdc++.h>
#define int long long
using namespace std;
priority_queue<int>q;
int n,m,a[100001];
signed main()
{
	int x;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		q.push(x);
		m--;
		if(m<0)
		m++,q.pop();
	}
	m=0;
	while(!q.empty())
	{
		m++;
		a[m]=q.top();
		q.pop();
	}
	for(int i=m;i>=1;i--)
	printf("%lld\n",a[i]);
	return 0;
}
*/

map<int, int > mp;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int t; 
	while (n--) {
		scanf("%d", &t);
		// ����д���������bug����������Ϊ����ƣ����������˸�flag��������˼��ǰm���������������룬
		// ���ǳ�����m�������������Ҫ���жԱ�ɾ����Ȼ��������������趨����һ����Ч��������Ч������
		// ����һ�����볬����m�����󣬺�����������ʵ�ǻᱻ���Եģ������������tС��֮ǰm�����������Ǹ�
		// ����mp�Ĵ�С�ſ��ܸı�... 
		if (mp.size() < m) {
			mp[t]++;
		} else {
			// ��Ϊmap�����ԣ�����endһ���������Ǹ������������ȡ�����������ǰ����С
			// ��˵�����԰������ɾ��Ȼ����������� 
			map<int, int >::iterator me = --mp.end();
			if (me->first > t) mp[t]++, mp.erase(me->first); 
		}
	}
	// �����������map��Ͱ... 
	for (map<int, int >::iterator it = mp.begin(); it != mp.end(); it++) {
		for (int i = 0; i < it->second && m > 0; i++, m--) {
			cout << it->first << endl;
		}
		
	}
	return 0;
}
/*
10 5
1
1
1
2
3
2
4
5
6
7
*/
/*
// �ܷ���m������ֱ�ӷţ����Ҽ�¼�¶������Сֵ����ΪSTL�����ȶ���ֻ�ܲ�ѯ��ͷ... 
if (heapque.size() <= m) {
	minNum = min(minNum, t);
	heapque.push(-t);
} else {
	// ��������Ѿ���m��Ԫ���ˣ���ʱ��Ҫ�Ա��¶�����С��Ԫ�غ͵�ǰԪ��
	// �Ĺ�ϵ�ˣ������ǰԪ�ش��ڶ�����С��Ԫ�أ���ô���Ԫ�ؾͿ�����ӣ�
	// ���ҽ���С��Ԫ��ȥ�������򲻹�
	if (t < minNum) continue;
		
}

if (mp.size() <= m) {
				
		} else {
			// ȡ����Сֵ��Ȼ���ж��µ�ǰԭ��ֵ�ǲ���С����Сֵ�����С�ڲ��ܣ����������Сֵ
			
//			if (-t < (mp.end())->first) {
//				for (map<int, int >::iterator it = mp.begin(); it != mp.end(); it++) {
//					cout << it->first << ' ';
//				}
//				cout << endl;
//				cout << mp.end()->first << "-----" << endl;
//				mp.erase(mp.end()->first);
//				mp[-t]++; 
//			} 
		}
	}
//	for (map<int, int >::iterator it = mp.begin(); it != mp.end(); it++) {
//		cout << it->first << ' ';
//	}
*/

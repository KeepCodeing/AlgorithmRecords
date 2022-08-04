#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

// 水...大根堆就完了，另外小根堆变大根堆可以把数字改成负数，因为
// 只有正整数数据 
// 然后发现STL里的大根堆不支持尾删除，所以改用map算了，因为map默认排序，而入过把map当成一个大根堆的话
// 可以用end()取到最后一个pair，然后维护这个map的大小就行 

// 很坑的题，比想象坑很多... 

// ↑因为自己太池沼但是居然还是做出来了...

// 没想明白是因为这里的操作时先入堆，这样的话不管元素大小，堆顶一定是最大元素
// 当元素个数超过m个时，删除堆顶的最大元素，这时就剩m - 1较小元素，然后继续入堆
// 元素，这时堆里只有m个元素，重复以上操作，最后剩下来的就是最小的m个元素
 
// m = 5
// 2 4 6 8 10 1 3 5 7 9
// 当堆里元素小于m个时，直接把所有元素放进去就行
// 否则去掉当前区间里最大的数
// 10 8 6 2 4 --> 1
// 8 6 4 2 1 --> 3
// 6 4 3 2 1 --> 5
// 5 4 3 2 1 --> 7
// 7 5 4 3 2 1 --- 5 4 3 2 1
// 9 5 4 3 2 1 --- 5 4 3 2 1

/*
记录里的粪代码，这是正解 
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
		// 这里写出了奇妙的bug，或许是因为过于疲惫，这里加了个flag，可能意思是前m个数可以随意输入，
		// 但是超过了m个数输入的数就要进行对比删除，然而奇妙的是这里设定的是一次生效，永久生效，所以
		// 当第一个输入超过了m个数后，后续的输入其实是会被忽略的，除非新输入的t小于之前m个数中最大的那个
		// 数，mp的大小才可能改变... 
		if (mp.size() < m) {
			mp[t]++;
		} else {
			// 因为map的特性，所以end一定是最大的那个数，把这个数取出来，如果当前数更小
			// 就说明可以把这个数删除然后更新序列了 
			map<int, int >::iterator me = --mp.end();
			if (me->first > t) mp[t]++, mp.erase(me->first); 
		}
	}
	// 输出，这里用map做桶... 
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
// 能放下m个数，直接放，并且记录下堆里的最小值，因为STL的优先队列只能查询队头... 
if (heapque.size() <= m) {
	minNum = min(minNum, t);
	heapque.push(-t);
} else {
	// 如果堆里已经有m个元素了，这时就要对比下堆里最小的元素和当前元素
	// 的关系了，如果当前元素大于堆里最小的元素，那么这个元素就可以入队，
	// 并且将最小的元素去掉，否则不管
	if (t < minNum) continue;
		
}

if (mp.size() <= m) {
				
		} else {
			// 取到最小值，然后判断下当前原的值是不是小于最小值，如果小于不管，否则更新最小值
			
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

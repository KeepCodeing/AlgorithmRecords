//#include <iostream>
//#include <queue>
//#include <cstdio>
//using namespace std;
//
//// 滑动窗口，但是本five忘了怎么用数组模拟单调栈和单调队列了（无能）
//// 这里用priority_queue()试试，STL里的优先队列好像是默认大顶堆，这里得
//// 用个小顶堆 
//
//// 草，这个不是普通的滑动窗口，这个求的是某个数前的窗口里的数... 
//
//// 然而坠毁了...因为优先队列会自动排序，而这个题求的是当前数之前的一个区间的最值
//// 也就是前面的另一个区间的数不一定能被删掉...
//
//// 用STL写得用双端队列..，数组模拟都忘了... 
//
//priority_queue<int, vector<int >, greater<int > > pri_que;
//int main() {
//	//for (int i = 0; i < 10; i++) pri_que.push(i);
//	//while (!pri_que.empty()) cout << pri_que.top(), pri_que.pop(); 
//	int n, m, t;
//	scanf("%d%d", &n, &m);
//	scanf("%d", &t);
//	pri_que.push(t), n--; 
//	printf("0\n");
//	while (n--) {
//		scanf("%d", &t);
//		if (pri_que.size() > m) pri_que.pop();
//		printf("%d\n", pri_que.top());
//		pri_que.push(t); 
//	}
//	return 0;
//} 

#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000002];
priority_queue< pair< int , int > > q;//二元组二叉堆 
int main()
{
cin>>n>>m>>a[1];//先把a[1]读入并放入堆中 
q.push(make_pair(-a[1],1));//每次放入相反数（取出当然也要反一下），让其变成小根堆 
printf("%d\n",0);//第一个永远输出0 
for(int i=2;i<=n;i++){
    cin>>a[i];//读入 
    int x=q.top().second;//去除堆中过时的堆顶 
//    cout << x  << ' ' << i << endl;
    while(i-m>x){
        q.pop();
        x=q.top().second;
    } 
    //printf("%d\n",-q.top().first);//去相反数输出现在的堆顶 
    q.push(make_pair(-a[i],i));//最后再将当前值放入堆中（因为前m个值中是不包括当前值的） 
}
return 0;
}

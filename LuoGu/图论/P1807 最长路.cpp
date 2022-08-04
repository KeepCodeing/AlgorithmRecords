#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

// 做最小生成树的时候觉得洛谷上有一道差不多的题，就来搜了下，顺带发现了这个题，似乎可以水过..
// 看了下似乎有负权边，但是题目保证无环，所以可以用Dijkstra写...主要就是松弛条件和边权初始值，
// 松弛条件在最短路里是dist[vt] > wt + w[i]，这样就能保证边权是越来越小的，改下符号dist[vt] < wt + w[i]
// 就能保证边权越来越大了，那么初始值设置为0或者-1都行，因为有负权边还想了下到底边权设置为多少比较合适
// 不过这个题求的最长路，我们知道负权边图不存在最短路，但是应该存在最长路，因为最长路要求的是边权更长，
// 那如果当前边加上一个负数，就会越来越短，即不会进行松弛，这也是为什么负权图不存在最短路的原因... 

// 奇怪，只能过一半的点...拿了以前写的板子发现没有问题，实际上代码也不应该有问题.. 
// 似乎Dijkstra只能过没有负权边的图..不过为什么别人能过呢.. 

typedef pair<int, int > PII;
// 有向图 
const int N = 1500 + 10, M = 5 * 1e5 + 10;
int head[N], w[M], e[M], ex[M], idx = 0;
int dist[N];
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	// 最长路边权全部初始为0 
	memset(dist, 0, sizeof dist);
	// STL里的优先队列默认是大根堆 
	priority_queue<PII > que;
	dist[st] = 0;
	que.push(PII(0, st)); 
	while (que.size()) {
		PII now = que.top();que.pop();
		int ut = now.second, wt = now.first;
		if (vis[ut]) continue;
		vis[ut] = true;
		for (int i = head[ut]; i != -1; i = ex[i]) {
			int vt = e[i];
			// 最长路松弛条件，可以使得边权变大 
			if (dist[vt] < w[i] + wt) {
				dist[vt] = w[i] + wt;
				que.push(PII(dist[vt], vt)); 
			}
		}
	}
	return dist[ed];
}
int main() {
	memset(head, -1, sizeof head);
	int n, m, ut, vt, wt;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d%d", &ut, &vt, &wt);
		add(ut, vt, wt);
	}
	int res = dijkstra(1, n);
	// for (int i = 1; i <= n; i++) cout << dist[i] << ' ';
	// 答案不存在输出-1 
	if (!res) res = -1;
	printf("%d", res);
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//#define MAXN 10005
//#define MAXM 500005
//int n,m,s,u,v,c,tot,dis[MAXN];//从1到每个点的距离，刚开始脑残了，以为每个点都要求。。。
//bool vis[MAXN];//表示每个点有没有被访问过。。。
//struct Node//结构体存边
//{
//    int v,c;
//    Node *next;
//}*h[MAXN],pool[MAXM];
//struct Queue
//{
//    int id,dis;
//    bool operator<(const Queue t) const
//    {
//        return dis<t.dis;
//    }
//};
//priority_queue <Queue> q;//队列
//Queue tmp;
//void ae(int u,int v,int c)//addedge，邻接表存边（本人只会写指针。。。）
//{
//    Node *p=&pool[tot++];
//    p->v=v;p->c=c;p->next=h[u];h[u]=p;
//}
//void dijkstra()
//{
//    for(int i=1;i<=n;i++) 
//        dis[i]=0;
//    dis[s]=0;
//    tmp.id=s;tmp.dis=0;q.push(tmp);
//    while(!q.empty())
//    {
//        tmp=q.top();q.pop();
//        int u=tmp.id;
//        for(Node *j=h[u];j;j=j->next)
//        {
//            if(!vis[j->v]&&dis[j->v]<dis[u]+ j->c)
//            {
//                dis[j->v]=dis[u]+j->c;
//                tmp.id=j->v;tmp.dis=dis[j->v];q.push(tmp);
//            }
//        }
//    }
//}//dijkstra的板子
//int main()
//{
//    cin >> n >> m;
//    for(int i=1;i<=m;i++)
//    {
//        cin >> u >> v >> c;
//        ae(u,v,c);
//    }
//    s=1;
//    dijkstra();
//    for (int i = 1; i <= n; i++) cout << dis[i] << ' ';
//    if(!dis[n])
//        cout << "-1";//注意，千万不要把“-1”打成‘-1’，本蒟蒻被坑了30分钟
//    else
//    	cout << dis[n];
//    return 0;//2333
//}

#include<cstdio>
#include<string.h>
#include<queue>
#include<vector>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e4,maxm=1e4;
int n,m;
struct edge {
	int to,dist,cost;
};
typedef pair<int,int> P;
int d[maxn];
int pre[maxn];
int main() {
	int a,b,c,e;
	edge e1,e2;
	while(true) {
		scanf("%d%d",&n,&m);
		if (!n && !m) break;
		vector<edge> G[maxn];
		for(int i=0; i<m; i++) {
			scanf("%d%d%d%d",&a,&b,&c,&e);
			e1.cost=e2.cost=e;
			e1.dist=e2.dist=c;
			e1.to=b;
			e2.to=a;
			G[a].push_back(e1);
			G[b].push_back(e2);
		}
		priority_queue<P,vector<P>,greater<P> >que;
		fill(d+1,d+n+1,inf);
		d[1]=0;
		que.push(P(0,1));
		pre[1]=0;      //每个图n-1条边
		while(!que.empty()) {
			P p=que.top();
			que.pop();
			int v=p.second;
			if(d[v]<p.first) continue;
			for(int i=0; i<G[v].size(); i++) {
				edge e=G[v][i];
				if(d[e.to]>d[v]+e.dist) {
					d[e.to]=d[v]+e.dist;
					cout << e.to << endl;
					pre[e.to]=e.cost;  //每个pre放了这个点与这个图相连的那条边，这样后面就不用回溯找边的cost值
					que.push(P(d[e.to],e.to));
				} else if(d[e.to]==d[v]+e.dist) {
					pre[e.to]=min(e.cost,pre[e.to]);
				}
			}
		}
		int ans=0;
		for(int i=1; i<=n; i++) {
			ans+=pre[i];
		}
		printf("%d\n",ans);
	}
}

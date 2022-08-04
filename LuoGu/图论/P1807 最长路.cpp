#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

// ����С��������ʱ������������һ�������⣬���������£�˳������������⣬�ƺ�����ˮ��..
// �������ƺ��и�Ȩ�ߣ�������Ŀ��֤�޻������Կ�����Dijkstraд...��Ҫ�����ɳ������ͱ�Ȩ��ʼֵ��
// �ɳ����������·����dist[vt] > wt + w[i]���������ܱ�֤��Ȩ��Խ��ԽС�ģ����·���dist[vt] < wt + w[i]
// ���ܱ�֤��ȨԽ��Խ���ˣ���ô��ʼֵ����Ϊ0����-1���У���Ϊ�и�Ȩ�߻������µ��ױ�Ȩ����Ϊ���ٱȽϺ���
// �������������·������֪����Ȩ��ͼ���������·������Ӧ�ô����·����Ϊ�·Ҫ����Ǳ�Ȩ������
// �������ǰ�߼���һ���������ͻ�Խ��Խ�̣�����������ɳڣ���Ҳ��Ϊʲô��Ȩͼ���������·��ԭ��... 

// ��֣�ֻ�ܹ�һ��ĵ�...������ǰд�İ��ӷ���û�����⣬ʵ���ϴ���Ҳ��Ӧ��������.. 
// �ƺ�Dijkstraֻ�ܹ�û�и�Ȩ�ߵ�ͼ..����Ϊʲô�����ܹ���.. 

typedef pair<int, int > PII;
// ����ͼ 
const int N = 1500 + 10, M = 5 * 1e5 + 10;
int head[N], w[M], e[M], ex[M], idx = 0;
int dist[N];
bool vis[N];
void add(int ut, int vt, int wt) {
	e[idx] = vt, w[idx] = wt, ex[idx] = head[ut], head[ut] = idx++;
}
int dijkstra(int st, int ed) {
	// �·��Ȩȫ����ʼΪ0 
	memset(dist, 0, sizeof dist);
	// STL������ȶ���Ĭ���Ǵ���� 
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
			// �·�ɳ�����������ʹ�ñ�Ȩ��� 
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
	// �𰸲��������-1 
	if (!res) res = -1;
	printf("%d", res);
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//#define MAXN 10005
//#define MAXM 500005
//int n,m,s,u,v,c,tot,dis[MAXN];//��1��ÿ����ľ��룬�տ�ʼ�Բ��ˣ���Ϊÿ���㶼Ҫ�󡣡���
//bool vis[MAXN];//��ʾÿ������û�б����ʹ�������
//struct Node//�ṹ����
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
//priority_queue <Queue> q;//����
//Queue tmp;
//void ae(int u,int v,int c)//addedge���ڽӱ��ߣ�����ֻ��дָ�롣������
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
//}//dijkstra�İ���
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
//        cout << "-1";//ע�⣬ǧ��Ҫ�ѡ�-1����ɡ�-1�������X�m������30����
//    else
//    	cout << dis[n];
//    return 0;//2333
//}

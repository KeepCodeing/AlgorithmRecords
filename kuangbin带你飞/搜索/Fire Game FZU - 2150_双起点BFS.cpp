#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

// ��������ר������û��������w������ǰ���Ĵ��������Թ�֮��ļ���....
// �����Ҳ���������Թ���������������������㣬˼·����ö�����е�ԣ�Ȼ��
// ����Щ����Ӿ����ˣ�Ȼ����ΪҪ�ж���������ʱ�䣬��˿����ø����������¼
// ���ʷ�;���... 

// AC����... 

typedef pair<int, int > PII;
const int N = 15, INF = 0x3fffffff;
char graph[N][N];
PII record[N * N];
int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
PII que[N * N]; 
int dist[N][N];
int T, n, m, cnt;
int bfs(PII x, PII y) {
	int qtop = 0, qback = 0;
	queue<PII > que;
	que.push(x), que.push(y);
	// que[qback] = x, que[++qback] = y;
	dist[x.first][x.second] = dist[y.first][y.second] = 0;
	while (que.size()) {
		PII now = que.front();que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + mv[i][0], ny = now.second + mv[i][1];
			if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
			// ע��ֻ�����쵽#��... 
			if (graph[nx][ny] != '#') continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[now.first][now.second] + 1;
			que.push(PII(nx, ny));
		}
	}
	PII temp;
	int res = 0;
	// �ж�����#�Ƿ񶼱������ˣ���������̱������ʱ�䣬��ʵ����Ҳ������BFS���������������߰����һ��
	// ��ֱ�������ã�����ǰ����û��̫����գ������ƺ��ᵼ���ٶȱ���... 
	for (int i = 1; i <= cnt; i++) {
		temp = record[i];
		if (dist[temp.first][temp.second] == -1) return INF;
		res = max(res, dist[temp.first][temp.second]);
	}
	return res;
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n >> m;
		cnt = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)  {
				cin >> graph[i][j];
				// ��¼�����������꣬�������ö�ٵ��.. 
				if (graph[i][j] == '#') record[cnt++] = PII(i, j);
			}
		}
		// ����ֻ������������ 
		if (cnt <= 3) {
			printf("Case %d: %d\n", t, 0);
			continue;
		}
		int res = INF;
		// ö�����е�ԣ�Ȼ����BFS
		for (int i = 1; i <= cnt; i++) {
			for (int j = i; j <= cnt; j++) {
				memset(dist, -1, sizeof dist);
				// ����ÿ�������Ϊ��������������ͼ�����ʱ��.. 
				res = min(res, bfs(record[i], record[j]));
			}
		}
		// ���ÿ����Զ��޷�����.. 
		if (res == INF) res = -1;
		printf("Case %d: %d\n", t, res);
	}
	return 0;
}
/*
AC���룬��û����ģ����У�Ҳû���þ������飬����ֱ���ڱ����Ĺ����н�����ͳ��.. 
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<math.h>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define met(a,b) memset(a,b,sizeof(a))
#define N 109
int vis[N][N];
char str[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int k,n,m;
struct node
{
    int x,y,temp;
}a[N];///ͳ�Ƹɲݵ�����
int pan()///�жϸɲ��Ƿ��ܱ���ȼ
{
    int x,y;
    for(int i=0;i<k;i++)
    {
        x=a[i].x;y=a[i].y;
        if(!vis[x][y])
            return 0;
    }
    return 1;
}
int bfs(node a,node b)
{
    int team=0;
    met(vis,0);
    queue<node>Q;
    node q,p;
    Q.push(a);Q.push(b);
    vis[a.x][a.y]=1;vis[b.x][b.y]=1;
    while(Q.size())
    {
        q=Q.front();
        Q.pop();
        for(int i=0;i<4;i++)
        {
            p.x=q.x+dir[i][0];
            p.y=q.y+dir[i][1];
            p.temp=q.temp+1;
            if(p.x>=0 && p.x<n&& p.y>=0 && p.y<m && str[p.x][p.y]=='#' && !vis[p.x][p.y])
            {
                vis[p.x][p.y]=1;
                team=max(team,p.temp);
                Q.push(p);
            }
        }
    }
    if(pan())
        return team;
    else
        return INF;
}
int main()
{
    int t,con=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='#')
                {
                    a[k].x=i;
                    a[k].y=j;
                    a[k++].temp=0;
                }
            }
        }
        int ans=INF;
        for(int i=0;i<k;i++)
        {
            for(int j=i;j<k;j++)
            {
                ans=min(bfs(a[i],a[j]),ans);
            }
        }
        printf("Case %d: ",con++);
        if(ans==INF)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
*/

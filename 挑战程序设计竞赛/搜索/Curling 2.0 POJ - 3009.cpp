#include <iostream>
#include <cstdio>
using namespace std;

// 参考博客：https://www.jianshu.com/p/6d7684159189
// 这个题和普通的DFS不同，它存在一些限制，首先是走的步数，它要求碰到障碍物换方向的次数不超过10次，也就是
// 说我们最多碰十次壁，另外这里碰壁也有奇妙的判定。程序允许我们消除碰到的障碍，不过不能直接穿过障碍，而是
// 碰到后把其消除，下一步才能继续走。另外这个题要求我们只能走一个方向，除非碰了十次壁或者出界了才能换新方向
// 而更新答案的条件就是走到了终点，这里要求最短路，但是因为上述特性，BFS不一定就能求到，这里得用DFS 

const int N = 25, INF = 0x3fffffff;
int graph[N][N];
int n, m;
int res;
int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int sx, int sy, int step) {
	if (step > 10) return;
	int now_x, now_y, next_x, next_y;
	for (int i = 0; i < 4; i++) {
		next_x = sx + mv[i][0], next_y = sy + mv[i][1];
		now_x = sx, now_y = sy;
		// 判断下一个位置是否能走，如果能走，就一直从这个位置走 
		while (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m && graph[next_x][next_y] != 1) {
			// 更新当前位置 
			now_x += mv[i][0], now_y += mv[i][1];
			// 如果当前就在终点了，更新答案 
			if (graph[now_x][now_y] == 3) {
				res = min(res, step);
				return;
			}
			// 从当前位置继续扩展这个方向 
			next_x = now_x + mv[i][0], next_y = now_y + mv[i][1];
			// 如果出界了，就换方向 
			if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) break;
			// 如果下一个位置是障碍，先打破它，然后再从这个位置出发 
			if (graph[next_x][next_y] == 1) {
				graph[next_x][next_y] = 0;
				dfs(now_x, now_y, step + 1);
				// 回溯，因为不同路线的障碍互不影响... 
				graph[next_x][next_y] = 1;
			}
		}
	}
}
int main() {
	int sx, sy;
	do {
		res = INF;
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
					scanf("%d", &graph[i][j]);
					if (graph[i][j] == 2) sx = i, sy = j;
			}	
		}		
		dfs(sx, sy, 1);
		if (n && m) printf("%d\n", res == INF ? -1 : res);
	} while(n && m);
	return 0;
}
/*

#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
int w,h;
int mp[30][30];
int dir[5][5]={{0,1},{0,-1},{-1,0},{1,0}},mins,sx,sy;
void dfs(int x,int y,int step)
{
   step++;
   if(step>10)return;
   for(int i=0;i<4;i++)
   {
       int tx=x+dir[i][0];
       int ty=y+dir[i][1];
       if(mp[tx][ty]==1)continue;//该方向被墙挡住不能向此方向抛
       while(mp[tx][ty]==0||mp[tx][ty]==2)//0和2都无墙壁
       {
             tx=tx+dir[i][0];
             ty=ty+dir[i][1];
       }
       if(mp[tx][ty]==-1)continue;//出界
       if(mp[tx][ty]==1)
       {
          mp[tx][ty]=0;
          dfs(tx-dir[i][0],ty-dir[i][1],step);
          mp[tx][ty]=1;//回溯
       }
       if(mp[tx][ty]==3)
       {
          if(step<mins)
          mins=step;
          continue;
       }
   }
}
int main()
{
    while(~scanf("%d%d",&w,&h))
    {    if(w==0&&h==0)
         break;
         mins=inf;
         memset(mp,-1,sizeof(mp));
         for(int i=1;i<=h;i++)
         {   for(int j=1;j<=w;j++)
             {
                 scanf("%d",&mp[i][j]);
                 if(mp[i][j]==2)
                 {
                    sx=i;
                    sy=j;
                 }
             }
         }
         dfs(sx,sy,0);
         if(mins<inf)
         printf("%d\n",mins);
         else printf("-1\n");
    }
    return 0;
}

*/

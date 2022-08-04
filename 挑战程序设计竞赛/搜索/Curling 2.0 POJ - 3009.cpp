#include <iostream>
#include <cstdio>
using namespace std;

// �ο����ͣ�https://www.jianshu.com/p/6d7684159189
// ��������ͨ��DFS��ͬ��������һЩ���ƣ��������ߵĲ�������Ҫ�������ϰ��ﻻ����Ĵ���������10�Σ�Ҳ����
// ˵���������ʮ�αڣ�������������Ҳ��������ж��������������������������ϰ�����������ֱ�Ӵ����ϰ�������
// �����������������һ�����ܼ����ߡ����������Ҫ������ֻ����һ�����򣬳�������ʮ�αڻ��߳����˲��ܻ��·���
// �����´𰸵����������ߵ����յ㣬����Ҫ�����·��������Ϊ�������ԣ�BFS��һ�������󵽣��������DFS 

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
		// �ж���һ��λ���Ƿ����ߣ�������ߣ���һֱ�����λ���� 
		while (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m && graph[next_x][next_y] != 1) {
			// ���µ�ǰλ�� 
			now_x += mv[i][0], now_y += mv[i][1];
			// �����ǰ�����յ��ˣ����´� 
			if (graph[now_x][now_y] == 3) {
				res = min(res, step);
				return;
			}
			// �ӵ�ǰλ�ü�����չ������� 
			next_x = now_x + mv[i][0], next_y = now_y + mv[i][1];
			// ��������ˣ��ͻ����� 
			if (next_x < 1 || next_x > n || next_y < 1 || next_y > m) break;
			// �����һ��λ�����ϰ����ȴ�������Ȼ���ٴ����λ�ó��� 
			if (graph[next_x][next_y] == 1) {
				graph[next_x][next_y] = 0;
				dfs(now_x, now_y, step + 1);
				// ���ݣ���Ϊ��ͬ·�ߵ��ϰ�����Ӱ��... 
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
       if(mp[tx][ty]==1)continue;//�÷���ǽ��ס������˷�����
       while(mp[tx][ty]==0||mp[tx][ty]==2)//0��2����ǽ��
       {
             tx=tx+dir[i][0];
             ty=ty+dir[i][1];
       }
       if(mp[tx][ty]==-1)continue;//����
       if(mp[tx][ty]==1)
       {
          mp[tx][ty]=0;
          dfs(tx-dir[i][0],ty-dir[i][1],step);
          mp[tx][ty]=1;//����
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

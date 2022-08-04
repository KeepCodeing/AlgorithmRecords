#include <iostream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

// 类似于迷宫版的爆搜，但是限制的步数，起点也变成了任意点 
// 另外要注意，一个点可以重复走，这也就意味着我们只用保证只走了六步即可，无需管什么访问否或者
// 回溯之类的东西... 

// TLE一次，选错评测语言CE一次...，TLE的原因是使用了字符作为记录路径的方法，如果使用数字就不会
// 可能和STL的set的性能有关，下面提供数字的记录方法...

// 另外考虑下这个题需不需要所谓的回溯，很明显应该是不需要的，因为回溯就是回去走别的路，但是这个题限制了六步
// 也就是不管怎么回去走总会走起始格子为中心的六步，所以无需回溯... 

/*
// 参考地址：https://www.cnblogs.com/mzchuan/p/11199242.html
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#define mod 1000000007
#define eps 1e-6
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

int fx[4]={1,-1,0,0},fy[4]={0,0,1,-1};
int sz[6][6];
set<int> se;

void dfs(int i,int j,int s,int num)
 {
     if(s==6)
     {
         if(!se.count(num))
         {
             se.insert(num);
         }
         return ;
     }
     for(int k=0;k<4;k++)
     {
         int x=i+fx[k];
         int y=j+fy[k];
         if(x>=0&&y>=0&&x<5&&y<5&&s<6)
         {
             dfs(x,y,s+1,num*10+sz[x][y]);
         }
     }
 }
int main()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&sz[i][j]);
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            dfs(i,j,1,sz[i][j]);
        }
    }
    cout<<se.size()<<endl;

}
*/

const int N = 10, M = 5;
char graph[N][N];
bool visited[N][N];
set<string > ss;
void dfs(int sx, int sy, int step, string path) {
	if (step <= 0) {
		ss.insert(path);
		return;
	}
	if (sx > M || sx < 1 || sy > M || sy < 1) return;
//	if (visited[sx][sy]) return;
//	visited[sx][sy] = true;
	dfs(sx + 1, sy, step - 1, path + graph[sx][sy]);
	dfs(sx, sy + 1, step - 1, path + graph[sx][sy]);
	dfs(sx - 1, sy, step - 1, path + graph[sx][sy]);
	dfs(sx, sy - 1, step - 1, path + graph[sx][sy]);
}
int main() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= M; j++) {
			// memset(visited, 0, sizeof visited);
			dfs(i, j, 6, "");
		}
	}
	cout << ss.size();
	return 0;
}

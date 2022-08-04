#include <iostream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

// �������Թ���ı��ѣ��������ƵĲ��������Ҳ���������� 
// ����Ҫע�⣬һ��������ظ��ߣ���Ҳ����ζ������ֻ�ñ�ֻ֤�����������ɣ������ʲô���ʷ����
// ����֮��Ķ���... 

// TLEһ�Σ�ѡ����������CEһ��...��TLE��ԭ����ʹ�����ַ���Ϊ��¼·���ķ��������ʹ�����־Ͳ���
// ���ܺ�STL��set�������йأ������ṩ���ֵļ�¼����...

// ���⿼����������費��Ҫ��ν�Ļ��ݣ�������Ӧ���ǲ���Ҫ�ģ���Ϊ���ݾ��ǻ�ȥ�߱��·���������������������
// Ҳ���ǲ�����ô��ȥ���ܻ�����ʼ����Ϊ���ĵ������������������... 

/*
// �ο���ַ��https://www.cnblogs.com/mzchuan/p/11199242.html
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

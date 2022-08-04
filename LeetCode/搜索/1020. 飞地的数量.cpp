#include <iostream>
#include <vector>
using namespace std;

// �����ͬ���Ǹ�����������������⣬ֻ����Ҫ�����Ԫ�ظ����������ǵ������
// �ֻ�ȥ��������ȵ���Ŀ����Щ��Ҳ�����Ƶģ��������������Ļ�������һȦ
// �ɱ��������ݻ�����㣬���Ƕ����������˵������ⲻ����Щ�⣬������Ԫ�أ�
// ˮ��½�أ��ϰ��������ֻ������Ԫ�أ��ϰ���½�أ�Ҳ����˵����û�취ͨ����
// һȦˮ���ѳ��˱��ϰ���Χ��Ԫ��ȫ��Ⱦɫ����������⻹�ǵ��ó������ж�

// ��ô����������Ŀ�����Ҫ�����Ⱦɫ���ͼ�������ü�һȦ�ķ���
// �ȽϺã���ֻ�������ͨͼ�������ó��緽��Ӧ�û����

// �ٽ�һ��������LeetCode�ϵ������Ǹ��õģ�������мӹ��Ƚ��ѣ���OI���������Ҫ
// ����ģ����Կ��Է���Ľ��мӹ�����ôOI�ü�һȦ�ķ�����LeetCode�ó��編Ӧ�û���� 

// ��ÿ��1���б������жϳ���񣬲�ͳ��1�������������Ҳ�Ƚ�ֱ�׵�˵
// �����ܳ����1�Ͳ��Ǵ� 

class Solution {
public:
	int line, col;
	int oneCnt;
	vector<vector<int> > g;
	// �ǵü�&����Ȼflag��ֵ����ı� 
	void dfs(int sx, int sy, bool& flag) {
		if (sx < 0 || sx >= line || sy < 0 || sy >= col) {
			flag = false;
			// oneCnt = 0;
			return;
		}
		// ֻ��½�ؽ��б��� 
		if (g[sx][sy]) {
			g[sx][sy] = 0;
			oneCnt++;
			dfs(sx + 1, sy, flag);
			dfs(sx - 1, sy, flag);
			dfs(sx, sy + 1, flag);
			dfs(sx, sy - 1, flag);
		}
	}
    int numEnclaves(vector<vector<int> >& A) {
    	this->g = A;
		this->line = A.size(), this->col = A[0].size();
		bool flag;
		int ans = 0;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (g[i][j]) {
					flag = true, oneCnt = 0;
					dfs(i, j, flag);
					if (flag) ans += oneCnt;
				}
			}
		}
		return ans;
    }
};

int main() {
	return 0;
}

/*
[0,0,0,0],
[1,0,1,0],
[0,1,1,0],
[0,0,0,0]

[0,1,1,0],
[0,0,1,0],
[0,0,1,0],
[0,0,0,0]
*/

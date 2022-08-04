#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

// �������ǲ�ͬ·���ı��֣����ǿ�����ԭ�е�״̬ת�Ʒ����Ͻ����޸�
// ���ȿ������ϰ���������������ϰ��ĵ㣬�ߵ�����ķ������ǲ����ڵģ�Ҳ����0�� 
// ��ô���ڿ����ߵĵ��أ����Է�����Ȼ�ǳ��˱߽��ϵ���Щ��ֻ��һ�ַ�ʽ�ߵ�������
// �������ַ�ʽ�ߵ�.. 
// ���ǣ�����Ҫע�⵽�����ڱ߽��ϵĵ㣬����Ĭ���Ƕ���һ���߷��ģ���ô���账�ڱ߽�
// �ϵ�ĳ�������ϰ���������֮������е����ж������߷��أ���������0�֣���Ϊ�߽��
// ֻ�ܳ���һ�������ߣ�������·�����и��㱻��ס�ˣ�����ĵ㰴������˵Ӧ�ö���������.. 
// ���Եü�Щ�ж�.. 
// Ȼ������д׹����...  

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int f[110][110];
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (obstacleGrid[i][j]) {
        			// ����߲��ˣ��Ǿ�ֻ��0���߷� 
        			f[i][j] = 0;
				} else {
					// ���һ����һ���߷� 
					if (i == 0 && j == 0) f[i][j] = 1;
					else {
						// �Ƚ�ÿ������߷���Ϊ0���������԰�����һ�����߲��˵���� 
					    f[i][j] = 0;
					    // ����ܴ���һ�����߹�������ô��ǰ���߷�������һ������߷�֮�� 
				        if (i - 1 >= 0) f[i][j] += f[i - 1][j];
					    if (j - 1 >= 0) f[i][j] += f[i][j - 1];
					}
					
				}
			}
		}
		return f[m - 1][n - 1];
    }
};

int main() {
	int a[10]={34,87,23,15,32,46,67,62,28,30};
	sort(a, a + 10);
	for (int i = 0; i < 10; i++) cout << a[i] << ' ';
	return 0;
}

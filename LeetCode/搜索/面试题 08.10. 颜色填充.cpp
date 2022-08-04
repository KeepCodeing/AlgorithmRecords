#include <iostream>
#include <vector> 
using namespace std;

// ��������ˮ��з�����...������ˮ��䷨��ֻ�����涨��������ɫ 
// ����Ҫע���£���Ŀû˵0��һ���Ǹ������ص��Ԫ�أ���ʾ����Ҳ˵
// �������������������Կ��ܻ�Ҫ�ж�����������Ԫ���Ƿ���ͬ
// �����ˣ���Ȼ���ǵ�����ɫ��ԭͼ��ͬ�����������̫���ӻ���ûд 
 
class Solution {
public:
	vector<vector<int> > result;
	int line, col;
	void dfs(int sx, int sy, int target, int color) {
		// ֮ǰ��Ϊ�����жϳ��磬��ʵ���������ͱ���Χ�ĵ����Ǹ��ⲻһ��
		// ����û�ж�����Χ����ɫ 
		if (sx >= line || sx < 0 || sy >= col || sy < 0) return;
		// ͬһ��ɫ�Ž���Ⱦɫ��Ҳ������ͨ�������򲻹� 
		if (result[sx][sy] != target) return;
		// �����ɫ��ԭɫ��ͬ���ͻ��������Ⱦɫ������������ͻ�
		// stackoverflow...����������һ�������ܴ��ڵ���ɫ��ǵ�ͼ��
		// Ȼ��dfs������Ⱦ����������ɫ 
		result[sx][sy] = color;
		dfs(sx + 1, sy, target, color);
		dfs(sx - 1, sy, target, color);
		dfs(sx, sy + 1, target, color);
		dfs(sx, sy - 1, target, color);
	}
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
		this->line = image.size(), this->col = image[0].size();
		this->result = image;
		int target = image[sr][sc];
		// ��Ȼ���Ⱦ������Ⱦ�����������ǵ�ѡ�����ж���ԭ��ɫ
		// �Ƿ��ҪȾ����ɫ��ͬ�������Ϳ��Ա��ⲻ��Ҫ�Ĳ��� 
		if (target != newColor) dfs(sr, sc, target, newColor);
//		for (int i = 0; i < line; i++) {
//			for (int j = 0; j < col; j++) {
//				// �ٰ���ɫȾ���� 
//				result[i][j] = result[i][j] != -1 ? result[i][j] : newColor;
//			}
//		}
		return result;
    }
}; 

int main() {
	return 0;
}

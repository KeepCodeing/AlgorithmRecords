// �ҵ��˱Ƚ����ǵ�д��������ģ��DFS���ǵ�����ģ����ûд����ֱ��copy��ww�����������ģ��DFS������Ҳ��ЩҪע��ĵط�... 
class Solution {
public:
	// �������ߵķ���˳��Ӧ������->��->��->�� 
    int mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int > res;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return res;
        int n = matrix.size(), m = matrix[0].size();
        // ��Ϊ��һ��������Ϊ0,0�����ǰ��������ߵ�˳�����Ļ��Ͳ����ߵ������Ҫ�ѵ�һ����ĺ���������Ϊ-1������
		// ���������������ᣩ 
		int cur = 0, cx = 0, cy = -1, cnt = 0;
        while (cnt < m * n) {
            int nx = cx + mv[cur][0], ny = cy + mv[cur][1];
            // �������ж��Ƿ��ڽ��ڣ�����ڽ��ھ��ߣ����ڽ��ھͻ��������� 
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] != INT_MAX) {
                cnt++;
                // ��һ����������һ���Ļ��������� 
                cx = nx, cy = ny;
                res.push_back(matrix[nx][ny]);
                // ���߹��ĵط���� 
                matrix[nx][ny] = INT_MAX;
                // ����߳����ˣ�������������%4�Ǳ�֤���鲻���� 
            } else cur = (cur + 1) % 4;
        }
        return res;
    }
};

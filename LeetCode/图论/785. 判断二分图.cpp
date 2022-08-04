// ��Ϊû����������LeetCode��д���ж϶���ͼ��������˵���ǲ���Щ�ӵ� 
class Solution {
public:
    vector<int > grid[110];
    int color[110];
    bool dfs(int now, int c) {
        color[now] = c;
        for (int i = 0; i < grid[now].size(); i++) {
            int vt = grid[now][i];
            if (color[vt] == color[now]) return false;
            // ȡ����ɫ��Ϊʲô��������д���Բο�����Ľ���... 
            if (!color[vt]&& !dfs(vt, -c)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // �Ƚ�ͼ������
        int gLen = graph.size();
        for (int i = 0; i <gLen; i++) {
            for (auto& j : graph[i]) {
                grid[i].push_back(j);
            }
        }
        // ע�����ͼ�����Ǹ�ɭ�֣����������д��ѭ��ö������û�б�Ⱦɫ�ĵ㣬�����һ�������Ƕ���ͼ��������ɭ��
		// Ҳ�Ͳ��Ƕ���ͼ�� 
        for (int i = 0; i < gLen; i++) {
        	// ����&&�����ʣ�����ǰ��û�б�Ⱦɫ��ʱ��ֵΪ�棬ִ��dfs����������ڵ���ͨ��Ⱦɫ��
			// ��������ͨ�鲻�Ƕ���ͼdfs�ͻ᷵��false��Ȼ�����ȡ�����ͻ᷵��false... 
            if (!color[i] && !dfs(i, 1)) return false;
        }
        return true;
    }
};

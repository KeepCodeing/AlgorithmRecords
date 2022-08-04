// �е�ӵļ��⣬��˵��·���ϵĽڵ����ǰ������ڵ��...����д�˸�BFS�����ԼӸ���֦����Ϊ��һ�����ĸ��ڵ�������Ⱦ�����С��
// Ȼ��Ҫע�����п����ݣ���Ȼ��NP... 
typedef pair<TreeNode*, int > PII;
class Solution {
public:
    int bfs(TreeNode* root) {
        queue<PII> que;
        que.push(PII(root, 1));
        while (que.size()) {
            PII now = que.front(); que.pop();
            TreeNode *nd = now.first;
            if (!nd->left && !nd->right) return now.second;
            if (nd->left) que.push(PII(nd->left, now.second + 1));
            if (nd->right) que.push(PII(nd->right, now.second + 1));
        }
        return 0;
    }
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        return bfs(root);
    }
};

// 有点坑的简单题，它说的路径上的节点数是包括根节点的...这里写了个BFS，可以加个剪枝，因为第一个到的根节点所处深度绝对最小，
// 然后要注意特判空数据，不然会NP... 
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

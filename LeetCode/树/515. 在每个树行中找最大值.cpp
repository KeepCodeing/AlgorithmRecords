/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第19191919419（十九）弹，突然发现自己连树的BFS都忘了，这里总结下
// 图的BFS或者DFS都是直接遍历边，然后把点入队，网格图的话就是遍历位置，树比较特殊，是遍历整个队列，将队列里的
// 所有节点的非空左右子树入队.. 
class Solution {
public:
    vector<int > res;
    queue<TreeNode* > que;
    vector<int> largestValues(TreeNode* root) {
        if (!root) return res;
        que.push(root);
        while (que.size()) {
        	// 这个题卡了最小值... 
            int maxVal = -2147483648;
            int qLen = que.size();
            for (int i = 0; i < qLen; i++) {
                TreeNode* now = que.front();que.pop();
                maxVal = max(maxVal, now->val);
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

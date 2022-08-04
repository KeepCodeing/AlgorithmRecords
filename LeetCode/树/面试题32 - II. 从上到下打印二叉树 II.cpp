/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第二十弹，同样是层次遍历树，但是这个题要将结果返回.. 
class Solution {
public:
    vector<vector<int > > tree;
    queue<TreeNode* > que;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return tree;
        que.push(root);
        while (que.size()) {
            int qLen = que.size();
            // 用一个暂存数组vector存放结果，因为不能直接返回vector数组...，不过这样也就不用记录当前遍历到那一层了.. 
            vector<int > temp;
            for (int i = 0; i < qLen; i++) {
                TreeNode* now = que.front();que.pop();
                temp.push_back(now->val);
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            tree.push_back(temp);
        }
        return tree;
    }
};

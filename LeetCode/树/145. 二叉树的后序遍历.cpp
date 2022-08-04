/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 树专题第四弹，又是模板题呢，注意到这个题的分级是困难，其实难的不是模板，而是怎么用迭代的方式遍历这个树... 

class Solution {
public:
    vector<int > res;
    void pre_order(TreeNode* root) {
        if (!root) return;
        pre_order(root->left);
        pre_order(root->right);
        res.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        pre_order(root);
        return res;
    }
};

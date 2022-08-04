/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 思路是算出每个子树的高度，而不是只算出根节点的左右子树的高度，如果任意一个子树不是平衡的，那么整棵树也就不是平衡的了... 
 
class Solution {
public:
    int pre_order(TreeNode* root) {
        if (!root) return 0;
        // 算高度 
        return max(pre_order(root->left), pre_order(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // 如果当前节点的左右子树不平衡，返回false 
        if (abs(pre_order(root->left) - pre_order(root->right)) > 1) return false;
        // 继续算左右子树的高度 
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

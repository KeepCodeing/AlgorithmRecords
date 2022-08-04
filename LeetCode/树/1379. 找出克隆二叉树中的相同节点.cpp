/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第八弹，这个代码只能用于两个树没有相同值的情况，而且写得和模板一样w 
class Solution {
public:
    TreeNode* res;
    TreeNode* pre_order(TreeNode* root, int target) {
        if (root == NULL) return NULL;
        pre_order(root->left, target);
        pre_order(root->right, target);
        if (root->val == target) res = root; // 这里应该可以加个return加速... 
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        pre_order(cloned, target->val);
        return res;
    }
};

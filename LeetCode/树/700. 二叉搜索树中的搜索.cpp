/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第十二弹，这个题利用到了BST的性质，即左<根<右，因此我们在进行前序遍历的时候就可以根据这个性质逐步逼近
// 目标值，如果当前节点的值比目标值大，那么我们希望的是下次的节点值比目标值小，即往左子树走，否则就往右子树走... 
class Solution {
public:
    TreeNode* res = NULL;
    void pre_order(TreeNode* root, int target) {
        if (!root) return;
        // 如果找到了目标值就记录退出，注意下面没有判断等于的原因就是因为这里写了.. 
        if (root->val == target) {
            res = root;
            return;
        }
        // 根据BST的性质判断往哪个子树走 
        if (root->val > target) pre_order(root->left, target);
        else pre_order(root->right, target);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        pre_order(root, val);
        return res;
    }
};

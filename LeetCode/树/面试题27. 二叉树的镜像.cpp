/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第十弹，这个题以前做过，利用一个前序遍历遍历到所有节点，然后将除了叶子节点的左右子树都进行互换... 
class Solution {
public:
    void in_order(TreeNode* root) {
        if (!root) return;
        // 互换左右节点，为什么叶子节点不会进行互换呢？因为它们没有子树了，所以left,right都是NULL，就被前面的判断剪掉了.. 
        swap(root->left, root->right);
        in_order(root->left);
        in_order(root->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        in_order(root);
        return root;
    }
};

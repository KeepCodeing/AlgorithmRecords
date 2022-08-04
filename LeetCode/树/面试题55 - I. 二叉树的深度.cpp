/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 树专题第五弹，这个题其实以前做过，算是树上DP，不过这里用更加明白的语言解释下
// 首先思考下当前树为空深度是多少，其一开始想的是1，但是如果当前树为空，那它应该是没有深度的，即深度为0，
// 那么最大深度是什么呢？因为给的是一个二叉树，因此最大的深度就是是左子树深度最大还是右子树深度最大，当然还要
// 加上当前这个根的深度1。于是就有了下面的代码，这个代码本质上就是个后序遍历.. 
 
class Solution {
public:
    int pre_order(TreeNode* root) {
        if (!root) return 0;
        return max(pre_order(root->left), pre_order(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return pre_order(root);
    }
};

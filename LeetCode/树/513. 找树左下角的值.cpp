/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第十五弹，这个题一开始题意搞错了，以为就是找最左边最深的第一个左子树的值，事实上这个题找的是
// 第一个访问到的最深处的节点的值，用前序遍历，然后记录最大深度，只有当当前节点所在的深度严格大于最大
// 深度时才进行更新，这样就可以保证我们村的答案永远是第一个最深处的节点，也就是所谓的最左边的节点..另外
// 要注意树的深度从1开始，否则当树只有一个节点时maxDeepth不会进行更新，也就是说结果不会被更新... 
class Solution {
public:
    int maxDeepth = 0, res = 0;
    void in_order(TreeNode* root, int deepth) {
        if (!root) return;
        in_order(root->left, deepth + 1);
        in_order(root->right, deepth + 1);
        if (deepth > maxDeepth) maxDeepth = deepth, res = root->val;
    }
    int findBottomLeftValue(TreeNode* root) {
        in_order(root, 1);
        return res;
    }
};

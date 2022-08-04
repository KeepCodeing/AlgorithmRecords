/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第十六弹，第一次写这么简洁直接返回结果而不是用个全局变量存储，思路就是如果前一个节点的值
// 和当前节点的值不同，那么这棵树就一定不是单值树，否则只有当左右子树都是单值树时整棵树才是单值树。 
class Solution {
public:
    bool in_order(TreeNode* root, int pre) {
    	// 空节点算单值树，值为空 
        if (!root) return true;
        // 如果当前节点的值和上个节点不同，就说明这棵树不是单值树 
        if (root->val != pre) return false;
        // 当左右子树都是单值树时，这棵树才是单值树 
        return in_order(root->left, root->val) && in_order(root->right, root->val);
    }
    bool isUnivalTree(TreeNode* root) {
        return in_order(root, root->val);
    }
};

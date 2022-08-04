/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// ˼·�����ÿ�������ĸ߶ȣ�������ֻ������ڵ�����������ĸ߶ȣ��������һ����������ƽ��ģ���ô������Ҳ�Ͳ���ƽ�����... 
 
class Solution {
public:
    int pre_order(TreeNode* root) {
        if (!root) return 0;
        // ��߶� 
        return max(pre_order(root->left), pre_order(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // �����ǰ�ڵ������������ƽ�⣬����false 
        if (abs(pre_order(root->left) - pre_order(root->right)) > 1) return false;
        // ���������������ĸ߶� 
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

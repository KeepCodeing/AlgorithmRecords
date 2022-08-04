/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ��ר����������ƺ���ֻ����ģ�����������... 

class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (root == NULL) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        mid_order(root);
        return res;
    }
};

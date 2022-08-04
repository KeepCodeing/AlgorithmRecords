/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// ��ר����ĵ�������ģ�����أ�ע�⵽�����ķּ������ѣ���ʵ�ѵĲ���ģ�壬������ô�õ����ķ�ʽ���������... 

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

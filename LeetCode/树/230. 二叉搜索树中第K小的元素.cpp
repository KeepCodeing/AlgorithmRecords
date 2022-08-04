/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// ��ר���ʮ���������������߶���������Ҳ���������Ǵ��˾�����Ҫ�����������Ծͱ�����..
// ��������������BST����������õ����������������������Ȼ��Ŀ�����˸����⣬�������ڲ��뿼����... 
class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        mid_order(root);
        return res[k - 1];
    }
};

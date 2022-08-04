/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// ��ר����ߵ�������������ģ�壬����Ч�ʷǳ���..
// ���ȿ���֪������BST���������һ��������ģ��������벻����ô��O(n)�ķ����⣬���������������ģ��Ȼ��Խ�����˸���.. 

class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        mid_order(root1), mid_order(root2);
        sort(res.begin(), res.end());
        return res;
    }
};

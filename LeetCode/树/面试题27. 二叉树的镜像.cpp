/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר���ʮ�����������ǰ����������һ��ǰ��������������нڵ㣬Ȼ�󽫳���Ҷ�ӽڵ���������������л���... 
class Solution {
public:
    void in_order(TreeNode* root) {
        if (!root) return;
        // �������ҽڵ㣬ΪʲôҶ�ӽڵ㲻����л����أ���Ϊ����û�������ˣ�����left,right����NULL���ͱ�ǰ����жϼ�����.. 
        swap(root->left, root->right);
        in_order(root->left);
        in_order(root->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        in_order(root);
        return root;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר���ʮ��������������õ���BST�����ʣ�����<��<�ң���������ڽ���ǰ�������ʱ��Ϳ��Ը�����������𲽱ƽ�
// Ŀ��ֵ�������ǰ�ڵ��ֵ��Ŀ��ֵ����ô����ϣ�������´εĽڵ�ֵ��Ŀ��ֵС�������������ߣ����������������... 
class Solution {
public:
    TreeNode* res = NULL;
    void pre_order(TreeNode* root, int target) {
        if (!root) return;
        // ����ҵ���Ŀ��ֵ�ͼ�¼�˳���ע������û���жϵ��ڵ�ԭ�������Ϊ����д��.. 
        if (root->val == target) {
            res = root;
            return;
        }
        // ����BST�������ж����ĸ������� 
        if (root->val > target) pre_order(root->left, target);
        else pre_order(root->right, target);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        pre_order(root, val);
        return res;
    }
};

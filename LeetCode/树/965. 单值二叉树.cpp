/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר���ʮ��������һ��д��ô���ֱ�ӷ��ؽ���������ø�ȫ�ֱ����洢��˼·�������ǰһ���ڵ��ֵ
// �͵�ǰ�ڵ��ֵ��ͬ����ô�������һ�����ǵ�ֵ��������ֻ�е������������ǵ�ֵ��ʱ���������ǵ�ֵ���� 
class Solution {
public:
    bool in_order(TreeNode* root, int pre) {
    	// �սڵ��㵥ֵ����ֵΪ�� 
        if (!root) return true;
        // �����ǰ�ڵ��ֵ���ϸ��ڵ㲻ͬ����˵����������ǵ�ֵ�� 
        if (root->val != pre) return false;
        // �������������ǵ�ֵ��ʱ����������ǵ�ֵ�� 
        return in_order(root->left, root->val) && in_order(root->right, root->val);
    }
    bool isUnivalTree(TreeNode* root) {
        return in_order(root, root->val);
    }
};

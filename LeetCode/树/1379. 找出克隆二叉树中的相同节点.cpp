/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר��ڰ˵����������ֻ������������û����ֵͬ�����������д�ú�ģ��һ��w 
class Solution {
public:
    TreeNode* res;
    TreeNode* pre_order(TreeNode* root, int target) {
        if (root == NULL) return NULL;
        pre_order(root->left, target);
        pre_order(root->right, target);
        if (root->val == target) res = root; // ����Ӧ�ÿ��ԼӸ�return����... 
        return NULL;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        pre_order(cloned, target->val);
        return res;
    }
};

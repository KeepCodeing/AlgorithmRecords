/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר���ʮ�嵯�������һ��ʼ�������ˣ���Ϊ���������������ĵ�һ����������ֵ����ʵ��������ҵ���
// ��һ�����ʵ�������Ľڵ��ֵ����ǰ�������Ȼ���¼�����ȣ�ֻ�е���ǰ�ڵ����ڵ�����ϸ�������
// ���ʱ�Ž��и��£������Ϳ��Ա�֤���Ǵ�Ĵ���Զ�ǵ�һ������Ľڵ㣬Ҳ������ν������ߵĽڵ�..����
// Ҫע��������ȴ�1��ʼ��������ֻ��һ���ڵ�ʱmaxDeepth������и��£�Ҳ����˵������ᱻ����... 
class Solution {
public:
    int maxDeepth = 0, res = 0;
    void in_order(TreeNode* root, int deepth) {
        if (!root) return;
        in_order(root->left, deepth + 1);
        in_order(root->right, deepth + 1);
        if (deepth > maxDeepth) maxDeepth = deepth, res = root->val;
    }
    int findBottomLeftValue(TreeNode* root) {
        in_order(root, 1);
        return res;
    }
};

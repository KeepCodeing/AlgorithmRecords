/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// ��ר����嵯���������ʵ��ǰ��������������DP�����������ø������׵����Խ�����
// ����˼���µ�ǰ��Ϊ������Ƕ��٣���һ��ʼ�����1�����������ǰ��Ϊ�գ�����Ӧ����û����ȵģ������Ϊ0��
// ��ô��������ʲô�أ���Ϊ������һ�������������������Ⱦ������������������������������󣬵�Ȼ��Ҫ
// ���ϵ�ǰ����������1�����Ǿ���������Ĵ��룬������뱾���Ͼ��Ǹ��������.. 
 
class Solution {
public:
    int pre_order(TreeNode* root) {
        if (!root) return 0;
        return max(pre_order(root->left), pre_order(root->right)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return pre_order(root);
    }
};

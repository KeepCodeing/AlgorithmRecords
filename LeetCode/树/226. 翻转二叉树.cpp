/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// ��ר�������..������븴���ˣ���һ��ʼ���뷨���ȱ���������Ȼ��Ա������Ľ�������޸�...��ʵ֤�����ǲ����еģ�����
// ��ĿҪ�󷵻صľ��Ǹ���ָ�룬������vector����Σ�����һ�����������������ò���Ϊ2^(k-1)������������һ�����ݲ�����������
// ������û�취��...
// ʵ���������Ĺؼ�������ģ�壬���Ȱ�ģ��д������˵...��ô���ڸ��ڵ㣬�򵥵�˼������ô��������ڵ��������������ʵ��
// �ܼ򵥣�ֻҪ�������������ָ�뽻���¾����ˣ��ɴˣ�ÿ�����������������������... 
public:
    void in_order(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        in_order(root->left);
        in_order(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        in_order(root);
        return root;
    }
};

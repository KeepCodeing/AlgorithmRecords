// ��ר�����������������֪����ԭ��Ҳ��ģ������w
// ��������������BST���������һ���õ����Ǹ��������е����ʣ���ô�𰸾����������һ�Σ�Ȼ��ȡ��������k��Ԫ����
// ��������BST��ǰ��ͺ���������ǰ��������Է���ĵõ�һ������·������������һ����������׺���ʽ... 
class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        mid_order(root);
        return res[res.size() - k];
    }
};

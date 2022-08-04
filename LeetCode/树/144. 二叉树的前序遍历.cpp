/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר���ʮ�ߵ�����Ȼ��ģ���⣬��������õķǵݹ鷽ʽʵ�֣�˼·�Ͼ�����һ��ջģ��ݹ�Ĺ��̣���������
// �м���ط�Ҫע�� 
class Solution {
public:
    vector<int > res;
    vector<int> preorderTraversal(TreeNode* root) {
        // �����ǿ������������Ϊ���ǵ�ѭ����Ĭ�ϸ��ڵ�ǿ���ֻ��ջ�ǿսڵ㣬���Ը��ڵ�Ϊ�յ������Ҫ���� 
		if (!root) return res;
        stack<TreeNode* > stk;
        stk.push(root);
        while (stk.size()) {
            TreeNode* now = stk.top();stk.pop();
            res.push_back(now->val);
            // Ȼ������ȱ������������������������⣬����͵ݹ�������������������˳���Ƿ��ŵģ�������Ҫ��ѹ��
			// ����������ѹ��������... 
            if (now->right) stk.push(now->right);
            if (now->left) stk.push(now->left);
        }
        return res;
    }
};

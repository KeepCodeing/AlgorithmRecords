/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第十七弹，依然是模板题，不过这次用的非递归方式实现，思路上就是用一个栈模拟递归的过程，不过还是
// 有几点地方要注意 
class Solution {
public:
    vector<int > res;
    vector<int> preorderTraversal(TreeNode* root) {
        // 首先是空树的情况，因为我们的循环里默认根节点非空且只入栈非空节点，所以跟节点为空的情况需要特判 
		if (!root) return res;
        stack<TreeNode* > stk;
        stk.push(root);
        while (stk.size()) {
            TreeNode* now = stk.top();stk.pop();
            res.push_back(now->val);
            // 然后就是先遍历左子树还是右子树的问题，这里和递归先左子树再右子树的顺序是反着的，即这里要先压入
			// 右子树，再压入左子树... 
            if (now->right) stk.push(now->right);
            if (now->left) stk.push(now->left);
        }
        return res;
    }
};

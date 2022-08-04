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
// 树专题第六弹..这个题想复杂了，其一开始的想法是先遍历遍树，然后对遍历到的结果进行修改...事实证明这是不可行的，首先
// 题目要求返回的就是个树指针，而不是vector，其次，对于一个满二叉树可能能用步长为2^(k-1)来交换，但是一旦数据不是满二叉树
// 这个题就没办法了...
// 实际上这个题的关键还是在模板，首先把模板写出来再说...那么对于根节点，简单的思考下怎么交换这个节点的左右子树，事实上
// 很简单，只要把其下面的左右指针交换下就行了，由此，每个子树都可以套用这个规则... 
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

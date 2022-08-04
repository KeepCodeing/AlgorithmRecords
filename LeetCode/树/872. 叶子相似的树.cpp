// 树专题第二十三弹，注意这个题要求叶子节点出现的顺序是一样的，而不是次数是一样的.. 
class Solution {
public:
    vector<int > r1, r2;
    void in_order(TreeNode* root, bool flag) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (flag) r1.push_back(root->val);
            else r2.push_back(root->val);
            return;
        }
        in_order(root->left, flag);
        in_order(root->right, flag);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        in_order(root1, true), in_order(root2, false);
        return r1 == r2;
    }
};

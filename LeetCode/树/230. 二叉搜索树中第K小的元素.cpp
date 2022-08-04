/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 树专题第十三弹，摸了两天线段树，今天也在摸，但是打卡了就至少要做两道题所以就爆肝了..
// 这个题就是利用了BST的中序遍历得到的序列是有序的这个概念，虽然题目多问了个问题，不过现在不想考虑呢... 
class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        mid_order(root);
        return res[k - 1];
    }
};

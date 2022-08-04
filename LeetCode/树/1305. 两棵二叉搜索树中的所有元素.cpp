/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 树专题第七弹，这个题管理套模板，但是效率非常低..
// 首先可以知道两个BST的中序遍历一定是有序的，但是其想不到怎么用O(n)的方法解，所以这个题管理的套模板然后对结果排了个序.. 

class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        mid_order(root1), mid_order(root2);
        sort(res.begin(), res.end());
        return res;
    }
};

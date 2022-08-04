/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 抄题解的w...，没有好好思考.. 
class Solution {
public:
    TreeNode* in_order(TreeNode* root, int target) {
        // if (root->left->val == target && !root->left->left && !root->left->right) {
        //     root->left = NULL;
        //     return;
        // }
        // if (root->right->val == target && !root->right->left && !root->right->right) {
        //     root->right = NULL;
        //     return;
        // }
        if (!root) return NULL;
        if (!root->left && !root->right && root->val == target) return NULL;
        if (root->left) root->left = in_order(root->left, target);
        if (root->right) root->right = in_order(root->right, target);
        if (!root->left && !root->right && root->val == target) return NULL;
        else return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == nullptr)return nullptr;
        if(!root->left && !root->right && root->val == target){
            return nullptr;//不要用delete，否则无法通过
        }
        if(root->left)root->left = removeLeafNodes(root->left,target);
        if(root->right)root->right = removeLeafNodes(root->right,target);
        if(!root->left && !root->right && root->val == target){
            return nullptr;
        }
        else return root;
    }
};

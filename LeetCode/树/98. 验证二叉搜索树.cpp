#include <iostream>
using namespace std;

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
public:
    vector<int > vec;
    void mid_order(TreeNode* root) {
        if (root == NULL) return;
        mid_order(root->left);
        vec.push_back(root->val);
        mid_order(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        mid_order(root);
        int vLen = vec.size();
        for (int i = 0; i < vLen - 1; i++) 
            if (vec[i] >= vec[i + 1]) return false;
        return true;
    }
};

int main() {
	return 0;
}

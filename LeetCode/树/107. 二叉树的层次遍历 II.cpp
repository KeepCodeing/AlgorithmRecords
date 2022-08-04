/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树专题第二十二弹，LeetCode好多水题... 
class Solution {
public:
    vector<vector<int > > res;
    queue<TreeNode* > que;
    void rev(vector<vector<int>>& vec) {
        int left = 0, right = vec.size() - 1;
        while (left < right) swap(vec[left++], vec[right--]);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return res;
        que.push(root);
        while (que.size()) {
            int qLen = que.size();
            vector<int > temp;
            while (qLen--) {
                TreeNode* now = que.front();que.pop();
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
                temp.push_back(now->val);
            }
            res.push_back(temp);
        }
        rev(res);
        return res;
    }
};

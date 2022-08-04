// 树专题第二十七弹，刷一题少一题了w 
class Solution {
public:
    vector<int > vec;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        vec.push_back(root->val);
        mid_order(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        mid_order(root);
        int vLen = vec.size();
        int minRes = INT_MAX;
        for (int i = 0; i < vLen - 1; i++) minRes = min(abs(vec[i] - vec[i +1]), minRes);
        return minRes;
    }
};

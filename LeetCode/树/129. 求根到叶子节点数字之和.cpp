// 树专题第十八弹，这题写了两个版本 
// 直接将路径转换为数字求和，效率较高 
class Solution {
public:
    long long res = 0;
    void in_order(TreeNode* root, int path) {
        if (!root) return;
        if (!root->left && !root->right) {
            res += path * 10 + root->val;
            return;
        }
        in_order(root->left, path * 10 + root->val);
        in_order(root->right, path * 10 + root->val);
    }
    int sumNumbers(TreeNode* root) {
        in_order(root, 0);
        return res;
    }
};
// 转化为字符串再求和，效率很低
class Solution {
public:
    vector<int > nums;
    char num2char(int n) {
        return n + '0';
    }
    void in_order(TreeNode* root, string path) {
        if (!root) return;
        if (!root->left && !root->right) {
            stringstream ss;
            int temp;
            ss << (path + num2char(root->val)), ss >> temp, nums.push_back(temp);
            return;
        }
        in_order(root->left, path + num2char(root->val));
        in_order(root->right, path + num2char(root->val));
    }
    int sumNumbers(TreeNode* root) {
        in_order(root, "");
        long long res = 0;
        for (auto& i : nums) res += i;
        return res;
    }
}; 

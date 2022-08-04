// 树专题第二十一弹，这个题也是层次打印，不过有个翻转而已，注意双指针效率更高 
class Solution {
public:
    vector<vector<int > > res;
    queue<TreeNode* > que;
    void rev(vector<int >& vec) {
        int left = 0, right = vec.size() - 1;
        while (left < right) swap(vec[left++], vec[right--]);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return res;
        que.push(root);
        bool flag = true;
        while (que.size()) {
            int qLen = que.size();
            vector<int > temp;
            flag = !flag;
            while (qLen--) {
                TreeNode* now = que.front();que.pop();
                temp.push_back(now->val);
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            if (flag) rev(temp);
            res.push_back(temp);
        }
        return res;
    }
};

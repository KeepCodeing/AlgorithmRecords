// 树专题第二十五弹...，BFS然后层次求和就行了，注意开long long..另外其发现把long long开外面会快很多，但是内存并没有
// 什么减少，而如果把TreeNode*开外面就会慢很多... 
class Solution {
public:
    queue<TreeNode* > que;
    vector<double > res;
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return res;
        que.push(root);
        long long tot;
        while(que.size()) {
            int qLen = que.size();
            tot = 0;
            int cnt = 0;
            while (qLen--) {
                TreeNode* now = que.front();que.pop();
                tot += now->val, cnt++;
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            res.push_back((double)tot / cnt);
        }    
        return res;
    }
};

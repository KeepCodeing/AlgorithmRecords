// ��ר��ڶ�ʮһ���������Ҳ�ǲ�δ�ӡ�������и���ת���ѣ�ע��˫ָ��Ч�ʸ��� 
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

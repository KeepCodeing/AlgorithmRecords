// ��ר��ڶ�ʮ�嵯...��BFSȻ������;����ˣ�ע�⿪long long..�����䷢�ְ�long long��������ܶ࣬�����ڴ沢û��
// ʲô���٣��������TreeNode*������ͻ����ܶ�... 
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

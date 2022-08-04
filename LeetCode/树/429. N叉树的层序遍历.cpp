// ��ר��ڶ�ʮ��������Ȼ������ģ�壬������Ҳֻ���������... 
class Solution {
public:
    vector<vector<int > > res;
    queue<Node* > que;
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return res;
        que.push(root);
        while (que.size()) {
            int qLen = que.size();
            vector<int > temp;
            while (qLen--) {
                Node* now = que.front();que.pop();
                // ע���Ǽ�����һ��Ľڵ��ֵ�����Ǽ��ӽڵ��ֵ... 
                temp.push_back(now->val);
                for (auto& i : now->children) {
                    if (!i) continue;
                    que.push(i);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};

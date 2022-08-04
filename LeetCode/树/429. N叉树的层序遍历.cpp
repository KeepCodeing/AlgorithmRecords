// 树专题第二十六弹，虽然会了套模板，但好像也只会了这个呢... 
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
                // 注意是加入这一层的节点的值，不是加子节点的值... 
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

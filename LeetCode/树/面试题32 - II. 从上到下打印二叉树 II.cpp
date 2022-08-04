/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר��ڶ�ʮ����ͬ���ǲ�α����������������Ҫ���������.. 
class Solution {
public:
    vector<vector<int > > tree;
    queue<TreeNode* > que;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return tree;
        que.push(root);
        while (que.size()) {
            int qLen = que.size();
            // ��һ���ݴ�����vector��Ž������Ϊ����ֱ�ӷ���vector����...����������Ҳ�Ͳ��ü�¼��ǰ��������һ����.. 
            vector<int > temp;
            for (int i = 0; i < qLen; i++) {
                TreeNode* now = que.front();que.pop();
                temp.push_back(now->val);
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            tree.push_back(temp);
        }
        return tree;
    }
};

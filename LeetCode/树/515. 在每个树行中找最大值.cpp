/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��ר���19191919419��ʮ�ţ�����ͻȻ�����Լ�������BFS�����ˣ������ܽ���
// ͼ��BFS����DFS����ֱ�ӱ����ߣ�Ȼ��ѵ���ӣ�����ͼ�Ļ����Ǳ���λ�ã����Ƚ����⣬�Ǳ����������У����������
// ���нڵ�ķǿ������������.. 
class Solution {
public:
    vector<int > res;
    queue<TreeNode* > que;
    vector<int> largestValues(TreeNode* root) {
        if (!root) return res;
        que.push(root);
        while (que.size()) {
        	// ����⿨����Сֵ... 
            int maxVal = -2147483648;
            int qLen = que.size();
            for (int i = 0; i < qLen; i++) {
                TreeNode* now = que.front();que.pop();
                maxVal = max(maxVal, now->val);
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            res.push_back(maxVal);
        }
        return res;
    }
};

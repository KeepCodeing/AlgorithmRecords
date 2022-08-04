// ��ר��ڶ�ʮ�ĵ�desu�����⣬��BFS��α���Ȼ��˫ָ�������.. 
class Solution {
public:
    
    queue<TreeNode* > que;
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        que.push(root);
        while (que.size()) {
            int qLen = que.size();
            vector<TreeNode* > vec;
            while (qLen--) {
                TreeNode* now = que.front();que.pop();
                // ��Ϊ���ж����������Ƿ���ͬ���������ﲻ�ܵ�ǰ�ڵ��Ƿ�Ϊ�ն��üӽ�ȥ 
                vec.push_back(now);
                // Ϊ�˷�ֹ���ֿ�ָ��������ж��£�����Ķ��мӵ�����ָ������Ǹ��յģ�������Ӱ�� 
                if (!now) continue;
                que.push(now->left);
                que.push(now->right);
            }
            int left = 0, right = vec.size() - 1;
            // ��ǰ�������ԳƵ�����ǰ�ᣬֵ��Ȼ���ͬʱΪ��... 
            while (left < right) {
                if (!vec[left] || !vec[right]) {
                    if (!vec[left] && !vec[right]) {
                        left++, right--;
                        continue;
                    }
                    return false;
                }
                if (vec[left]->val != vec[right]->val) return false;
                left++, right--;
            }
        }
        return true;
    }
};

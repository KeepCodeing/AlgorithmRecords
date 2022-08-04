// 树专题第二十四弹desu，打卡题，用BFS层次遍历然后双指针就行了.. 
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
                // 因为是判断左右子树是否相同，所以这里不管当前节点是否为空都得加进去 
                vec.push_back(now);
                // 为了防止出现空指针这里得判断下，这里的队列加的左右指针可能是个空的，不过不影响 
                if (!now) continue;
                que.push(now->left);
                que.push(now->right);
            }
            int left = 0, right = vec.size() - 1;
            // 当前二叉树对称的两个前提，值相等或者同时为空... 
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

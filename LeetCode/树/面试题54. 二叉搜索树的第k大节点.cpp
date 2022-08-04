// 树专题第三弹，这个题如果知道了原理也是模板题呢w
// 这个题就是利用了BST的中序遍历一定得到的是个升序序列的性质，那么答案就是中序遍历一次，然后取出倒数第k个元素了
// 另外提下BST的前序和后续遍历，前序遍历可以方便的得到一个搜索路径，后续遍历一般用来做后缀表达式... 
class Solution {
public:
    vector<int > res;
    void mid_order(TreeNode* root) {
        if (!root) return;
        mid_order(root->left);
        res.push_back(root->val);
        mid_order(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        mid_order(root);
        return res[res.size() - k];
    }
};

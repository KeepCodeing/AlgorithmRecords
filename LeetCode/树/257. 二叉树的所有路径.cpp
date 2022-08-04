class Solution {
public:
    vector<string > res;
    // 坑点，这个题没说所有节点的值都是0~9的数字，它可能是两位数，甚至负数，也就是说这里得专门写个方法转换数字 
    string num2str(int n) {
        stringstream ss;
        string str;
        ss << n, ss >> str;
        return str;
    }
    void pre_order(TreeNode* root, string str) {
        if (!root->left && !root->right) {
            // 注意路径应该包含根节点的值 
			res.push_back(str + num2str(root->val));
            return;
        }
        // 注意这里要求的是到叶子节点的路径，也就是普通X序遍历是不可行的，这是为什么呢？因为它会把空节点也放到路径里，那么如果结合
		// 普通的递归跳出条件，空节点就会被当成叶子节点，这很明显是错误的...
		// 改进之后应该将所有路径上的点都判断下是否为空，然后将递归出口条件改成当前节点没有左右子树，这样就能判断一个节点是否是根节点
		// 了 
        if (root->left) pre_order(root->left, str + num2str(root->val) + "->");
        if (root->right) pre_order(root->right, str + num2str(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return res;
        pre_order(root, "");
        return res;
    }
};

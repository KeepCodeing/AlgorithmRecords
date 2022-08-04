/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// 树专题第十四弹，肝完第的第二个题，一般来说二叉树的最大深度都可以用一个dp来解
// 就是return max(maxDeepth(root->left), maxDeepth(root->right)) + 1（突然觉得类似线段树的查询w），但是这里给的
// 一个多叉树，其不知道怎么搞，不过真如那篇文章所说，二叉树大多是模板，所以做到现在又拿出了模板，这里用的后序遍历
// 每次统计最大深度，很类似求二叉树的最深叶子节点那个题呢...另外这里二叉树深度默认从1开始，为空就是0，也就是没有
// 左右子树，所以不用担心会出现错误... 
class Solution {
public:
    int res = 0;
    void pre_order(Node* root, int deepth) {
        if (!root) return;
        for (auto& i : root->children) pre_order(i, deepth + 1);
        res = max(res, deepth);
    }
    int maxDepth(Node* root) {
        pre_order(root, 1);
        return res;
    }
};

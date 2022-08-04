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
// 二叉树第十一弹，还是模板题...不过多叉树有没有中序遍历呢... 
class Solution {
public:
    vector<int > res;
    void pre_mid(Node* root) {
        if (!root) return;
        for (auto& i : root->children) pre_mid(i);
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        pre_mid(root);
        return res;
    }
};

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

// 树专题的第二弹，不管怎么说，从早摸到下午，课多..痿... 

class Solution {
public:
    vector<int > res;
    void in_order(Node *root) {
        if (root == NULL) return;
        res.push_back(root->val);
        // 不管是几叉树，都可以用这个模板..，要注意的就是添加答案的顺序了... 
        for (auto& i : root->children) in_order(i);
    }
    vector<int> preorder(Node* root) {
        in_order(root);
        return res;
    }
};

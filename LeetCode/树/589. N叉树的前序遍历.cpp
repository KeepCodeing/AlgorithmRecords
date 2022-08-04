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

// ��ר��ĵڶ�����������ô˵�������������磬�ζ�..��... 

class Solution {
public:
    vector<int > res;
    void in_order(Node *root) {
        if (root == NULL) return;
        res.push_back(root->val);
        // �����Ǽ������������������ģ��..��Ҫע��ľ�����Ӵ𰸵�˳����... 
        for (auto& i : root->children) in_order(i);
    }
    vector<int> preorder(Node* root) {
        in_order(root);
        return res;
    }
};

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
// ��ר���ʮ�ĵ�������ڵĵڶ����⣬һ����˵�������������ȶ�������һ��dp����
// ����return max(maxDeepth(root->left), maxDeepth(root->right)) + 1��ͻȻ���������߶����Ĳ�ѯw���������������
// һ����������䲻֪����ô�㣬����������ƪ������˵�������������ģ�壬���������������ó���ģ�壬�����õĺ������
// ÿ��ͳ�������ȣ��������������������Ҷ�ӽڵ��Ǹ�����...����������������Ĭ�ϴ�1��ʼ��Ϊ�վ���0��Ҳ����û��
// �������������Բ��õ��Ļ���ִ���... 
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

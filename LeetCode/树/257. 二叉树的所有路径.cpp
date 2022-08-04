class Solution {
public:
    vector<string > res;
    // �ӵ㣬�����û˵���нڵ��ֵ����0~9�����֣�����������λ��������������Ҳ����˵�����ר��д������ת������ 
    string num2str(int n) {
        stringstream ss;
        string str;
        ss << n, ss >> str;
        return str;
    }
    void pre_order(TreeNode* root, string str) {
        if (!root->left && !root->right) {
            // ע��·��Ӧ�ð������ڵ��ֵ 
			res.push_back(str + num2str(root->val));
            return;
        }
        // ע������Ҫ����ǵ�Ҷ�ӽڵ��·����Ҳ������ͨX������ǲ����еģ�����Ϊʲô�أ���Ϊ����ѿսڵ�Ҳ�ŵ�·�����ô������
		// ��ͨ�ĵݹ������������սڵ�ͻᱻ����Ҷ�ӽڵ㣬��������Ǵ����...
		// �Ľ�֮��Ӧ�ý�����·���ϵĵ㶼�ж����Ƿ�Ϊ�գ�Ȼ�󽫵ݹ���������ĳɵ�ǰ�ڵ�û���������������������ж�һ���ڵ��Ƿ��Ǹ��ڵ�
		// �� 
        if (root->left) pre_order(root->left, str + num2str(root->val) + "->");
        if (root->right) pre_order(root->right, str + num2str(root->val) + "->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return res;
        pre_order(root, "");
        return res;
    }
};

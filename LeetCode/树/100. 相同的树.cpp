#include <iostream>
using namespace std;

// �����½̳��ƺ�������ʼˢ�����°빦�������ӣ���ô����ǵ�һ����������..
// ˼·���Ƿֱ�Ա����������Ƿ���ͬ
// ���ȿ��ǲ�ͬ�����
// �����ǰ������/������ΪNULL��������һ��������/��������Ϊ�գ���������������ͬ
// �����ǰ���ĸ���ֵ����һ�����ĸ���ֵ��ͬ����������������ͬ 
// ��ο�����ͬ�����
// ��Ϊ��ͬ������Ѿ������Ǽ�ȥ�ˣ������������ͬ��������������ͬ������ֵ��ͬ
// ����ֻ�����ж������������У���Ϊֵ�������������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) return true; // �����������Ϊ�գ�����Ϊ����ͬ
        // ע�������жϵ�˳��Ӧ�����ж����������Ƿ�Ϊ�գ�Ϊ�յĻ�����û��val������� 
        if (p == NULL || q == NULL) return false;// �����������ֻ��һ��Ϊ�գ�����Ϊ�䲻��ͬ
		if (p->val != q->val) return false; // �������ֵ��ͬ������Ϊ�䲻��ͬ
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // �����������ȫ��ͬ������������Ҳ����ͬ�� 
    }
}; 

int main() {
	return 0;
}

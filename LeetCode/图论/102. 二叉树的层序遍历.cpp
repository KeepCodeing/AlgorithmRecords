#include <iostream>
using namespace std;

// ���BFS������...��������Ϊ̫�����������ⶼû��ô����������... 
// ����BFS����û����һ��...����¼��˼·�����Ƚ�һ��ĸ��ڵ���ӣ�Ȼ������������У����մ������ң��������ָ���˳�򣩵�˳��
// ���ν����Һ�����ӣ��������ƾ��ܵõ����Ĳ�α����ˣ��Ա�ͼ�ı��������ı�������Ҫ��visited���飬��Ϊ�������ڻ�·.. 

// ��ô�Ա�������ͼ��BFS���������ı��������Ǵ���㿪ʼ������������ֱ�ӵ���ĵ㣨�бߵĵ㣩��ӣ�Ȼ���Դ����ƣ�����Ҫע��
// ����ͼ�����ø�visited�����Ƿ��ʹ��Ľڵ�ı�ţ�����������ѭ�� 

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
	queue<TreeNode > que;
	vector<vector<int > > res;
    vector<vector<int> > levelOrder(TreeNode* root) {
        if (root == NULL) return res;
        bfs(root);
        return res;
    }
    void bfs(TreeNode* root) {
    	queue<TreeNode* > que;
        que.push(root);
        while (que.size()) {
            vector<int > temp;
            int len = que.size();
            while (len--) {
                TreeNode* now = que.front();que.pop();
                temp.push_back({now->val});
                if (now->left) que.push(now->left);
                if (now->right) que.push(now->right);
            }
            res.push_back(temp);
        }
	}
}; 

int main() {
	return 0;
}

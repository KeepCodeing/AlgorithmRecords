#include <iostream>
using namespace std;

// 裸的BFS遍历题...，不过因为太简单所以这种题都没怎么做过的样子... 
// 树的BFS就像没做过一样...，记录下思路：首先将一层的根节点入队，然后遍历整个队列，按照从左往右（队列添加指针的顺序）的顺序
// 依次将左右孩子入队，依次类推就能得到树的层次遍历了，对比图的遍历，树的遍历不需要用visited数组，因为树不存在环路.. 

// 那么对比下无向图的BFS遍历，它的遍历过程是从起点开始，将其所有能直接到达的点（有边的点）入队，然后以此类推，另外要注意
// 无向图必须用个visited数组标记访问过的节点的编号，否则会出现死循环 

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

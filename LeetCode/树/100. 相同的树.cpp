#include <iostream>
using namespace std;

// 看了下教程似乎从树开始刷可以事半功倍的样子，那么这就是第一道树的题了..
// 思路就是分别对比左右子树是否相同
// 首先考虑不同的情况
// 如果当前树的左/右子树为NULL，但是另一个树的左/右子树不为空，则这两个树不相同
// 如果当前树的根的值和另一个树的根的值不同，则这两个树不相同 
// 其次考虑相同的情况
// 因为不同的情况已经被我们剪去了，因此两个树相同就是左右子树相同，根的值相同
// 这里只用先判断左右子树就行，因为值的情况后面会剪掉

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
        if (p == NULL && q == NULL) return true; // 如果两个树的为空，则认为其相同
        // 注意这里判断的顺序，应该先判断这两个树是否为空，为空的话根就没有val这个属性 
        if (p == NULL || q == NULL) return false;// 如果这两个树只有一个为空，则认为其不相同
		if (p->val != q->val) return false; // 如果根的值不同，则认为其不相同
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // 如果左右子树全相同，则这两个树也是相同的 
    }
}; 

int main() {
	return 0;
}

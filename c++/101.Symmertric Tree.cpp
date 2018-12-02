/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归版，时间复杂度O(n), 空间复杂度O(logn)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *root1, TreeNode *root2)
    {
    	if(root1 == NULL && root2 == NULL) return true;
    	if(root1 == NULL || root2 == NULL) return false;
    	return (root1->val == root2->val
    			&& isSymmetric(root1->left, root2->right)
    			&& isSymmetric(root1->right, root2->left) );
    }
};

// 迭代版，时间复杂度O(n), 空间复杂度O(logn)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        // 栈 s 存放树节点的地址
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty())
        {
        	// 取出栈顶的两个元素
        	auto p = s.top(); s.pop();
        	auto q = s.top(); s.pop();
        	// p 和 q 都为空
        	if(!p && !q) continue;
        	// p 和 q 有一个为空
        	if(!p || !q) return false;
        	if(p->val != q->val) return false;

        	s.push(p->left);
        	s.push(q->right);

        	s.push(p->right);
        	s.push(q->left);
        }
        return true;
    }
};
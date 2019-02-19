/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 迭代方法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> ret;
    	// 栈 st 存放结点的地址
    	stack<TreeNode*> st;
    	while(!st.empty() || root){
    		// 结点不为 NULL
    		if(root){
    			st.push(root);
    			root = root->left;
    		}else{
    			root = st.top(); st.pop();
    			v.push_back(root->val);
    			root = root->right;
    		}
    	}       
    	return ret;
    }
};

// 递归方法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);
        return v;
    }

    void inOrder(TreeNode* root, vector<int> &v){
		if(root == NULL) return;
		inOrder(root->left, v);
		v.push_back(root->val);
		inOrder(root->right, v);
	}
};
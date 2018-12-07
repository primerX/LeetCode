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
    int kthSmallest(TreeNode* root, int k) {
    	vector<int> nums;
        inorder(root, nums);
        return nums[k-1];
    }

    void inorder(TreeNode *root, vector<int> &nums){
    	if(root == NULL) return;
    	inorder(root->left, nums);
    	nums.push_back(root->val);
    	inorder(root->right, nums);
    }
};


// 非递归解法
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(!st.empty() || root){
        	while(root){
        		st.push(root);
        		root = root->left;
        	}
        	root = st.top()->right;
        	k--;
        	if(k == 0) return st.top()->val;
        	st.pop();
        }
        return -1;
    }
};
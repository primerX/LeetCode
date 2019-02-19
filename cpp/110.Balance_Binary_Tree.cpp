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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        // 左子树与右子树的高度
        int LHeight = treeDepth(root->left);
        int RHeight = treeDepth(root->right);

        if(LHeight - RHeight > 1 || LHeight - RHeight < -1){
        	return false;
        } 

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int treeDepth(TreeNode *root){
    	if(root == NULL){
    		return 0;
    	}
    	int LHeight = 1, RHeight = 1;

    	LHeight += treeDepth(root->left);
    	RHeight += treeDepth(root->right);

    	return LHeight > RHeight ? LHeight : RHeight;
    }
};
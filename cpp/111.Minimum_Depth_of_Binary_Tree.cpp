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
    int minDepth(TreeNode* root) {
        if(root == NULL){
        	return 0;
        }
        if(root->left == NULL && root->right == NULL){
        	return 1;
        }
        int leftDepth = INT_MAX, rightDepth = INT_MAX;
        if(root->left){
        	leftDepth = minDepth(root->left) + 1;
        }
        if(root->right){
        	rightDepth = minDepth(root->right) + 1;
        }
        return leftDepth < rightDepth ? leftDepth : rightDepth;
    }
};
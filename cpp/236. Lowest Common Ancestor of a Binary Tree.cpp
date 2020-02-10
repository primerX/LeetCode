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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	//return if found or not found, return NULL if not found
        if(root == NULL || root == p || root == q) return root;

        //find the LCA in left tree
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        //find the LCA in right tree
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // left==NULL means both `p` and `q` are not found in left tree.
        if(left == NULL) return right;
        // right==NULL means both `p` and `q` are not found in right tree.
        if(right == NULL) return left;
        // left!=NULL && right !=NULL, which means `p` & `q` are seperated in left and right tree.
        return root;
    }
};
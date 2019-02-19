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
    void inorder(TreeNode *root, vector<int> &vi){
    	if(root == NULL) return;
    	inorder(root->left, vi);
    	vi.push_back(root->val);
    	inorder(root->right, vi);
    }
    
    bool isValidBST(TreeNode* root) {
    	// 空节点 或者 只有一个根结点
		if(root == NULL || (root->left == NULL && root->right == NULL)){
			return true;
		}
		// vi 用来记录中序遍历的结果
		vector<int> vi;
		// 对树进行中序遍历，如果中序遍历结果为递增
		// 则证明该树为二叉搜索树
		inorder(root, vi);
		for(int i = 1; i < vi.size(); i++){
			if(vi[i] <= vi[i-1]) return false;
		}
		return true;
    }

    
};
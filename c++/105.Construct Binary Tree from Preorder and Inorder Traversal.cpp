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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size());
    }

    TreeNode* createTree(vector<int> &preorder, vector<int> &inorder,int preL, int preR, int inL, int inR)
    {
    	if(preL > preR){
    		return NULL;
    	}
    	// 创建根结点
    	TreeNode* root = new TreeNode(preorder[preL]);
    	// 在中序序列中找出根结点的位置
    	int k = inL;
    	for(k; k <= inR; k++){
    		if(preorder[preL] == inorder[k]){
    			break;
    		}
    	}
    	// 左子树结点数
    	int numLeft = k - inL;

    	root->left = createTree(preorder, inorder, preL+1, preL+numLeft, inL, k-1);

    	root->right = createTree(preorder, inorder, preL+numLeft+1, preR, k + 1, inR);
        
        return root;

    }
};
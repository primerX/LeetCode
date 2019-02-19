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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* createTree(const vector<int>& inorder, const vector<int> &postorder, int inL, int inR, int posL, int posR){
    	if(posL > posR) return NULL;
    	// 创建根结点
    	TreeNode *root = new TreeNode(postorder[posR]);

    	// 在中序序列中找出根结点的位置
    	int k = inL;
    	for(k; k <= inR; k++){
    		if(inorder[k] == postorder[posR]){
    			break;
    		}
    	}
    	// 左子树的结点数
    	int numLeft = k - inL;

    	root->left = createTree(inorder, postorder, inL, k-1, posL, posL+numLeft-1);

    	root->right = createTree(inorder, postorder, k+1, inR, posL+numLeft, posR-1);

    	return root;
    }
};
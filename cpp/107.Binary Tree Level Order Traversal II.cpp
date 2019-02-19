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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> row;
        vector<vector<int>> res;
        if(root == NULL){
        	return res;
        }
        // 注意：队列 q 里面存的是地址
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        while(!q.empty()){
        	int size = q.size();
        	while(size--){
        		temp = q.front();
        		q.pop();
        		row.push_back(temp->val);
        		if(temp->left != NULL){
        			q.push(temp->left);
        		}
        		if(temp->right != NULL){
        			q.push(temp->right);
        		}
        	}
        	res.insert(res.begin(), row);
        	row.clear();
        }
        return res;
    }
};
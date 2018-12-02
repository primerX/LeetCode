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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> current, next;
        if(root == NULL) return result;

        current.push(root);
        while(!current.empty())
        {
        	// level 记录每一层结点的 val
        	vector<int> level;
        	// 取出 current 中的所有树结点
        	while(!current.empty())
        	{
        		TreeNode *node = current.front();
        		current.pop();
        		level.push_back(node->val);
        		if(node->left != NULL) next.push(node->left);
        		if(node->right != NULL) next.push(node->right);
        	}
        	result.push_back(level);
        	swap(next, current);
        }
        return result;
    }
};
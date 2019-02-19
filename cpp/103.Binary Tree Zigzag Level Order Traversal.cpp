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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> v;
		if(root == NULL) return v;

		queue<TreeNode*> q;
		vector<int> row;

		q.push(root);
		int lev = 0;

		while(!q.empty()){
			int size = q.size();
			while(size--){
				// 取出队列首元素
				TreeNode *temp = q.front();
				q.pop();
				row.push_back(temp->val);
				if(temp->left != NULL) { q.push(temp->left); }
				if(temp->right != NULL) { q.push(temp->right); }
			}
			if(lev % 2){		// 偶数层
				reverse(row.begin(), row.end());
			}
			v.push_back(row);
			lev++;
			row.clear();
		}
		return v;
    }
};
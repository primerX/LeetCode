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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums.begin(), nums.end());
    }

    TreeNode* func(vector<int>::iterator beg, vector<int>::iterator end)
    {
    	if(beg == end) return NULL;
    	auto mid = beg + (end - beg)/2;
    	TreeNode *root = new TreeNode(*mid);
    	root->left = func(beg, mid);
    	root->right = func(std::next(mid), end);
    	return root;
    }
};
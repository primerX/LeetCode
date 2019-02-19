/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return function(head, NULL);
    }

    TreeNode *function(ListNode* head, ListNode *tail){
    	// 利用双指针求解问题
    	ListNode *fast = head, *slow = head;
    	if(head == tail) return NULL;
    	// 找到中点
    	while(fast != tail && fast->next != tail){
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	TreeNode *root = new TreeNode(slow->val);
    	root->left = function(head, slow);
    	root->right = function(slow->next, tail);
    	return root;
    }
};
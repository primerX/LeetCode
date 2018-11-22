/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n < 1){
        	return head;
        }
        ListNode *cur = head;
        while(cut != NULL){
        	n--;
        	cur = cut->next;
        }
        if(n == 0){			// 链表长度刚好等于 n
        	head = head->next;
        }
        if(n < 0){
        	cur = head;
        	while(++n != 0){
        		cur = cur->next;
        	}
        	cur->next = cur->next->next;
        }
        return head;
    }
};
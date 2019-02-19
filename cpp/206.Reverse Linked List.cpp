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
	// 迭代方法反转链表
	ListNode* reverseList_iteratively(ListNode* head){
		ListNode *p = nullptr, *q = nullptr;
        while(head)
        {
        	q = head->next;
        	head->next = p;
        	p = head;
        	head = q;
        }
        return p;
	}

	// 递归方法反转链表
	ListNode* reverseList_recursively(ListNode* head){
		// 该链表为空，或只有一个结点
		if(head == NULL || head->next == NULL){
			return head;
		}
		ListNode *p = reverseList_recursively(head->next);
		head->next->next = head;
		head->next = NULL;
		return p;
	}

    ListNode* reverseList(ListNode* head) {
    	return reverseList_iteratively(head);
        //return reverseList_recursively(head);
    }
};
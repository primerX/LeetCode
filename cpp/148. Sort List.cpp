/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 常数空间O(nlogn)，单链表适合归并排序，双向链表适合快速排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        // 快慢指针找到中间结点
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
        	slow = slow->next;
        	fast = fast->next->next;
        }
        // 断开
        fast = slow->next;
        slow->next = NULL;

        ListNode *l1 = sortList(head);	// 前半段排序
        ListNode *l2 = sortList(fast);	// 后半段排序
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode *head1, ListNode *head2){
    	ListNode *p1 = head1, *p2 = head2;
    	ListNode dummpy(-1);
    	ListNode *tail = &dummpy;
    	while(p1 && p2){
    		if(p1->val < p2->val){
    			tail->next = p1;
    			p1 = p1->next;
    		}else{
    			tail->next = p2;
    			p2 = p2->next;
    		}
    		tail = tail->next;
    	}
    	if(p1) tail->next = p1;
    	if(p2) tail->next = p2;
    	return dummpy.next;
    }
};
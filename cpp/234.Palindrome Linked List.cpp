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
	// 找到链表的终点
	ListNode* findMiddle(ListNode* head)
	{
		ListNode *p = head, *q = head;
		while(q && q->next)
		{
			p = p->next;
			q = q->next->next;
		}
		return p;
	}

	// 反转链表
	ListNode* reverseLink(ListNode* head)
	{
		ListNode *p = nullptr, *q = nullptr;
		while(head)
		{
			ListNode *q = head->next;
			head->next = p;
			p = head;
			head = q;
		}
		return p;
	}

    bool isPalindrome(ListNode* head) {
    	// 找到链表的中间结点
        ListNode *pMid = findMiddle(head);
        // 将链表从中间结点一分为二
        ListNode *pRev = reverseLink(pMid);

        for( ;head != pMid; head = head->next, pRev = pRev->next){
        	if(head->val != pRev->val){
        		return false;
        	}
        }
        return true;
    }
};
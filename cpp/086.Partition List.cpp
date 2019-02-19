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
    ListNode* partition(ListNode* head, int x) {
    	// 创建一个新的头结点，方便操作
        ListNode fakeHead(0);
        fakeHead.next = head;
        head = &fakeHead;

        // pos 指向第一个大于等于 x 的结点位置
        ListNode *pos = nullptr;
        for(ListNode *p = head; p && p->next;){
        	if(!pos && p->next->val >= x){
        		pos = p;
        		p = p->next;
        		continue;
        	}
        	if(pos && p->next->val < x){
        		ListNode *pNext = p->next;
        		p->next = pNext->next;
        		pNext->next = pos->next;
        		pos->next = pNext;
        		pos = pNext;
        		continue;
        	}
        	p = p->next;
        }
        return head->next;
    }
};
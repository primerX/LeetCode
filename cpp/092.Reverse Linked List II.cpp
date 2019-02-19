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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m >= n) return head;
        n -= m;     // 重要的一步
        // 创建新的头结点 preHead
        ListNode preHead(0);
        preHead.next = head;
        
        // pre 是一个前驱结点，指向第一个需要改变的结点的前驱结点
        ListNode *pre = &preHead;
        while(--m) pre = pre->next;
        // first 指向第一个需要改变的结点
        ListNode *first = pre->next;
        while(n--){
        	ListNode *p = first->next;
        	first->next = p->next;
        	p->next = pre->next;
        	pre->next = p;
        }
        return preHead.next;
    }
};
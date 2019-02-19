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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        // odd 负责连接奇数结点，even 负责连接偶数结点
        ListNode *odd = head, *even = head->next;
        // evenHead 用来将奇数结点与偶数结点相连
        ListNode *evenHead = head->next;
        while(even != NULL && even->next != NULL){
        	odd->next = odd->next->next;
        	even->next = even->next->next;
        	odd = odd->next;
        	even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
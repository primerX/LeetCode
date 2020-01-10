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
        if(head == NULL){
            return head;
        }
        ListNode *cur = head;
        while(cur != NULL){
            n--;
            cur = cur->next;
        }
        if(n == 0){         // 链表长度刚好等于 n
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
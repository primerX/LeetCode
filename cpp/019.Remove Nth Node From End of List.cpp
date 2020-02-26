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

// 使用一趟扫描实现
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *p = dummyNode;
        ListNode *q = dummyNode;

        for(int i = 0; i <= n; i++){
            q = q->next;
        }

        while(q){
            p = p->next;
            q = q->next;
        }
        // 注意销毁结点，良好的编码习惯
        ListNode* temp = p->next;
        p->next = temp->next;
        delete temp;

        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        
        return newHead;
    }
};
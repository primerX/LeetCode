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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);       //创建头结点
        ListNode* p = head;
        int carry = 0;      //初始化进位为 0
        while(l1 != NULL && l2 != NULL){        //链表 l1 和 l2 都不为空
            p->next = new ListNode((carry + l1->val + l2->val) % 10);
            carry = (carry + l1->val + l2->val) / 10;   //更新进位
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){      //链表 L1 不为空时
            p->next = new ListNode((carry + l1->val) % 10);
            carry = (carry + l1->val) / 10;     //更新进位
            p = p->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            p->next = new ListNode((carry + l2->val) % 10);
            carry = (carry + l2->val) / 10;
            p = p->next;
            l2 = l2->next;
        }
        if(carry != 0){
            p->next = new ListNode(1);
        }
        return head->next;      //返回第一个结点
    }
};
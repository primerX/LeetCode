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
        ListNode *head = new ListNode(0);	// 创建头结点
        ListNode *p = head;
        int carry = 0;		//初始化进位为 0
        while(l1!=NULL && l2!=NULL){
        	p->next = new ListNode((l1->val + l2->val + carry)%10);
        	carry = (l1->val + l2->val + carry)/10;	//更新进位
        	p = p->next;
        	l1 = l1->next;
        	l2 = l2->next;
        }
        while(l1!=NULL){	// 链表L1 中数的位数大于链表L2 中数的位数
        	p->next = new ListNode((l1->val + carry)%10);
        	carry = (l1->val + carry)/10;
        	p = p->next;
        	l1 = l1->next;
        }
        while(l2!=NULL){
        	p->next = new ListNode((l2->val+carry)%10);
        	carry = (l2->val+carry)/10;
        	p = p->next;
        	l2 = l2->next;
        }
        if(carry != 0){		// 最终，如果进位不为 0，在首位添加加 1
        	p->next = new ListNode(1);
        }
        return head->next;
    }
};
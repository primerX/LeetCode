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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;

        // 链表的长度
        int len = 1;
        ListNode *p = head;
        while(p->next){
        	p = p->next;
        	len++;
        }
        // 将链表的头尾连接起来
        p->next = head;
        // 找到左边的位置
        k = len - k%len;

        // 找到需要更改的位置
        for(int i = 0; i < k; i++){
        	p = p->next;
        }

        head = p->next;
        p->next = NULL;
        return head;
    }
};
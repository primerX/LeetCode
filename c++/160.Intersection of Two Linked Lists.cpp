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
	// 获取链表长度
	int getLength(ListNode *head){
		int len = 0;
		while(head){
			head = head->next;
			len++;
		}
		return len;
	}

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	// 获取两个链表的长度
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        if(lenA < lenB) swap(headA, headB);

        // 让两个链表长度相等
        for(int i = 0; i < abs(lenA - lenB); i++){
        	headA = headA->next;
        }
        // 遍历两个链表，检查这两个链表结点是否相同
        while(headA != headB){
        	headA = headA->next;
        	headB = headB->next;
        }
        return headA;
    }
};
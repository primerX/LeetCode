/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 使用递归方式求解
        if(l1 == null && l2 == null){
        	return null;
        }else if (l1 == null || l2 == null){
        	return l1 != null ? l1 : l2;
        }else{
        	ListNode l3;
        	// 不产生进位
        	if(l1.val + l2.val < 10){
        		l3 = new ListNode(l1.val + l2.val);
        		l3.next = addTwoNumbers(l1.next, l2.next);
        	}else{	// 产生进位
        		l3 = new ListNode(l1.val + l2.val - 10);
        		l3.next = addTwoNumbers(l1.next, addTwoNumbers(l2.next, new ListNode(1)));
        	}

        	return l3;
        }
    }
}
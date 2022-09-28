/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode root = new ListNode();
        root.next = head;
        head = root;
        
        for(int i = 0; i < n; i++){
            head = head.next;
        }
        
        ListNode temp = root;
        while(head.next != null){
            temp = temp.next;
            head = head.next;
        }
        
        temp.next = temp.next.next;
        
        return root.next;
    }
}
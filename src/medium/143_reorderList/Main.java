import java.util.ArrayList;
import java.util.List;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public void reorderList(ListNode head) {
        ListNode curr = head;
        List<ListNode> list = new ArrayList<>();
        while (curr != null) {
            list.add(curr);
            curr = curr.next;
        }
        
        ListNode middle = list.get(list.size() / 2);
        for (int i = 0; i < list.size() / 2; i++) {
            ListNode left = list.get(i);
            ListNode right = list.get(list.size() - i - 1);
            
            ListNode leftNext = left.next;
            left.next = right;
            right.next = leftNext;
        }
        
        middle.next = null;
    }
}

public class Main {
    public static void main(String[] args) {
        ListNode head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));//, new ListNode(5)))));
        Solution sol = new Solution();
        sol.reorderList(head);
        System.out.println("hmm");
    }
}

import java.util.Comparator;
import java.util.PriorityQueue;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) {
            return null;
        }

        PriorityQueue<ListNode> pq = new PriorityQueue<>(new Comparator<ListNode>() {
            public int compare(ListNode l1, ListNode l2) {
                if (l1.val < l2.val) {
                    return -1;
                }

                if (l1.val > l2.val) {
                    return 1;
                }

                return 0;
            }
        });

        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                pq.add(lists[i]);
            }
        }

        if (pq.isEmpty()) {
            return null;
        }

        ListNode head = pq.poll();
        if (head.next != null) {
            pq.add(head.next);
        }

        ListNode curr = head;
        while (!pq.isEmpty()) {
            ListNode smallest = pq.poll();
            ListNode next = smallest.next;
            curr.next = smallest;
            curr = curr.next;

            if (next != null) {
                pq.add(next);
            }
        }

        return head;
    }
}

public class Main {
    public static void main(String[] args) {
        ListNode l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
        ListNode l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        ListNode l3 = new ListNode(2, new ListNode(6));

        Solution sol = new Solution();

        ListNode head = sol.mergeKLists(new ListNode[] { l1, l2, l3 });
        System.out.println("boo");

    }
}

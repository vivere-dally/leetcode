#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode *curr = head;
        while (curr != nullptr) {
            while (curr->next != nullptr && curr->next->val == val) {
                ListNode *next = curr->next;
                curr->next = next->next;
                delete next;
            }

            curr = curr->next;
        }

        return head;
    }
};

int main() {
    Solution s;
    ListNode *root = new ListNode(
        1,
        new ListNode(
            2,
            new ListNode(
                6,
                new ListNode(
                    3,
                    new ListNode(
                        4,
                        new ListNode(
                            5,
                            new ListNode(6)))))));

    cout << s.removeElements(root, 6) << endl;
    return 0;
}

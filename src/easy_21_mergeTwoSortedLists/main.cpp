#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void print()
    {
        ListNode *root = this;
        while (root != nullptr)
        {
            cout << root->val << " ";
            root = root->next;
        }

        cout << endl;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        else if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *root = (l1->val <= l2->val) ? l1 : l2;
        ListNode *curr = root;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                ListNode *next = l1->next;
                curr->next = l1;
                l1 = next;
            }
            else
            {
                ListNode *next = l2->next;
                curr->next = l2;
                l2 = next;
            }

            curr = curr->next;
        }

        if (l1 == nullptr)
        {
            curr->next = l2;
        }
        else
        {
            curr->next = l1;
        }

        return root;
    }
};

int main()
{
    Solution s;

    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    for (int i = 5; i >= 0; i--)
    {
        l1 = new ListNode(i, l1);
        l2 = new ListNode(i * 3, l2);
    }

    l1->print();
    l2->print();
    s.mergeTwoLists(l1, l2)->print();
    s.mergeTwoLists(nullptr, new ListNode())->print();
    s.mergeTwoLists(new ListNode(), nullptr)->print();
    s.mergeTwoLists(new ListNode(3), new ListNode(4))->print();
    return 0;
}

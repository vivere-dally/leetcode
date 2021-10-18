#include <iostream>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> pointers;
        for (ListNode *node = head; node != nullptr; node = node->next)
        {
            if (pointers.find(node) != pointers.end())
            {
                return true;
            }

            pointers.emplace(node);
        }

        return false;
    }
};

class Solution2
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr && head->next == nullptr)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next->next;
        while (slow != nullptr || fast != nullptr)
        {
            if (slow == fast)
            {
                return true;
            }

            slow = slow->next;
            for (int i = 0; i < 2; i++)
            {
                if (fast->next == nullptr)
                {
                    return false;
                }

                fast = fast->next;
            }
        }

        return false;
    }
};

int main()
{
    Solution2 s;

    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(2);
    a->next = b;
    ListNode *c = new ListNode(0);
    b->next = c;
    ListNode *d = new ListNode(-4);
    c->next = d;
    d->next = b;

    cout << s.hasCycle(a) << endl;
    return 0;
}

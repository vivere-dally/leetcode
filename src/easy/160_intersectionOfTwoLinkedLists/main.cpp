#include <iostream>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        set<ListNode*> saw;
        while (headA != NULL && headB != NULL)
        {
            auto result = saw.find(headA);
            if (result != saw.end())
            {
                return *result; 
            }

            saw.insert(headA);
            headA = headA->next;

            result = saw.find(headB);
            if (result != saw.end())
            {
                return *result;
            }

            saw.insert(headB);
            headB = headB->next;
        }

        return NULL;
    }
};

int main()
{
    Solution s;

    ListNode *headA = new ListNode(1, new ListNode(3, new ListNode(4, new ListNode(5))));
    ListNode *headB = new ListNode(100, headA->next);

    cout << s.getIntersectionNode(headA, headB)->val << endl;
    return 0;
}

#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *reverseLinkedList(ListNode *l)
    {
        ListNode *prev = nullptr, *next = nullptr, *current = l;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = this->reverseLinkedList(l1);
        l2 = this->reverseLinkedList(l2);
        ListNode *sum = new ListNode(), *root = sum, *prev = nullptr;
        while (l1 != nullptr && l2 != nullptr)
        {
            // Add
            sum->val += l1->val + l2->val;
            int rest = sum->val / 10;
            sum->val %= 10;

            sum->next = new ListNode(rest);
            prev = sum;
            sum = sum->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr)
        {
            sum->val += l1->val;
            int rest = sum->val / 10;
            sum->val %= 10;
            sum->next = new ListNode(rest);
            prev = sum;
            sum = sum->next;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            sum->val += l2->val;
            int rest = sum->val / 10;
            sum->val %= 10;
            sum->next = new ListNode(rest);
            prev = sum;
            sum = sum->next;
            l2 = l2->next;
        }

        if (prev->next->val == 0) {
            prev->next = nullptr;
        }

        return root;
    }
};

ListNode* buildList(std::vector<int> nums)
{
    ListNode *root = nullptr, *current = new ListNode(nums[0]);
    root = current;
    for (int i = 1; i < nums.size(); i++)
    {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return root;
}

int main()
{
    Solution s;
    std::vector<int> v(26);
    std::cout << v[5];
    ListNode* result = s.addTwoNumbers(buildList({9,9,9,9,9,9,9}), buildList({9,9,9,9}));
    std::cout<<result->val;
}

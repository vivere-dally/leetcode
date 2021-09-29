#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *sortedArrayToBSTRec(vector<int> &nums, int l, int r)
    {
        if (l >= r)
        {
            return nullptr;
        }

        int m = (l + r) / 2;
        return new TreeNode(nums[m],
                            this->sortedArrayToBSTRec(nums, l, m),
                            this->sortedArrayToBSTRec(nums, m + 1, r));
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return this->sortedArrayToBSTRec(nums, 0, nums.size());
    }
};

int main()
{
    Solution s;
    vector<int> v{-10, -3, 0, 5, 9};
    auto x = s.sortedArrayToBST(v);
    return 0;
}

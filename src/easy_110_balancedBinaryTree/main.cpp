#include <iostream>
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
    bool found = false;
    int isBalancedRec(TreeNode *root)
    {
        if (root == nullptr || found)
        {
            return 0;
        }

        int l = isBalancedRec(root->left);
        int r = isBalancedRec(root->right);
        if (abs(l - r) > 1)
        {
            found = true;
        };

        return max(l, r) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        this->found = false;
        this->isBalancedRec(root);
        return !found;
    }
};

int main()
{
    TreeNode *t1 = new TreeNode(
        3,
        new TreeNode(9),
        new TreeNode(
            20,
            new TreeNode(15),
            new TreeNode(7)));

    TreeNode *t2 = new TreeNode(
        1,
        new TreeNode(2),
        new TreeNode(
            2,
            new TreeNode(3),
            new TreeNode(
                3,
                new TreeNode(4),
                new TreeNode(4))));

    Solution s;
    cout << s.isBalanced(t1) << endl;
    cout << s.isBalanced(t2);
    return 0;
}

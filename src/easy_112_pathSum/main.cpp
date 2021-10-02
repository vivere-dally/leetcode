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
private:
    bool found = false;

    void hasPathSumRec(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }

        if (found || (root->val == targetSum && root->left == nullptr && root->right == nullptr))
        {
            found = true;
            return;
        }

        targetSum -= root->val;
        hasPathSumRec(root->left, targetSum);
        if (found)
        {
            return;
        }

        hasPathSumRec(root->right, targetSum);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        this->found = false;
        this->hasPathSumRec(root, targetSum);
        return this->found;
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
    cout << s.hasPathSum(t1, 12) << endl;
    cout << s.hasPathSum(t1, 38) << endl;
    cout << s.hasPathSum(t1, 3) << endl;
    cout << s.hasPathSum(t2, 3) << endl;
    cout << s.hasPathSum(t2, 6) << endl;
    cout << s.hasPathSum(t2, 10) << endl;
    return 0;
}

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
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (l != 0 && r != 0)
        {
            return min(l, r) + 1;
        }

        return max(l, r) + 1;
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
    cout << s.minDepth(t1) << endl;
    cout << s.minDepth(t2) << endl;
    cout << s.minDepth(new TreeNode()) << endl;
    cout << s.minDepth(nullptr) << endl;
    cout << s.minDepth(new TreeNode(1, new TreeNode(), nullptr)) << endl;
    return 0;
}

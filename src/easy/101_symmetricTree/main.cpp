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
    bool isSymmetricRec(TreeNode *l, TreeNode *r)
    {
        if (l == nullptr && r == nullptr)
        {
            return true;
        }
        else if ((l == nullptr && r != nullptr) ||
                 (l != nullptr && r == nullptr))
        {
            return false;
        }

        if (l->val == r->val)
        {
            bool r1 = this->isSymmetricRec(l->left, r->right);
            bool r2 = this->isSymmetricRec(l->right, r->left);
            return r1 & r2;
        }

        return false;
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        return this->isSymmetricRec(root->left, root->right);
    }
};

int main()
{
    Solution s;
    return 0;
}

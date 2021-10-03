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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        {
            return false;
        }

        if (p->val == q->val)
        {
            bool l = this->isSameTree(p->left, q->left);
            bool r = this->isSameTree(p->right, q->right);
            return l & r;
        }

        return false;
    }
};

int main()
{
    Solution s;

    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->right = new TreeNode(2);

    cout << s.isSameTree(p, p) << endl;
    cout << s.isSameTree(p, q) << endl;
    cout << s.isSameTree(q, q) << endl;

    return 0;
}

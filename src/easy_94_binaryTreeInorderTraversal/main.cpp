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
    void inorderTraversalRec(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left != nullptr)
        {
            inorderTraversalRec(root->left, v);
        }

        v.push_back(root->val);
        if (root->right != nullptr)
        {
            inorderTraversalRec(root->right, v);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        this->inorderTraversalRec(root, v);
        return v;
    }
};

int main()
{
    Solution s;

    TreeNode *r = new TreeNode(1);
    r->left = nullptr;
    r->right = new TreeNode(2);
    r->right->left = new TreeNode(3);

    auto v = s.inorderTraversal(r);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    void postorderTraversalRec(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
        {
            return;
        }

        this->postorderTraversalRec(root->left, v);
        this->postorderTraversalRec(root->right, v);
        v.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        this->postorderTraversalRec(root, v);
        return v;
    }
};

class Solution2
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> v;
        stack<TreeNode *> nodes({root});

        while (!nodes.empty())
        {
            TreeNode *current = nodes.top();
            nodes.pop();
            while (current->left != nullptr)
            {
                nodes.push(current);
                TreeNode *left = current->left;
                current->left = nullptr;
                current = left;
            }

            if (current->right != nullptr)
            {
                nodes.push(current);
                TreeNode *right = current->right;
                current->right = nullptr;
                nodes.push(right);
            }
            else
            {
                v.push_back(current->val);
            }
        }

        return v;
    }
};

int main()
{
    Solution2 s;

    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(4);
    r->right = new TreeNode(3);
    r->left->right = new TreeNode(17);
    r->left->left = new TreeNode(2);

    auto v = s.postorderTraversal(r);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}

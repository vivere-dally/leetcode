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
    void preorderTraversalRec(TreeNode *root, vector<int> &v)
    {
        if (root == nullptr)
        {
            return;
        }

        v.push_back(root->val);
        if (root->left != nullptr)
        {
            preorderTraversalRec(root->left, v);
        }

        if (root->right != nullptr)
        {
            preorderTraversalRec(root->right, v);
        }
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        this->preorderTraversalRec(root, v);
        return v;
    }
};

class Solution2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        queue<TreeNode *> lefts;
        stack<TreeNode *> rights;
        lefts.push(root);

        while (!lefts.empty() || !rights.empty())
        {
            TreeNode *current;
            if (lefts.empty())
            {
                current = rights.top();
                rights.pop();
            }
            else
            {
                current = lefts.front();
                lefts.pop();
            }

            if (current == nullptr)
            {
                continue;
            }

            v.push_back(current->val);
            lefts.push(current->left);
            rights.push(current->right);
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
    r->left->left = new TreeNode(2);

    auto v = s.preorderTraversal(r);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}

#include <iostream>
using namespace std;

class MinStack
{
private:
    struct Node
    {
        int val;
        Node *next;
        Node() : val(0), next(nullptr) {}
        Node(int x) : val(x), next(nullptr) {}
        Node(int x, Node *next) : val(x), next(next) {}
    };

    Node *root = nullptr;
    int min = INT_MAX;

    void inner_pop()
    {
        Node *tmp = root;
        root = root->next;
        delete tmp;
    }

public:
    void push(int val)
    {
        if (min >= val)
        {
            root = new Node(min, root);
            min = val;
        }

        root = new Node(val, root);
    }

    void pop()
    {
        if (min == root->val)
        {
            this->inner_pop();
            min = root->val;
        }

        this->inner_pop();
    }

    int top()
    {
        return root->val;
    }

    int getMin()
    {
        return min;
    }
};

int main()
{
    MinStack *ms = new MinStack();
    ms->push(1);
    ms->push(2);
    ms->push(3);
    ms->push(4);
    cout << ms->getMin() << endl;
    ms->pop();
    cout << ms->top() << endl;
    cout << ms->getMin() << endl;

    return 0;
}

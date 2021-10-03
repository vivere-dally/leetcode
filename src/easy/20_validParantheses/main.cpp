#include <iostream>
#include <stack>
using namespace std;

class Solution
{
private:
    char isClosing(char par)
    {
        return (par == ')' || par == ']' || par == '}');
    }

    char getOpposite(char par)
    {
        if (par == ')')
        {
            return '(';
        }

        if (par == ']')
        {
            return '[';
        }

        return '{';
    }

public:
    bool isValid(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            bool isClosing = this->isClosing(s[i]);
            if (st.empty() && isClosing)
            {
                return false;
            }
            else if (!st.empty() && isClosing)
            {
                if (st.top() != this->getOpposite(s[i]))
                {
                    return false;
                }

                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
    cout << s.isValid("((([[[{{{}}}]]])))") << endl;
    cout << s.isValid("[") << endl;
    return 0;
}

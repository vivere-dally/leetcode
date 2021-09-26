#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }

        if (needle.empty())
        {
            return 0;
        }

        int i = 0;
        while (i < haystack.size())
        {
            // possible solution
            if (haystack[i] == needle[0])
            {
                bool sol = true;
                int j = 0, k = i;
                while (k < haystack.size() && j < needle.size())
                {
                    if (haystack[k++] != needle[j++])
                    {
                        sol = false;
                    }
                }

                if (j == needle.size() && sol)
                {
                    return i;
                }

                i = k - j + 1;
            }
            else
            {
                i++;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.strStr("blabla", "ab") << endl;
    cout << s.strStr("hello", "ll") << endl;
    cout << s.strStr("aaaaaa", "ba") << endl;
    cout << s.strStr("", "") << endl;
    cout << s.strStr("mississippi", "issip") << endl;
    cout << s.strStr("mississippi", "pi") << endl;
    cout << s.strStr("issip", "mississippi") << endl;
    cout << s.strStr("aacaacaab", "aab") << endl;
    return 0;
}

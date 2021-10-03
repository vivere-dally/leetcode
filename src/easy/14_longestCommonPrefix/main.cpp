#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result = strs[0];
        while (result.length())
        {
            bool isPrefix = true;
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i].rfind(result, 0) != 0)
                {
                    isPrefix = false;
                    break;
                }
            }

            if (isPrefix)
            {
                return result;
            }

            result.pop_back();
        }

        return "";
    }
};

int main()
{
    Solution s;
    vector<string> v;
    v.push_back("abcdefg");
    v.push_back("abcdef");
    v.push_back("abcde");
    v.push_back("abcd");
    cout << s.longestCommonPrefix(v) << endl;

    vector<string> v1;
    v1.push_back("aqweqweq");
    v1.push_back("bewqeqw");
    v1.push_back("xaxa");
    v1.push_back("dada");
    cout << s.longestCommonPrefix(v1) << endl;

    vector<string> v2;
    v2.push_back("");
    cout << s.longestCommonPrefix(v2) << endl;

    return 0;
}

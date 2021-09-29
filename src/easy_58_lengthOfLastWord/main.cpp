#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = 0;
        bool encounteredWord = false;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && encounteredWord)
            {
                break;
            }

            if (s[i] != ' ')
            {
                encounteredWord = true;
                count++;
            }
        }

        return count;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    cout << s.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    cout << s.lengthOfLastWord("luffy is still joyboy") << endl;
    return 0;
}

#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        if (s == goal) {
            set<char> chars;
            for (int i = 0; i < s.size(); i++) {
                if (chars.find(s[i]) != chars.end()) {
                    return true;
                }

                chars.insert(s[i]);
            }

            return false;
        }

        int index = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (index == -1) {
                    index = i;
                }
                else {
                    char temp = s[index];
                    s[index] = s[i];
                    s[i] = temp;
                    break;
                }
            }
        }

        return s == goal;
    }
};

int main() {
    Solution s;
    cout << s.buddyStrings("abab", "abab") << endl;
    cout << s.buddyStrings("ab", "ba") << endl;
    cout << s.buddyStrings("ab", "ab") << endl;
    cout << s.buddyStrings("aa", "aa") << endl;
    cout << s.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
    return 0;
}

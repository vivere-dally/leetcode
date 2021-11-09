#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> sm, tm;
        for (size_t i = 0; i < s.length(); i++) {
            auto si = sm.find(s[i]);
            auto ti = tm.find(t[i]);
            if ((si != sm.end() && ti == tm.end()) ||
                (si == sm.end() && ti != tm.end()) ||
                (si != sm.end() && ti != tm.end() && si->second != ti->second)) {
                return false;
            }

            if (si == sm.end()) {
                sm.emplace(s[i], i);
            }

            if (ti == tm.end()) {
                tm.emplace(t[i], i);
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isIsomorphic("paper", "title") << endl;
    cout << s.isIsomorphic("egg", "add") << endl;
    cout << s.isIsomorphic("foo", "bar") << endl;
    cout << s.isIsomorphic("badc", "baba") << endl;
    return 0;
}

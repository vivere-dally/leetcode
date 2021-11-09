#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> sawN;
        while (n > 1) {
            if (sawN.find(n) != sawN.end()) {
                return false;
            }

            sawN.insert(n);
            int newN = 0;
            while (n) {
                short digit = n % 10;
                newN = newN + digit * digit;
                n /= 10;
            }

            n = newN;
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
    return 0;
}

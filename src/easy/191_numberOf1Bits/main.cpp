#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int count;
        // for (count = 0; n; count++) {
        //     n &= n - 1;
        // }

        // return count;
        if (n == 0) return 0;
        if (n>>1<<1 == n) return hammingWeight(n>>1);
        return hammingWeight(n>>1) + 1;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(11) << endl;
    cout << s.hammingWeight(128) << endl;
    cout << s.hammingWeight(4294967293) << endl;
    return 0;
}

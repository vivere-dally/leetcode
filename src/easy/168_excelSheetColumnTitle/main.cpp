#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        stringstream s;
        while (columnNumber) {
            columnNumber--;
            int mod = columnNumber % 26;
            char c = 65 + columnNumber % 26;
            columnNumber /= 26;

            s << c;
        }

        string r_result(s.str());
        string result(r_result.rbegin(), r_result.rend());
        return result;
    }
};

int main() {
    Solution s;
    cout << s.convertToTitle(52) << endl;
    cout << s.convertToTitle(1) << endl;
    cout << s.convertToTitle(2) << endl;
    cout << s.convertToTitle(3) << endl;
    cout << s.convertToTitle(26) << endl;
    cout << s.convertToTitle(27) << endl;
    cout << s.convertToTitle(28) << endl;
    cout << s.convertToTitle(701) << endl;
    cout << s.convertToTitle(2147483647) << endl;
    return 0;
}

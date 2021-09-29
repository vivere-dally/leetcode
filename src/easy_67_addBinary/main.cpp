#include <iostream>
using namespace std;

#define ZERO 48

class Solution
{
public:
    // 0 -> 48
    // 1 -> 49
    string addBinary(string a, string b)
    {
        char carry = 0;
        string *s = (a.length() >= b.length()) ? &a : &b;
        int i = a.size(), j = b.size(), k = s->size();
        while (i > 0 && j > 0)
        {
            char sum = a[--i] % ZERO + b[--j] % ZERO + carry;
            (*s)[--k] = sum % 2 + ZERO;
            carry = sum / 2;
        }

        if (carry == 0)
        {
            return *s;
        }

        while (k > 0 && carry == 1)
        {
            char sum = (*s)[--k] % ZERO + carry;
            (*s)[k] = sum % 2 + ZERO;
            carry = sum / 2;
        }

        if (carry == 1)
        {
            s->insert(s->begin(), ZERO + 1);
        }

        return *s;
    }
};

int main()
{
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    cout << s.addBinary("1010", "1011") << endl;
    cout << s.addBinary("0", "0") << endl;
    cout << s.addBinary("11111111111", "11111111111") << endl;
    return 0;
}

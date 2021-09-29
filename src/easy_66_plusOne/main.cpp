#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 && carry; i--)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry == 1)
        {
            vector<int> v(digits.size() + 1);
            v[0] = 1;
            return v;
        }

        return digits;
    }
};

void print(vector<int> &digits)
{
    Solution s;
    auto result = s.plusOne(digits);
    for (auto &&i : result)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v1{1, 2, 3}, v2{4, 3, 2, 1}, v3{0}, v4{9}, v5, v6{9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
    return 0;
}

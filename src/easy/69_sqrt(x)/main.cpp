#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int start = 0, end = x, y;
        while (start <= end)
        {
            int m = (start + end) / 2;
            if (m == 0 || m <= x / m)
            {
                start = m + 1;
                y = m;
            }
            else
            {
                end = m - 1;
            }
        }

        return y;
    }
};

int main()
{
    Solution s;
    cout << s.mySqrt(16) << endl;
    cout << s.mySqrt(4) << endl;
    cout << s.mySqrt(8) << endl;
    return 0;
}

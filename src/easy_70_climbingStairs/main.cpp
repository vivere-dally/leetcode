#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev1 = 1;
        long prev2 = 1;
        for (int i = 0; i < n; i++)
        {
            int temp = prev2;
            prev2 += prev1;
            prev1 = temp;
        }

        return prev1;
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(2) << endl;
    cout << s.climbStairs(3) << endl;
    cout << s.climbStairs(4) << endl;
    cout << s.climbStairs(5) << endl;
    cout << s.climbStairs(45) << endl;
    return 0;
}

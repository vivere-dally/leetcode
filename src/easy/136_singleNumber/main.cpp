#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> a{2, 2, 1}, b{4, 1, 2, 1, 2}, c{1};

    cout << s.singleNumber(a) << endl;
    cout << s.singleNumber(b) << endl;
    cout << s.singleNumber(c) << endl;
    return 0;
}

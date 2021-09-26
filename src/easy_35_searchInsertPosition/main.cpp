#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = (r + l) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return l;
    }
};

int main()
{
    Solution s;

    vector<int> v = {1, 3, 5, 6};
    cout << s.searchInsert(v, 5) << endl;

    vector<int> v1 = {1, 3, 5, 6};
    cout << s.searchInsert(v1, 2) << endl;

    vector<int> v2 = {1, 3, 5, 6};
    cout << s.searchInsert(v2, 7) << endl;

    vector<int> v3 = {1, 3, 5, 6};
    cout << s.searchInsert(v3, 0) << endl;

    vector<int> v4 = {1};
    cout << s.searchInsert(v4, 0) << endl;

    return 0;
}

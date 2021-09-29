#include <iostream>
#include <vector>
using namespace std;

// Kadane's Algorithm O(n)
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_sum = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (sum + nums[i] < nums[i])
            {
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }

            if (sum > max_sum)
            {
                max_sum = sum;
            }
        }

        return max_sum;
    }
};

// Divide and conquer
class Solution2
{
private:
    int dnq(vector<int> &nums, int l, int r)
    {
        // if (r - l == 1)
        // {
        //     return make_pair(nums[l], 0);
        // }

        // int m = (l + r) / 2;
        // auto l_sum = dnq(nums, l, m);

        // auto r_sum = dnq(nums, m, r);

        // int sum = l_sum + r_sum;
        // return max(max(l_sum, r_sum), sum);
    }

public:
    int maxSubArray(vector<int> &nums)
    {
        return dnq(nums, 0, nums.size());
    }
};

int main()
{
    Solution s;
    Solution2 s2;
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(v) << endl;
    cout << "s2: " << s2.maxSubArray(v) << endl;
    vector<int> v1{1};
    cout << s.maxSubArray(v1) << endl;
    cout << "s2: " << s2.maxSubArray(v1) << endl;
    vector<int> v2{5, 4, -1, 7, 8};
    cout << s.maxSubArray(v2) << endl;
    cout << "s2: " << s2.maxSubArray(v2) << endl;
    return 0;
}

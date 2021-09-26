#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int size = nums.size(), prev = nums[0], i = 1, j = 1;
        while (j < nums.size())
        {
            while (j < nums.size() && prev == nums[j])
            {
                size--;
                j++;
            }

            if (j < nums.size())
            {
                nums[i++] = nums[j];
                prev = nums[j++];
            }
        }

        return size;
    }
};

void solve(vector<int> &nums)
{
    Solution s;
    int c = s.removeDuplicates(nums);
    cout << c << endl;
    for (int i = 0; i < c; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v1{0, 0, 1, 1, 2, 2};
    solve(v1);

    vector<int> v2{1, 1, 2};
    solve(v2);

    vector<int> v3{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    solve(v3);

    return 0;
}

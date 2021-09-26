#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int size = nums.size(), i = 0, j = 0;

        // Navigate i to val
        while (i < nums.size() && nums[i] != val)
        {
            i++;
        }

        j = i;
        while (j < nums.size())
        {
            while (j < nums.size() && val == nums[j])
            {
                j++;
                size--;
            }

            if (j < nums.size())
            {
                nums[i++] = nums[j++];
            }
        }

        return size;
    }
};

void print(vector<int> &nums, int val)
{
    Solution s;
    int c = s.removeElement(nums, val);
    cout << c << endl;
    for (int i = 0; i < c; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v{3, 2, 2, 3};
    print(v, 3);

    vector<int> v1{0, 1, 2, 2, 3, 0, 4, 2};
    print(v1, 2);

    vector<int> v2{1, 1, 2};
    print(v2, 1);

    vector<int> v3{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    print(v3, 1);

    vector<int> v4{0, 0};
    print(v4, 0);

    return 0;
}

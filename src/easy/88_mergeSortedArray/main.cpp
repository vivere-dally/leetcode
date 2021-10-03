#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (0 <= i && 0 <= j)
        {
            int temp;
            if (nums1[i] >= nums2[j])
            {
                temp = nums1[i--];
            }
            else
            {
                temp = nums2[j--];
            }

            nums1[k--] = temp;
        }

        while (0 <= i)
        {
            nums1[k--] = nums1[i--];
        }

        while (0 <= j)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

void print(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    Solution s;
    s.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> v1{1, 2, 3, 0, 0, 0}, v2{2, 5, 6};
    print(v1, 3, v2, 3);

    vector<int> v3{1}, v4;
    print(v3, 1, v4, 0);

    vector<int> v5{0}, v6{1};
    print(v5, 0, v6, 1);

    vector<int> v7{4, 5, 6, 0, 0, 0}, v8{1, 2, 3};
    print(v7, 3, v8, 3);

    vector<int> v9{1, 10, 20, 60, 0, 0, 0}, v10{2, 3, 4};
    print(v9, 4, v10, 3);

    return 0;
}

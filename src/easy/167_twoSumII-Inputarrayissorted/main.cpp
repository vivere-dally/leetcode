#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); i++)
        {
            auto q = m.find(numbers[i]);
            if (q != m.end())
            {
                return {(*q).second + 1, i + 1};
            }

            m.emplace(target - numbers[i], i);
        }

        return {-1, -1};
    }
};

int main()
{
    Solution s;

    vector<int> v = {2, 7, 11, 15};
    auto result = s.twoSum(v, 9);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    
    return 0;
}

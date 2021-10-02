#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    map<int, int> complements;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] <= target)
      {
        int complement = target - nums[i];
        if (complements.find(complement) != complements.end())
        {
          return {complements[complement], i};
        }
        else
        {
          complements[nums[i]] = i;
        }
      }
    }
    
    return {};
  }
};

int main()
{
  Solution s;
  vector<int> numbers{-3, 4, 3, 90};
  vector<int> sol = s.twoSum(numbers, 0);
  for (auto &&i : sol)
  {
    cout << i;
  }
  
}
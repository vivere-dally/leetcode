#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pas{vector<int>{1}};
        if (numRows >= 2)
        {
            pas.push_back(vector<int>{1, 1});
        }

        for (int i = 2; i < numRows; i++)
        {
            vector<int> row(i + 1);
            row[0] = 1;
            for (int j = 1; j < i; j++)
            {
                row[j] = pas[i - 1][j - 1] + pas[i - 1][j];
            }

            row[row.size() - 1] = 1;
            pas.push_back(row);
        }

        return pas;
    }
};

int main()
{
    Solution s;
    auto v1 = s.generate(1);
    auto v2 = s.generate(5);
    auto v3 = s.generate(30);
    return 0;
}

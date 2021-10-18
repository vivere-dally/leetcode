#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }

        int max_profit = 0;
        int bought = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int profit = prices[i] - prices[bought];
            if (profit > max_profit)
            {
                max_profit = profit;
            }
            else if (prices[i] < prices[bought])
            {
                bought = i;
            }
        }

        if (max_profit < 0)
        {
            return 0;
        }

        return max_profit;
    }
};

int main()
{
    Solution s;
    vector<int> v1{7, 1, 5, 3, 6, 4}, v2{7, 6, 4, 3, 1};

    cout << s.maxProfit(v1) << endl;
    cout << s.maxProfit(v2) << endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
private:
  struct compare
  {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
      if (a.second == b.second)
      {
        return a.first < b.first;
      }

      return a.second < b.second;
    }
  };

public:
  vector<int>
  kScores(vector<int> &numbers, int k)
  {
    unordered_map<int, int> map;
    for (size_t i = 0; i < numbers.size(); i++)
    {
      map[numbers[i]]++;
    }

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, compare>
        pq(map.begin(), map.end());

    if (pq.size() < k)
    {
      return {};
    }

    vector<int> result(k);
    for (int i = 0; i < k; i++)
    {
      result[i] = pq.top().first;
      pq.pop();
    }

    return result;
  }
};

int main()
{
  Solution s;
  vector<int> v{6, 5, 2, 6, 6, 2, 1, 7, 3, 3, 3};
  int k = 3;

  vector<int> result = s.kScores(v, k);
  for (int i = 0; i < k; i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}

# kScores

Given a list of n natural numbers ranging between 1 and 1,000,000,000, find the most popular k scores in the descending order of their frequency.

Input
    n = 11,
    k = 3,
    numbers = [6, 5, 2, 6, 6, 2, 1, 7, 3, 3, 3]

Output: [6, 3, 2]

## Notes

The requirement is a bit incomplete:

- What happens when two records have the same frequency?

A solution would be to sort either by the biggest or smallest number. For example, we could update the `comparer` structure as follows:

```cpp
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
```

- What happens when `n < k`?

In this case we could either return an empty array, or the `n` numbers that we got in the array.

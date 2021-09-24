#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
  int reverse(int x)
  {
    short sign = x < 0 ? -1 : 1;
    int lim = INT_MAX / 10;
    int result = x % 10 * sign;

    x = x / 10 * sign;
    while (x)
    {
      if (lim < result)
      {
        return 0;
      }
      else if (lim == result && 1 < x)
      {
        return 0;
      }

      result = result * 10 + x % 10;
      x /= 10;
    }

    return sign * result;
  }
};

int main()
{
  Solution s;
  cout << s.reverse(1463847412) << endl;
  cout << s.reverse(12345678) << endl;
  cout << s.reverse(-12345678) << endl;
  cout << s.reverse(INT_MAX) << endl;
  cout << s.reverse(INT_MIN) << endl;
  return 0;
}

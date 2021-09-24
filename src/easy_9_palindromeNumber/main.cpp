#include <iostream>
using namespace std;

class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
    {
      return false;
    }

    if (0 <= x && x <= 9)
    {
      return true;
    }

    if (x % 10 == 0)
    {
      return false;
    }

    int y = 0;
    while (x > y)
    {
      y = y * 10 + x % 10;
      x /= 10;
      if (x == y || x / 10 == y)
      {
        return true;
      }
    }

    return false;
  }
};

int main()
{
  Solution s;
  cout << s.isPalindrome(123) << endl;
  cout << s.isPalindrome(2222) << endl;
  cout << s.isPalindrome(131) << endl;
  cout << s.isPalindrome(-111) << endl;
  cout << s.isPalindrome(10) << endl;
  return 0;
}

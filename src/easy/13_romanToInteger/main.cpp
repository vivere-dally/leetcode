#include <iostream>
#include <map>
using namespace std;

class Solution
{
private:
  map<char, int> map;

public:
  Solution()
  {
    map.emplace('I', 1);
    map.emplace('V', 5);
    map.emplace('X', 10);
    map.emplace('L', 50);
    map.emplace('C', 100);
    map.emplace('D', 500);
    map.emplace('M', 1000);
  }

  int romanToInt(string s)
  {
    int number = 0, i = 0;
    while (i < s.length())
    {
      if (i + 1 < s.length() && canSubtract(s[i], s[i + 1]))
      {
        number = number + map[s[i + 1]] - map[s[i]];
        i += 2;
      }
      else
      {
        number += map[s[i]];
        i++;
      }
    }

    return number;
  }

  bool canSubtract(char l, char s)
  {
    if ((l == 'I' && (s == 'V' || s == 'X')) ||
        (l == 'X' && (s == 'L' || s == 'C')) ||
        (l == 'C' && (s == 'D' || s == 'M')))
    {
      return true;
    }

    return false;
  }
};

int main()
{
  Solution s;
  cout << s.romanToInt("M") << endl;
  cout << s.romanToInt("III") << endl;
  cout << s.romanToInt("XXX") << endl;
  cout << s.romanToInt("IX") << endl;
  cout << s.romanToInt("XC") << endl;
  cout << s.romanToInt("LVIII") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;
  return 0;
}

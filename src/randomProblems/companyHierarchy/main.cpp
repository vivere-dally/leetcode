#include <iostream>
#include <vector>
using namespace std;

#define SEP ", "
#define UNV "\"Unavailable\""

class Solution
{
private:
  string getName(string str)
  {
    size_t nameEnd = str.find(',');
    return str.substr(1, nameEnd - 1); // str[0] is (
  }

  string getSubHierarchy(string str, size_t startAt)
  {
    int parantheses = 0;
    size_t i = startAt;
    do
    {
      if (str[i] == '(')
      {
        parantheses++;
      }

      if (str[i] == ')')
      {
        parantheses--;
        if (parantheses == 0)
        {
          return str.substr(startAt, i);
        }
      }

      i++;
    } while (i < str.size() && parantheses);

    return {};
  }

public:
  string companyHierarchy(string str)
  {
    if (str.empty())
    {
      return {};
    }

    string name = this->getName(str);
    if (name == UNV)
    {
      return {};
    }

    string subHierarchy1 = this->getSubHierarchy(str, 3 + name.size());
    string subHierarchy2 = this->getSubHierarchy(str, 5 + name.size() + subHierarchy1.size());

    string result1 = this->companyHierarchy(subHierarchy1);
    string result2 = this->companyHierarchy(subHierarchy2);

    string result = "(" + name;
    if (!result1.empty())
    {
      result += SEP + result1;
    }

    if (!result2.empty())
    {
      result += SEP + result2;
    }

    return result + ")";
  }
};

int main()
{
  Solution s;
  string str = "(\"John\", (\"Jasmine\", (\"Jay\"), (\"Unavailable\")), (\"Unavailable\", (\"Jack\", (\"Jeremy\"))), (\"Johanna\"))";

  cout << s.companyHierarchy(str) << endl;
  return 0;
}

#include <iostream>
#include <fstream>
using namespace std;
bool ispalindrome(string str)
{
  int n = str.length();
  for (int i = 0; i < n / 2; i++)
  {
    if (str[i] != str[n - i - 1])
    {
      return false;
    }
  }
  return true;
}
bool iskpalindromic(int num)
{
  
}
int main()
{
  int n = 5;
  int count = 0;
  for (int i = 100; i < 999; i++)
  {
    string str = to_string(i);
    if (ispalindrome(str))
    {
      if (i % 5 == 0)
      {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
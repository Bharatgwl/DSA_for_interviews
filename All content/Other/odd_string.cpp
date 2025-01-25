#include <iostream>
#include <string>
using namespace std;

string odd(string &s)
{
    while (!s.empty() && (s.back() - '0') % 2 == 0)
    {
        s.pop_back(); // Remove the last character
    }

    // If the string becomes empty, return an empty string
    if (s.empty())
    {
        return "";
    }

    return s;
}

int main()
{

    string s = "239537672423884969653287101";

    // cout << odd(s) << endl;
    cout<< s.back() << endl;
}

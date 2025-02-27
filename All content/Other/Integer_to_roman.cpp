#include <bits/stdc++.h>
using namespace std;

string buildRomanDigit(int digit, char single, char five, char ten)
{
    if (digit < 0 || digit > 9)
    {
        throw std::invalid_argument("Digit must be between 0 and 9");
    }

    string result;

    if (digit == 9)
    {
        result += single;
        result += ten;
    }
    else if (digit == 4)
    {
        result += single;
        result += five;
    }
    else
    {
        if (digit >= 5)
        {
            result += five;
            digit -= 5;
        }
        result.append(digit, single);
    }

    return result;
}
string intToRoman(int num)
{
    if (num < 1 || num > INT_MAX)
        throw std::invalid_argument("Roman numerals only support numbers between 1 and +INT_MAX");

    string result;
    int ones = num % 10;
    int tens = num / 10 % 10;
    int huns = num / 100 % 10;
    int thou = num / 1000 % 10;

    result.append(thou, 'M');
    result.append(buildRomanDigit(huns, 'C', 'D', 'M'));
    result.append(buildRomanDigit(tens, 'X', 'L', 'C'));
    result.append(buildRomanDigit(ones, 'I', 'V', 'X'));
    return result;
}

string intToRoman2(int num)
{
    if (num < 1 || num > INT_MAX)
    {
        throw std::invalid_argument("Roman numerals only support numbers between 1 and +INT_MAX");
    }

    map<int, string> roman = {
        {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

    string ans = "";

    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int val : values)
    {
        while (num >= val)
        {
            ans += roman[val];
            num -= val;
        }
    }

    return ans;
}
int main()
{
    int num;
    cin >> num;
    cout << intToRoman(num) << endl;
    cout << intToRoman2(num) << endl;
    return 0;
}

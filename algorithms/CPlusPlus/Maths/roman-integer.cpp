#include <iostream>
#include <unordered_map>

using namespace std;

string intToRoman(int num)
{
    // Define the symbols and their corresponding values
    unordered_map<int, string> symbol_map = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};

    // Build the Roman numeral string
    string roman = "";
    for (auto &[value, symbol] : symbol_map)
    {
        while (num >= value)
        {
            roman += symbol;
            num -= value;
        }
    }
    return roman;
}

int romanToInt(string s)
{
    // Define the symbols and their corresponding values
    unordered_map<char, int> symbol_map = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}};

    // Calculate the integer value
    int value = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0 && symbol_map[s[i]] > symbol_map[s[i - 1]])
        {
            value += symbol_map[s[i]] - 2 * symbol_map[s[i - 1]];
        }
        else
        {
            value += symbol_map[s[i]];
        }
    }
    return value;
}

int main()
{
    int num = 1234;
    string roman = intToRoman(num);
    cout << num << " in Roman numerals is " << roman << endl;

    string s = "MCCXXXIV";
    int value = romanToInt(s);
    cout << s << " in integer value is " << value << endl;

    return 0;
}
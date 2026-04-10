#include <iostream>
#include <string>

using namespace std;

string expandAroundCenter(const string& s, int left, int right)
{
    while (left >= 0 && right < static_cast<int>(s.size()) && s[left] == s[right])
    {
        left--;
        right++;
    }

    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(const string& s)
{
    if (s.empty())
    {
        return "";
    }

    string best = s.substr(0, 1);

    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
        string odd = expandAroundCenter(s, i, i);
        if (odd.size() > best.size())
        {
            best = odd;
        }

        string even = expandAroundCenter(s, i, i + 1);
        if (even.size() > best.size())
        {
            best = even;
        }
    }

    return best;
}

int main()
{
    string s;
    getline(cin, s);

    cout << longestPalindrome(s) << endl;
    return 0;
}

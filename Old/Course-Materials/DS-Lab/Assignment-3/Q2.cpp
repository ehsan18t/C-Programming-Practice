#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

// Collected from stackoverflow
// REF: https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
string ReplaceAll(string str, const string &from, const string &to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

int main()
{
    unordered_map<char, char> data;
    stack<char> brackets;
    string str;
    int i = 0;

    data[')'] = '0';
    data['}'] = '0';
    data[']'] = '0';

    data['('] = ')';
    data['{'] = '}';
    data['['] = ']';

    getline(cin, str);
    // remove all spaces (question sample input contains space)
    str = ReplaceAll(str, " ", "");
    while (str[i] != '\0')
    {
        char ch = str[i];
        if (!brackets.empty() && ch == data[brackets.top()])
            brackets.pop();
        else
            brackets.push(ch);
        i++;
    }
    cout << (brackets.empty() ? "Balanced" : "Not Balanced") << endl;

    return 0;
}
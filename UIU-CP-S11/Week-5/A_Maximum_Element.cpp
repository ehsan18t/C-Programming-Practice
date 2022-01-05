#include <bits/stdc++.h>

// #ifndef ONLINE_JUDGE
// #include "../Debugging Tools/dbg.cpp"
// #include "../Debugging Tools/MemView.cpp"
// #endif

using namespace std;

// collected from stackoverflow
// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
vector<string> split(const string str, const string regex_str)
{
    regex regEx(regex_str);
    vector<string> list(sregex_token_iterator(str.begin(), str.end(), regEx, -1), sregex_token_iterator());
    return list;
}

int s_to_i(string str)
{
    int num;
    stringstream ss;
    ss << str;
    ss >> num;
    return num;
}

int main()
{
    vector<string> strData;
    vector<int> data;
    stack<int> stk;
    stack<int> max;
    int n, tmp;
    string str;
    cin >> n;
    n++;
    while (n--)
    {
        getline(cin, str);
        strData = split(str, " ");
        int cmd = s_to_i(strData.at(0));

        switch (cmd)
        {
        case 1:
            tmp = s_to_i(strData.at(1));
            stk.push(tmp);
            if (max.empty() || tmp >= max.top())
                max.push(tmp);
            break;
        case 2:
            if (max.top() == stk.top())
                max.pop();
            stk.pop();
            break;
        case 3:
            cout << max.top() << endl;
            break;
        }
    }
    return 0;
}
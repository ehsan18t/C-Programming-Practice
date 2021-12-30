#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../../Debugging Tools/dbg.cpp"
#include "../../Debugging Tools/MemView.cpp"
#endif

// collected from stackoverflow
// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string str, const std::string regex_str)
{
    std::regex regexz(regex_str);
    std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1),
                                  std::sregex_token_iterator());
    return list;
}

std::string reverse(std::string str)
{
    char ch;
    int i = 0;
    int len = str.size();
    while (i < str.length() / 2)
    {
        ch = str.at(i);
        str.at(i) = str.at(len - i - 1);
        str.at(len - i - 1) = ch;
        i++;
    }
    return str;
}

int main()
{
    int count = 0;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    std::string line = "";
    while (std::getline(std::cin, line))
    {
        std::string str = "";
        std::vector<std::string> tokens = split(line, " ");
        for (auto s : tokens)
        {
            s = reverse(s);
            str += s + " ";
        }
        str.pop_back();
        std::cout << str << std::endl;
    }
    return 0;
}
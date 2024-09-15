#include <bits/stdc++.h>

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORr(i, n) for (int i = n - 1; i >= 0; i--)
#define FORx(i, x, n) for (int i = x; i < n; i++)
#define FORxr(i, x, n) for (int i = n - 1; i >= x; i--)

// Data Manupulation
#define init(A, V) memset(A, V, sizeof(A))

// Math
#define PI 2 * acos(0.0)
#define INF LLONG_MAX
#define sqr(n) (n * n)

// In/out
#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);

// Data types
#define db double
#define ll long long
#define ull unsigned long long

// Lazy
#define pb push_back
#define lg length()
#define sz size()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// Opt
#define sync                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

/* #region(collapsed) DEBUG */
// Debug Data
// Simple Debugger by UIU CP Club
// I've modified a littile bit for better view

// for 2d array
#define dbgA2(A, n, m)                           \
    {                                            \
        std::cout << "--> " << #A << " =\n    "; \
        for (int i = 0; i < n; i++)              \
        {                                        \
            std::cout << "[" << i << "] -> { ";  \
            for (int j = 0; j < m; j++)          \
            {                                    \
                std::cout << A[i][j] << " ";     \
            }                                    \
            std::cout << "}\n    ";              \
        }                                        \
        std::cout << "\n";                       \
    }

// for array
#define dbgA(A, n)                            \
    {                                         \
        std::cout << "--> " << #A << " = { "; \
        for (int i = 0; i < n; i++)           \
            std::cout << A[i] << " ";         \
        std::cout << "}\n";                   \
    }

// for variables
#define dbg(args...)                                  \
    {                                                 \
        std::string sss(#args);                       \
        sss += ',';                                   \
        std::cout << "--> ";                          \
        debugger::call(sss.begin(), sss.end(), args); \
        std::cout << "\n";                            \
    }

struct debugger
{
    typedef std::string::iterator si;
    static void call(si it, si ed) {}
    template <typename T, typename... aT>
    static void call(si it, si ed, T a, aT... rest)
    {
        std::string b;
        for (; *it != ','; ++it)
            if (*it != ' ')
                b += *it;
        std::cout << b << " = " << a << " ";
        call(++it, ed, rest...);
    }
};

// Debug Memory
// REF: https://stackoverflow.com/questions/38557168/does-vs-code-have-a-memory-viewer-and-or-a-disassembler-for-c-extension
namespace mem
{
    std::string IntToHexa(int num)
    {
        int values[2];
        int rest;
        for (int i = 0; i < 2; i++)
        {
            rest = num % 16;
            if (rest == 0 && num > 0)
            {
                values[i] = num / 16;
            }
            else
            {
                values[i] = num % 16;
            }
            num -= values[i] * std::pow(16, i);

            if (values[i] > 9)
            {
                values[i] = 65 + values[i] - 10;
            }
        }

        std::string output;
        for (int i = 1; i > -1; i--)
        {
            if (values[i] > 10)
            {
                output += char(values[i]);
            }
            else
            {
                output += std::to_string(values[i]);
            }
        }
        return output;
    }

    template <typename POINTER>
    void MemView(POINTER pointer, int length = 10, int lines = 1)
    {
        unsigned char *ptr = (unsigned char *)pointer;
        for (int x = 0; x < lines; x++)
        {
            std::cout << (void *)ptr << "   ";
            for (int i = 0; i < length; i++)
            {
                std::cout << IntToHexa((int)*ptr) << "  ";
                ptr++;
            }
            std::cout << std::endl;
        }
    }
}
/* #endregion */

/* #region(collapsed) FUNCTIONS */
// collected from stackoverflow
// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string str, const std::string regex_str)
{
    std::regex regexz(regex_str);
    std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1), std::sregex_token_iterator());
    return list;
}

/* #endregion */

using namespace std;

// Solution
vector<int> find_ch(string str, char ch)
{
    vector<int> index;
    int i = 0;
    for (char c : str)
    {
        if (c == ch)
            index.pb(i);
        i++;
    }
    return index;
}

void solve()
{
    bool possible = false;
    vector<int> indexs;
    string str;
    char ch;
    cin >> str >> ch;
    indexs = find_ch(str, ch);
    for (int index : indexs)
    {
        if (str.length() % 2 == 1)
        {
            if (index % 2 == 0)
            {
                possible = true;
                break;
            }
        }
    }
    (possible) ? yes : no;
}

int main()
{
    sync;
    int n;
    cin >> n;
    while (n--)
        solve();
    return 0;
}

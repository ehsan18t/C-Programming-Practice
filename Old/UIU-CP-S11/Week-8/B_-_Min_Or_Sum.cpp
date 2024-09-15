#include <bits/stdc++.h>

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORX(i, x, n) for (int i = x; i < n; i++)

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
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;

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

using namespace std;

// Solution
void solve()
{
    int n;
    vector<int> arr;
    cin >> n;

    // input
    FOR(i, n)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    // find
    FOR(i, n)
    {
        FOR(j, n)
        {
        }
    }
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

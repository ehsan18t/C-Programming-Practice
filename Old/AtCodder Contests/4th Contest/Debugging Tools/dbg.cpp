#include <iostream>

// Simple Debugger by UIU CP Club
// I modified a littile bit for better view

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

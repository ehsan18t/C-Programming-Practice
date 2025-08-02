#include <bits/stdc++.h>

// --- Type Aliases ---
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vpii = std::vector<pii>;
#define umap unordered_map

// --- Constants ---
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9 + 7;
constexpr ll LLINF = 1e18;

// Fast I/O
#define fast_io() std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
void setup_io() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

// Common Shortcuts
#define pb push_back
#define mp make_pair
#define F first
#define S second

// Iterator
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORr(i, n) for (int i = n - 1; i >= 0; i--)
#define FORx(i, x, n) for (int i = x; i < n; i++)
#define FORxr(i, x, n) for (int i = n - 1; i >= x; i--)
#define for_map(m) for (auto it : m)

// Lazy Map
#define contains(m, k) (m.find(k) != m.end())
#define K it.first
#define V it.second

// Data Manipulation
#define init(A, V) memset(A, V, sizeof(A))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

// --- Math Shortcuts ---
#define sqr(n) ((n) * (n))
const double PI = acos(-1.0);

// Modular exponentiation (binary exponentiation)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Modular inverse using Fermat's Little Theorem (MOD must be prime)
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// nCr % MOD. Assumes MOD is prime.
// For multiple queries, precomputing factorials is much faster.
long long nCr_mod(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    if (r > n / 2) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = (res * (n - i + 1)) % MOD;
        res = (res * modInverse(i)) % MOD;
    }
    return res;
}

// nPr % MOD.
long long nPr_mod(int n, int r) {
    if (r < 0 || r > n) return 0;
    long long res = 1;
    for (int i = 0; i < r; ++i) {
        res = (res * (n - i)) % MOD;
    }
    return res;
}

// Lazy
#define psb push_back
#define ppb pop_back
#define lg length()
#define sz size()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

// REF: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split(const std::string str, const std::string regex_str) {std::regex regexz(regex_str); std::vector<std::string> list(std::sregex_token_iterator(str.begin(), str.end(), regexz, -1), std::sregex_token_iterator()); return list;}

using namespace std;

// Solution
void solve()
{
    int n;
    cin >> n;
    ll s = 50;
    vll count(s, 0);
    FOR(i, n) {
        int x;
        cin >> x;
        count[x]++;
    }

    vector<vll> v(s+1, vll(n + 1, -LLINF));
    v[0][count[0]] = 0;

    FOR(i, s) {
        FOR(j, n + 1) {
            if (v[i][j] == -LLINF) continue;

            FOR(k, j + 1) {
                if (k > count[i]) continue;

                // cs = current score, as = added score
                ll cs = v[i][j];
                ll as = (ll)(j - k) * i + (ll)(count[i] - k) * i;

                if (v[i + 1][k] < cs + as) {
                    v[i + 1][k] = cs + as;
                }
            }
        }
    }

    //  ms = max score
    ll ms = 0;
    FOR(k, n + 1) {
        if (v[s][k] != -LLINF) {
            ms = max(ms, v[s][k] + (ll)k * s);
        }
    }
    cout << ms << endl;
}

int main()
{
    fast_io();
    setup_io();

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

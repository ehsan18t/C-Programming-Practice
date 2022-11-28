#include <bits/stdc++.h>
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define INF(type) std::numeric_limits<type>::max()

using namespace std;

struct Product
{
    string name;
    double value;
    double weight;
    double valPerUnit;
} typedef Product;

#define inputItems(v)                         \
    for (auto &a : v)                         \
    {                                         \
        cin >> a.name >> a.value >> a.weight; \
        a.valPerUnit = a.value / a.weight;    \
    }

#define printItems(v, sum)                                                          \
    for (auto a : v)                                                                \
    {                                                                               \
        cout << "Taking ";                                                          \
        cout << a.name << ": " << a.weight << " kg " << a.value << " taka" << endl; \
        sum += a.valPerUnit * a.weight;                                             \
    }

#define printRemaining(arr)                                                                                    \
    for (auto a : arr)                                                                                         \
    {                                                                                                          \
        if (a.weight <= 0)                                                                                     \
            continue;                                                                                          \
        cout << "      " << a.name << " " << a.weight << " kg " << a.valPerUnit * a.weight << " taka" << endl; \
    }

#define inputArr(v, n)          \
    for (int i = 0; i < n; i++) \
        cin >> v[i];

vector<Product> select(vector<Product> &arr, double sack)
{
    vector<Product> selected;
    for (auto &p : arr)
    {
        if (p.weight == 0)
            continue;

        if (p.weight <= sack)
        {
            selected.push_back(p);
            sack -= p.weight;
            p.weight = 0;
        }
        else
        {
            p.weight -= sack;
            if (sack > 0)
            {
                selected.push_back({p.name, p.valPerUnit * sack, sack, p.valPerUnit});
                sack = 0;
            }
            break;
        }
    }

    return selected;
}

int main()
{
    in;
    int n, m;
    cin >> n;
    vector<Product> arr(n);

    // input
    inputItems(arr);
    // Sack Input
    cin >> m;
    vector<double> sack(m);
    inputArr(sack, m);

    // sort (descending order) by value per unit
    sort(arr.begin(), arr.end(), [](Product a, Product b)
         { return a.valPerUnit > b.valPerUnit; });

    // find selected items
    vector<vector<Product>> selected;
    for (auto s : sack)
    {
        auto result = select(arr, s);
        if (result.size() > 0)
            selected.push_back(result);
    }

    // print output
    int i;
    for (i = 0; i < selected.size(); i++)
    {
        double sum = 0;
        printItems(selected[i], sum);
        cout << "Thief " << i + 1 << " profit: " << sum << " taka" << endl
             << endl;
    }

    cout << "Total " << i << " thieves stole from the warehouse." << endl;

    // Print Remaining Items (If available)
    if (arr[n - 1].weight > 0)
    {
        cout << "Still following items are left" << endl;
        printRemaining(arr);
    }
    return 0;
}
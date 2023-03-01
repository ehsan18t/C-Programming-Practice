#include <bits/stdc++.h>

using namespace std;

struct Product
{
    string name;
    double weight;
    double price;
    double valPerUnit;
} typedef Product;

#define inputItems(v)                         \
    for (auto &a : v)                         \
    {                                         \
        cin >> a.name >> a.weight >> a.price; \
        a.valPerUnit = a.price / a.weight;    \
    }

#define printItems(v, sum)                                                                  \
    for (auto a : v)                                                                        \
    {                                                                                       \
        cout << a.name << " " << a.weight << " " << a.price << " " << a.valPerUnit << endl; \
        sum += a.price * a.weight;                                                          \
    }

vector<Product> select(vector<Product> arr, double sack)
{
    vector<Product> selected;
    for (auto p : arr)
    {
        if (p.weight <= sack)
        {
            selected.push_back(p);
            sack -= p.weight;
        }
        else
        {
            if (sack > 0)
            {
                selected.push_back({p.name, sack, p.valPerUnit * sack, p.valPerUnit});
                sack = 0;
            }
            break;
        }
    }

    return selected;
}

int main()
{
    int n;
    double sack, price = 0;
    cin >> n >> sack;
    vector<Product> arr(n);

    // input
    inputItems(arr);

    // sort (descending order) by value per unit
    sort(arr.begin(), arr.end(), [](Product a, Product b)
         { return a.valPerUnit > b.valPerUnit; });

    // find selected items
    auto selected = select(arr, sack);
    cout << "Selected: " << endl;

    // print output
    printItems(selected, price);

    cout << "Total Price: " << price << endl;
    return 0;
}
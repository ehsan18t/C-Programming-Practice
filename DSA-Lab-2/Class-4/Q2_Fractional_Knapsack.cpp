#include <bits/stdc++.h>

using namespace std;

struct Product
{
    string name;
    double weight;
    double price;
    double valPerUnit;
} typedef Product;

bool comp(Product a, Product b)
{
    return a.valPerUnit > b.valPerUnit;
}

vector<Product> select(vector<Product> arr, double sack)
{
    vector<Product> selected;
    for (auto p : arr)
    {
        if (p.weight < sack)
        {
            selected.push_back(p);
            sack -= p.weight;
        }
        else
        {
            selected.push_back({p.name, sack, p.valPerUnit * sack, p.valPerUnit});
            sack = 0;
            break;
        }
    }

    return selected;
}

int main()
{
    int n;
    double sack, price = 0;
    cin >> n;
    cin >> sack;
    vector<Product> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].name;
        cin >> arr[i].weight;
        cin >> arr[i].price;
        arr[i].valPerUnit = arr[i].price / arr[i].weight;
    }
    sort(arr.begin(), arr.end(), comp);
    vector<Product> selected = select(arr, sack);
    cout << "Selected: " << endl;
    for (int i = 0; i < selected.size(); i++)
    {
        cout << selected[i].name << " " << selected[i].weight << " " << selected[i].price << endl;
        price += selected[i].price;
    }

    cout << "Total Price: " << price << endl;
    return 0;
}
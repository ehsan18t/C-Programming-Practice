#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> m;
	cin >> n;
	int arr[n];

	//in
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// cal
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] + arr[j] == m)
			{
				cout << arr[i] << " " << arr[j] << endl;
				return 0;
			}
		}
	}
}
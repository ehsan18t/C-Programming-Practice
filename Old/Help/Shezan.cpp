#include <iostream>
using namespace std;

int main()
{
	int n;
	int arr[10][10];
	cin >> n;

	// input
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	// sum of Row
	int sum = 0;
	int row = 0;
	for (int i = 0; i < n; i++)
		sum  += arr[row][i];
	cout << sum << endl;

	// sum /
	sum = 0;
	int j = n - 1;
	for (int i = 0; i < n; i++)
		sum  += arr[i][j--];
	cout << sum << endl;
}
#include <bits/stdc++.h>

int main()
{
	int n;
	int num[1000];
	int sereja = 0;
	int dima = 0;
	int temp;
	int start = 0;
	std::cin >> n;
	int end = n - 1;
	for (int i = 0; i < n; i++)
	{
		std::cin >> num[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (num[start] > num[end])
		{
			temp = num[start];
			start++;
		}
		else
		{
			temp = num[end];
			end--;
		}
		if (i % 2 == 0)
			sereja += temp;
		else
			dima += temp;
	}
std::cout << sereja << " " << dima << std::endl;
	return 0;
}

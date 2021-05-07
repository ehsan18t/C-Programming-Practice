#include <bits/stdc++.h>

int main()
{
	int n, k;
	int x1, y1;
	int x2, y2;
	double length = 0;
	double result;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		std::cin >> x2 >> y2;
		if (i != 0)
		{
			length += sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		}
		x1 = x2;
		y1 = y2;
	}
	result = (length * k) / 50;
	printf("%.9lf\n", result);
	return 0;
}
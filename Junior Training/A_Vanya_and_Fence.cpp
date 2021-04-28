#include <bits/stdc++.h>

int main()
{
	int n, h, result = 0;
	std::cin >> n >> h;
	for (int i = 0; i < n; i++)
	{
		int a;
		std::cin >> a;
		if (a > h)
			result += 2;
		else
			result++;
	}
	std::cout << result << std::endl;
	return 0;
}


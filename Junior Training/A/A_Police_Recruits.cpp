#include <bits/stdc++.h>
// https://codeforces.com/contest/427/problem/A
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
	int crime = 0;
	int police = 0, input, n;
	std::cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			police = arr[i];
			i++;
			// resolving crimes while we have police available
			while (police > 0 && i < n)
			{
				// dbg(i);
				// dbg(police);
				police += arr[i];
				i++;
			}
			// i increased to check condition, so we reduced again after checking condition
			i--;
		}
		else
			crime += arr[i];
	}

	std::cout << (-1 * crime) << std::endl;
	return 0;
}
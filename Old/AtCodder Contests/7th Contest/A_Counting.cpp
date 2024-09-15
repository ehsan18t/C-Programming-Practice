#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
	int a, b;
	int result = 0;
	std::cin >> a >> b;
	if (b > a)
	{
		for (int i = a; i <= b; i++)
			result++;
	}
	std::cout << result << std::endl;
	return 0;
}
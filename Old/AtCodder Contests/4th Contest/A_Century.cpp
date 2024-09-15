#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "./Debugging Tools/dbg.cpp"
#include "./Debugging Tools/MemView.cpp"
#endif

int main()
{
	int n;
	std::cin >> n;
	std::cout << ((n % 100) == 0 ? (n / 100) : ((n / 100) + 1)) << std::endl;
	return 0;
}
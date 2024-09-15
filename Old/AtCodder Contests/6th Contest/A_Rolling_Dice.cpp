#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
	int a, b;
    int count = 0;
	std::cin >> a >> b;
    double num = double(b) / a;
    if (a <= b && b <= a * 6)
    	std::cout << "Yes" << std::endl;
    else
    	std::cout << "No" << std::endl;
	return 0;
}
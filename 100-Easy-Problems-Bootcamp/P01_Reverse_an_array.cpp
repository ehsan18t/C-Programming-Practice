#include <bits/stdc++.h>
// https://codeforces.com/group/yg7WhsFsAp/contest/355490/problem/P01
#ifndef ONLINE_JUDGE
#include "../Debugging Tools/dbg.cpp"
#include "../Debugging Tools/MemView.cpp"
#endif

int main()
{
	int n;
	std::cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	int count = 0;
	while (count < n / 2)
	{
		std::swap(arr[count], arr[n - count - 1]);
		count++;
	}
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << " ";
	return 0;
}
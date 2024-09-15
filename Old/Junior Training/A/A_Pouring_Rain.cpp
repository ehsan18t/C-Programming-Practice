#include <bits/stdc++.h>

#define PI acos(-1);

int main()
{
	int d, h, v, e;
	std::cin >> d >> h >> v >> e;
	double pi = PI;
	// radius = diameter / 2
	double r2 = pow((d * 0.5), 2);
	// Formula: PI r^2 * h
	double inital_water = (pi * r2) * h;
	double tmp = (pi * r2) * e;
	double rate = v - tmp;
	double result = inital_water / rate;
	if (result > 10000 || result < 0.0001)
		std::cout << "NO" << std::endl;
	else
		std::cout << "YES\n" << std::setprecision(13) << result << std::endl;
	return 0;
}

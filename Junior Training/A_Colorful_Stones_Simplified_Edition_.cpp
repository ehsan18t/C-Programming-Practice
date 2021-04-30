#include <bits/stdc++.h>

int main()
{
	int j = 0;
	int i = 0;
	int position = 1;
	char path[51];
	char cmd[51];
	std::cin >> path;
	std::cin >> cmd;
	while (cmd[i] != '\0')
	{
		if (path[j] == cmd[i])
		{
			position++;
			j++;
		}
		i++;
	}
	std::cout << position << std::endl;
	return 0;
}
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "../../Debugging Tools/dbg.cpp"
#include "../../Debugging Tools/MemView.cpp"
#endif

using namespace std;

int main()
{
	int n;

	// adding data
	unordered_map<char, char> data;
	data[')'] = '0';
	data['}'] = '0';
	data[']'] = '0';

	data['('] = ')';
	data['{'] = '}';
	data['['] = ']';

	cin >> n;
	while (n--)
	{
		stack<char> brackets;
		string str;
		cin >> str;
		int i = 0;
		while (str[i] != '\0')
		{
			char ch = str[i];
			if (!brackets.empty() && ch == data[brackets.top()])
				brackets.pop();
			else
				brackets.push(ch);
			i++;
		}
		cout << (brackets.empty() ? "YES" : "NO") << endl;
	}

	return 0;
}
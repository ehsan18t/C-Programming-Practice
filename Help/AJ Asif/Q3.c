#include <stdio.h>

int isVowel(char ch)
{
	char v[] = {'a', 'e', 'i', 'o', 'u'};

	// if ch is vowel return 1
	for (int i = 0; i < 5; ++i)
		if (ch == v[i])
			return 1;

	// if not vowel return 0
	return 0;
}

int countDistinct(int arr[], int n)
{
	int count = 0;

	// Pick all elements one by one
	for (int i = 1; i < n; i++)
	{
		int isDup = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] == arr[j] && i != j)
			{
				isDup = 0;
				break;
			}

		// if not find any duplicate before, increase count
		if (isDup == 1)
			count++;
	}
	return count;
}

int countEvenDistinct(int arr[], int n)
{
	int count = 0;

	// Pick all elements one by one
	for (int i = 1; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			int isDup = 1;
			for (int j = 0; j < i; j++)
				if (arr[i] == arr[j] && i != j)
				{
					isDup = 0;
					break;
				}

			// if not find any duplicate before, increase count
			if (isDup == 1)
				count++;
		}
	}
	return count;
}

int main()
{
	char ch;
	int n, count;
	int arr[100];

	// input
	printf("Input array size: \n");
	scanf("%d", &n);

	printf("Input array: \n");
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("Input a char: \n");
	getchar();
	scanf("%c", &ch);

	if (isVowel(ch))
		printf("Distinct Element = %d\n", countDistinct(arr, n));
	else
		printf("Distinct Even Element = %d\n", countEvenDistinct(arr, n));
	return 0;
}
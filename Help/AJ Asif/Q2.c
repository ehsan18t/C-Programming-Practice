#include <stdio.h>

int isVowel(ch)
{
	char v[] = {'a', 'e', 'i', 'o', 'u'};

	// making ch lower case
	if(ch >= 'A' && ch <= 'Z')
		ch += 32;

	// if ch is vowel return 1
	for (int i = 0; i < 5; ++i)
		if(ch == v[i])
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
        int j = 0;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;
 
        // if not find any duplicate before, increase count
        if (i == j)
			count++;
    }
	return count;
}

int main()
{
	int n, v;
	int count = 0;
	int arr[100];

	// input
	printf("Input array size: \n");
	scanf("%d", &n);

	printf("Input array: \n");
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	printf("Input V: \n");
	scanf("%d", &v);
		
	// check even/odd
	if (v % 2 == 0)
	{
		for (int i = 0; i < n; ++i)
			if (isVowel(arr[i] + 96))
				count++;
	}
	else
	{
		count = countDistinct(arr, n);
	}
	printf("%d\n", count);
	return 0;
}
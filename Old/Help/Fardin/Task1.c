#include <stdio.h>
#include <stdlib.h> // for atoi()
#include <ctype.h>  // for isdigit()

#define MAX_INT 2147483647

int input_array_from_string(const char *, int[]);
void print_array(int arr[], int n);

int main()
{
    // input format:
    // [2, 1, -3, 1, -4, 2, 1, 5, 4]
    // [2,1,-3,1,-4,2,1,5,4]
    // both of them should works (tried to match pdf)
    const char *str;
    char input[999999];

    printf("Enter array (String): ");
    gets(input);
    str = input;
    int arr[99999];
    int n = input_array_from_string(str, arr);

    // print_array(arr, n); // debug
    int start_index;
    int end_index;
    int sub_array_sum = MAX_INT;
    int min_sum = MAX_INT;

    for (int i = 0; i < n; i++)
    {
        if (sub_array_sum > 0)
        {
            sub_array_sum = arr[i];
            if (sub_array_sum < min_sum)
                start_index = i;
        }
        else
            sub_array_sum += arr[i];

        if (min_sum > sub_array_sum)
        {
            min_sum = sub_array_sum;
            end_index = i;
        }
    }
    printf("Sum: %d\nIndex Range: [%d, %d]\n", min_sum, start_index, end_index);
    return 0;
}

int input_array_from_string(const char *str, int arr[])
{
    int i = 0;
    int j = 0;
    while (str[j] != '\0')
    {
        int digit = 0;
        int sign = 1;

        while (!isdigit(str[j]) && str[j] != '\0')
        {
            // minus sign from pdf seems different
            // it says there are multi char
            // so sample input copy paste from pdf might not not work
            if (str[j] == '-')
                sign = -1;
            j++;
        }

        while (isdigit(str[j]) && str[j] != '\0')
        {
            arr[i] += (sign * (atoi(str + j) + (digit * 10)));
            j++;
            digit++;
        }
        i++;
    }
    return i - 1;
}

// debug function
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

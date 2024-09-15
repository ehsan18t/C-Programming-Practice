#include <stdio.h>

// take input in array
void scan_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Print array
void print_arr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Swap
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// min index
int min_index(int arr[], int len)
{
    int min_ind = 0;
    for (int i = 1; i <= len; i++)
    {
        if (arr[i] < arr[min_ind]) // "<=" will return last min index
        {
            min_ind = i;
        }
    }
    return min_ind;
}

// min index (Special for sort with min)
int min_index_sp(int arr[], int len, int count)
{
    int min_ind = count;
    for (int i = count + 1; i <= len; i++)
    {
        if (arr[i] < arr[min_ind]) // "<=" will return last min index
        {
            min_ind = i;
        }
    }
    return min_ind;
}

// max index
int max_index(int arr[], int len)
{
    int max_ind = 0;
    for (int i = 1; i <= len; i++)
    {
        if (arr[i] >= arr[max_ind])
        {
            max_ind = i;
        }
    }
    return max_ind;
}

// max index (Special)
int max_index_sp(int arr[], int len, int count)
{
    int max_ind = count;
    for (int i = count + 1; i <= len; i++)
    {
        if (arr[i] >= arr[max_ind])
        {
            max_ind = i;
        }
    }
    return max_ind;
}

//************//
//    Sort    //
//************//
// bubble sort
// without max or min value
// decending
// swap() function needed
void sort_without_maxmin(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++) // replce "i + 1" with "0" to reverse sorting
        {
            if (arr[i] < arr[j]) // use '>' to make in assendin
                swap(&arr[i], &arr[j]);
        }
    }
}

// sort with min index (assending)
// swap() function needed
void sort_with_min_asc(int arr[], int len)
{
    // normal loop (Ansan)
    // for (int i = 0; i < len; i++)
    // {
    //     int index = min_index_sp(arr, len, i);
    //     swap(&arr[i], &arr[index]);
    // }

    // reverse loop (Fahad)
    len--;
    for (int i = len; i >= 0; i--)
    {
        int index = min_index_sp(arr, len, len - i);
        swap(&arr[len - i], &arr[index]);
    }
}

// sort with max index (assending)
// swap() function needed
void sort_with_max_asc(int arr[], int len)
{
    len--;
    // normal loop (Ahsan)
    for (int i = 0; i < len; i++)
    {
        int index = max_index(arr, len - i);
        swap(&arr[len - i], &arr[index]);
    }

    // reverse loop (Fahad)
    // alternative
    // for (int i = len; i > 0; i--)
    // {
    //     int index = max_index(arr, i);
    //     swap(&arr[i], &arr[index]);
    // }
}

// sort with min index (decending)
// swap() function needed
void sort_with_min_dec(int arr[], int len)
{
    // normal loop (Ahsan)
    // for (int i = 0; i < len; i++)
    // {
    //     int index = min_index(arr, len - i);
    //     swap(&arr[len - i], &arr[index]);
    // }

    // reverse loop (Fahad)
    len--;
    for (int i = len; i >= 0; i--)
    {
        int index = min_index(arr, i);
        swap(&arr[i], &arr[index]);
    }
}
///////////////////////////////////

// sort with max index (decending)
// swap() function needed
void sort_with_max_dec(int arr[], int len)
{
    len--;
    // while loop (Ahsan)
    // int i = 0;
    // while (i < len)
    // {
    //     int index = max_index_sp(arr, len, i);
    //     swap(&arr[i], &arr[index]);
    //     i++;
    // }

    // for loop(Fahad)
    for (int i = 0; i < len; i++)
    {
        int index = max_index_sp(arr, len, i);
        swap(&arr[i], &arr[index]);
    }
}

///////////////////////////////////////
// copy array
void copy_arr(int arr1[], int arr2[], int len)
{
    for (int i = 0; i < len; i++)
    {
        arr2[i] = arr1[i];
    }
}

// reverse array
// swap() function needed
void arr_reverse(int arr[], int len)
{
    len--;
    for (int i = 0; i < len / 2; i++)
    {
        swap(&arr[i], &arr[len - i]);
    }
}

////////////////////////////////
/////        Search        ////
//////////////////////////////

// normal search
int arr_search(int arr[], int len, int search)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == search)
        {
            return 1; // replace i with 1 to get index number
        }
    }
    // 1 = true, 0 = false
    return 0; // if returning index it will be -1
}

// binary search
// MUST BE SORTED ARRAY
int bin_search(int arr[], int len, int search)
{
    int start = 0;
    int end = len;
    while (start <= end)
    {
        int index = start + (end - start) / 2;
        if (arr[index] == search)
            return index;
        if (arr[index] < search)
            start = index + 1;
        else
            end = index - 1;
    }
    return -1;
}

/////////////////////////////////////////
////     Arithmetic Operation       ////
////////////////////////////////////////

// power function
int power(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
    {
        result *= x;
    }
    return result;
}

// squre root
double square_root(int x)
{
    double result = x / 2;
    double temp = 0;
    while (result != temp)
    {
        temp = result;
        result = (x / temp + temp) / 2;
    }
    return result;
}

// Armstrong Number
// power() is required
int is_armstrong(int num)
{
    int sum = 0;
    int digits = 0;
    int n = num;
    // counting digits
    while (n != 0)
    {
        digits++;
        n /= 10;
    }
    n = num;
    // calculating number
    while (n != 0)
    {
        sum += power(n % 10, digits);
        n /= 10;
    }
    if (n == sum)
        return 1;   // true
    else
        return 0;   // false
}

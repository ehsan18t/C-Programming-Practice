#include <bits/stdc++.h>

// In/out
#ifndef ONLINE_JUDGE
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#else
#define in printf("")
#define out printf("")
#endif // !ONLINE_JUDGE

using namespace std;

/////////////////////
//                 //
//     Solution    //
//                 //
/////////////////////

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
// Input Array
#define input(arr, n)           \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];

// Print Array
#define print(arr, s, n)        \
    for (int i = s; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << endl;

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

struct maxSubArr
{
    int start;
    int end;
    int sum;
} typedef maxSubArr;

maxSubArr max(maxSubArr a, maxSubArr b)
{
    return (a.sum > b.sum) ? a : b;
}

maxSubArr max(maxSubArr a, maxSubArr b, maxSubArr c)
{
    return max(max(a, b), c);
}

maxSubArr add(maxSubArr a, maxSubArr b)
{
    return {min(a.start, b.start), max(a.end, b.end), a.sum + b.sum};
}

// Linear Approach
maxSubArr maxSubArrSum(vector<int> arr)
{
    int n = arr.size();
    maxSubArr currentSum = {-1, -1, 0}, maxSum = {-1, -1, 0}, max = {-1, -1, INT_MIN};

    // Find Largest Sum Sub-array
    for (int i = 0; i < n; i++)
    {
        currentSum.sum += arr[i];
        // Reset if sum is negative
        if (currentSum.sum < 0)
        {
            currentSum.sum = 0;
            currentSum.start = -1;
        }
        else
        {
            // if sum is positive remember details
            currentSum.end = i;
            if (currentSum.start == -1)
                currentSum.start = i;
        }
        // if current sum is bigger store it to maxSum
        if (currentSum.sum > maxSum.sum)
            maxSum = currentSum;

        // maximum element of the array
        if (max.sum < arr[i])
        {
            max.sum = arr[i];
            max.start = i;
            max.end = i;
        }
    }

    // if all elements are negative
    if (maxSum.start == -1)
        maxSum = max;

    return maxSum;
}

// Divide and Conquer Approach
maxSubArr maxCrossingSum(vector<int> arr, int l, int m, int h);
maxSubArr maxSubArraySum(vector<int> arr, int l, int h)
{
    // Base Case
    if (l == h)
        return {l, l, arr[l]};

    // mid
    int m = (l + h) / 2;

    return max(maxSubArraySum(arr, l, m), maxSubArraySum(arr, m + 1, h), maxCrossingSum(arr, l, m, h));
}

maxSubArr maxCrossingSum(vector<int> arr, int l, int m, int h)
{
    // Include elements on left of mid.
    maxSubArr leftSum = {-1, -1, INT_MIN}, sum = {m, m, 0};
    for (int i = m; i >= l; i--)
    {
        sum.sum += arr[i];
        // if current sum is bigger store it to maxSum
        if (sum.sum > leftSum.sum)
        {
            sum.start = i;
            leftSum = sum;
        }
    }

    // Include elements on right of mid
    sum = {m + 1, m + 1, 0};
    maxSubArr rightSum = {-1, -1, INT_MIN};
    for (int i = m + 1; i <= h; i++)
    {
        sum.sum += arr[i];
        // if current sum is bigger store it to maxSum
        if (sum.sum > rightSum.sum)
        {
            sum.end = i;
            rightSum = sum;
        }
    }

    return max(add(leftSum, rightSum), leftSum, rightSum);
}

void solve()
{
    int n;
    maxSubArr maxSum;
    cin >> n;
    vector<int> arr(n);
    input(arr, n);

    // Find Max Sum -> O(n)
    maxSum = maxSubArrSum(arr);

    // Divide and Conquer -> n(logN)
    // maxSum = maxSubArraySum(arr, 0, n - 1);

    // output
    cout << "sum: " << maxSum.sum << endl;
    print(arr, maxSum.start, maxSum.end + 1);
}

int main()
{
    // in;
    // out;
    int n = 1;
    // cin >> n;
    while (n--)
        solve();
    return 0;
}

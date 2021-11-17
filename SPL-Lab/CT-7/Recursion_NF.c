// GCD
int GCD(int x, int y)
{
    // x is bigger
    if (y != 0)
        return GCD(y, x % y);
    else
        return x;
}

// LCM
int LCM(int x, int y)
{
    // x is smaller
    static int lcm = 0;
    lcm += y;
    if ((lcm % x != 0) && (lcm % y != 0))
        return LCM(x, y);
    else
        return lcm;
}

// Bin to Dec
// int bintodec(char binary[], int i)
// {
//     int dec = 0;
//     if (i >= 0)
//     {
//         dec = pow(2, i);
//         return dec + bintodec(binary, --i);
//     }
//     return dec;
// }

// Dec to Bin
// Dec to Hex
// Hex to Dec
// Palindrome
// Max index
// Min index
// Max value (array)
// Min value (array)
// Copy String
// Concat String
// Case conversion
// Combination Purmutation
// Power
// Factorial
// sort (Low praiority)
// Prime Number
// Armstrong Number
// Series
//
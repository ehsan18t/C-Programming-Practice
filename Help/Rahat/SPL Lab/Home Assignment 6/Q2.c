#include <stdio.h>

/*
Input:
Enter two distances (feet inch):
5 7
4 8

Output:
Total Distances: 10.00 Feet 3.00 Inch
*/

struct distance
{
    double feet;
    double inches;
} typedef distance;

distance sum(distance, distance);

int main()
{
    // freopen("Q2.in", "r", stdin);    // debug
    // Declare variables
    distance d1;
    distance d2;
    distance d3;

    // Prompt the user to enter two distances
    printf("Enter two distances (feet inch):\n");
    scanf("%lf %lf", &d1.feet, &d1.inches);
    scanf("%lf %lf", &d2.feet, &d2.inches);

    // Display the sum of the two distances
    d3 = sum(d1, d2);
    printf("Total Distances: %.2lf Feet %.2lf Inch\n", d3.feet, d3.inches);
    return 0;
}

distance sum(distance a, distance b)
{
    distance c;
    c.feet = a.feet + b.feet;
    c.inches = a.inches + b.inches;
    if (c.inches >= 12)
    {
        c.feet++;
        c.inches -= 12;
    }
    return c;
}

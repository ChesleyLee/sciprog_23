#include <stdio.h>
#include <math.h>

int main() {
    // Set the values for n, a, and r for the three cases
    int n1 = 10000;
    double a1 = 2.0;
    double r1 = 0.01;

    int n2 = 500;
    double a2 = 0.01;
    double r2 = 1.1;

    int n3 = 100;
    double a3 = 0.0001;
    double r3 = 2.0;

    // Initialize variables to store the summation and the formula results
    double sum1 = 0.0;
    double sum2 = 0.0;
    double sum3 = 0.0;

    // Calculate Sn using a loop for the three cases
    for (int i = 0; i <= n1; i++) {
        sum1 += a1 * pow(r1, i);
    }

    for (int i = 0; i <= n2; i++) {
        sum2 += a2 * pow(r2, i);
    }

    for (int i = 0; i <= n3; i++) {
        sum3 += a3 * pow(r3, i);
    }

    // Calculate Sn using the formula
    double formula1 = (a1 * (1 - pow(r1, n1 + 1))) / (1 - r1);
    double formula2 = (a2 * (1 - pow(r2, n2 + 1))) / (1 - r2);
    double formula3 = (a3 * (1 - pow(r3, n3 + 1))) / (1 - r3);

    // Compare the results
    printf("For Case 1 (n = %d, a = %lf, r = %lf):\n", n1, a1, r1);
    printf("Summation: %lf\n", sum1);
    printf("Formula: %lf\n", formula1);

    printf("\nFor Case 2 (n = %d, a = %lf, r = %lf):\n", n2, a2, r2);
    printf("Summation: %lf\n", sum2);
    printf("Formula: %lf\n", formula2);

    printf("\nFor Case 3 (n = %d, a = %lf, r = %lf):\n", n3, a3, r3);
    printf("Summation: %lf\n", sum3);
    printf("Formula: %lf\n", formula3);

    return 0;
}


//In the second case (n = 500, a = 0.010000, r = 1.100000) and the third case (n = 100, a = 0.000100, r = 2.000000), the discrepancies between the results obtained from the summation and the formula calculations are due to numerical computation errors. These differences become more pronounced as r increases, n decreases, and a becomes smaller, leading to inconsistent numerical results. In the firs case(n = 10000, a = 2.000000, r = 0.010000),n is a large sample size, the summation result and formula result is the same.
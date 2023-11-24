#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double trapezoidal_rule(double a, double b, int N) {
    double h = (b - a) / N;
    double sum = (tan(a) + tan(b)) / 2.0; 
    int i; 
    for (i = 1; i < N; i++) {
        double x_i = a + i * h;
        sum += tan(x_i); 
    }
    return h * sum;
}

int main() {
    double a = 0.0;
    double b = M_PI / 3.0;
    int N = 12; 

    double integral_approx = trapezoidal_rule(a, b, N);
    double actual_result = log(2);

    printf("Approximate the integral using the trapezoidal rule: %f\n", integral_approx);
    printf("Actual Result£¨log(2)£©: %f\n", actual_result);
    printf("Different Value: %f\n", fabs(integral_approx - actual_result));

    return 0;
}

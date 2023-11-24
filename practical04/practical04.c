#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define NUM_POINTS 13  // Define the number of points for the array

double tan_values[NUM_POINTS]; // Global array to hold the tangent values

// Function to convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to calculate the area under the curve using the trapezoidal rule
double trapezoidal_rule(int N) {
    double a = degrees_to_radians(0.0); // Convert start degree to radians
    double b = degrees_to_radians(60.0); // Convert end degree to radians
    double h = (b - a) / (N - 1);
    double area = (tan_values[0] + tan_values[N - 1]) / 2.0;

    for (int i = 1; i < N - 1; i++) {
        area += tan_values[i];
    }

    area *= h;
    return area; // The area is already in radians, no need to convert
}

int main() {
    // Calculate tan(x) for 0 to 60 degrees in 5-degree increments
    for (int i = 0; i < NUM_POINTS; i++) {
        double degree = i * 5.0;
        double radian = degrees_to_radians(degree);
        tan_values[i] = tan(radian);
    }

    // Print the tan values without any special formatting
    printf("Tangent values:\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("tan(%d degrees) = %f\n", i * 5, tan_values[i]);
    }

    // Calculate the area under the curve of tan(x) from 0 to 60 degrees
    double area = trapezoidal_rule(NUM_POINTS);
    printf("Area under the curve from 0 to 60 degrees (in radians): %f\n", area);

    return 0;
}
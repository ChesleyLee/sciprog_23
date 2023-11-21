#include <stdio.h>

// Function to calculate the determinant of a 3x3 matrix.
float determinant_3x3(float matrix[3][3]) {
    float det;
    det = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
          matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
          matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

// Function to calculate the determinant of a 4x4 matrix using Cramer's rule.
float determinant_4x4(float matrix[4][4]) {
    float det = 0;
    float minor[3][3];
    
    for (int i = 0; i < 4; i++) {
        // Get the 3x3 minor for each element in the first row.
        for (int j = 0; j < 3; j++) {
            for (int k = 0, col = 0; k < 4; k++) {
                if (k != i) {
                    minor[j][col++] = matrix[j + 1][k];
                }
            }
        }

        // Calculate the determinant of the 3x3 minor.
        float minor_det = determinant_3x3(minor);
        
        // Add or subtract the minor's determinant from the total determinant.
        det += matrix[0][i] * minor_det * (i % 2 == 0 ? 1 : -1);
    }

    return det;
}

int main() {
    int rows = 4, cols = 4; // The number of rows and columns of the matrix
    float matrix[4][4];

    // Use loop to generate a matrix and fill the matrix array
    printf("The matrix is:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            // Calculate the numerator and denominator
            int numerator = 1;
            int denominator = i + j - 1;

            // Fill the matrix
            matrix[i - 1][j - 1] = numerator / denominator;

            // Print out the form of the score
            printf("%d/%d ", numerator, denominator);
        }
        printf("\n"); // Line wrap at the end of each line
    }

    // Calculate the determinant of the 4x4 matrix.
    float det = determinant_4x4(matrix);

    // Print the determinant.
    printf("The determinant of the matrix is: %.2f\n", det);

    return 0;
}
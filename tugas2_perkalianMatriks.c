#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 2048

void generateMatrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = (double)rand() / RAND_MAX * 100.0;  // Angka acak antara 0 dan 100
        }
    }
}

void multiplyMatrices(double mat1[SIZE][SIZE], double mat2[SIZE][SIZE], double result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(double matrix[SIZE][SIZE]) {
    printf("Hasil matriks:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Deklarasi matriks
    static double mat1[SIZE][SIZE];
    static double mat2[SIZE][SIZE];
    static double result[SIZE][SIZE];

    // Menginisialisasi angka acak
    srand(time(NULL));

    // Mengisi matriks dengan angka acak
    generateMatrix(mat1);
    generateMatrix(mat2);

    // Menghitung waktu mulai
    clock_t start = clock();

    // Mengalikan matriks
    multiplyMatrices(mat1, mat2, result);

    // Menghitung waktu selesai
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Waktu yang diperlukan untuk perkalian matriks 2048x2048: %f detik\n", time_taken);

    // Mencetak seluruh hasil matriks ke terminal
    printMatrix(result);

    return 0;
}

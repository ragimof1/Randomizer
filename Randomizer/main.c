#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void randomizer(int **arr, int n, int size);
void stddev(int *arr[], int n, double *deviation);
void av(int *arr[], int n, float *average);

int main() {
    int n, size;
    clock_t start, end;
    printf("Please enter the amount of numbers that needs to be generated\n");
    scanf("%d", &n);
    printf("Please enter the maximum number that the generator should reach:\n");
    scanf("%d", &size);
    int *arr[n];
    float average;
    double deviation;
    start = clock();
    randomizer(arr, n, size);
    end = clock();
    printf("Your random numbers are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *arr[i]);
    }
    printf("\nTime spent to generate the array: %.5f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    av(arr, n, &average);
    end = clock();
    printf("\nThe average of the random numbers is: %.2f\n", average);
    printf("Time spent to calculate the average of the numbers: %.5f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    start = clock();
    stddev(arr, n, &deviation);
    end = clock();
    printf("\nThe standard deviation of the random numbers is: %lf\n", deviation);
    printf("Time spent to calculate the standard deviation: %.5f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    return 0;
}

void randomizer(int **arr, int n, int size) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(sizeof(int));
        *arr[i] = rand() % size + 1;
    }
}

void av(int *arr[], int n, float *average) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *arr[i];
    }
    *average = sum / n;
}

void stddev(int *arr[], int n, double *deviation) {
    double mean = 0;
    double diff = 0;
    for (int i = 0; i < n; i++) {
        mean += *arr[i];
    }
    mean /= n;
    for (int i = 0; i < n; i++) {
        diff += pow(*arr[i] - mean, 2);
    }
    *deviation = sqrt(diff / n);
}

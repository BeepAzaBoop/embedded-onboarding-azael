#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void FizzBuzz(int n);
int compareIntegers(const void *a, const void *b);
typedef struct
{
    int rows;
    int cols;
    float *data;
} matrix_t;

int main()
{ // Exercise 1
    char str[] = {"Hello, World!"};
    printf("%s\n", str);
    char *pStr = &str[0];
    printf("\"Hello World\" in integers\n");
    int strSize = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < strSize; i++)
    {
        printf("%d ", pStr[i]); // pStr[i] = *(pStr + i)
    }
    printf("\n");

    // Exercise 1.1 CORRECTED CODE:
    // matrix_t matrix_transpose(matrix_t m)
    // {
    //     matrix_t result = create_matrix(m.cols, m.rows); //<- assume this has been implemented

    //     for (int row = 0; row < m.rows; row++) // change mt to result for clarity
    //     {
    //         for (int col = 0; col < m.cols; col++) // change i and j to row and col for clarity
    //         {
    //             result.data[col * m.rows + row] = m.data[row * m.cols + col]; // indexing the data array in row-major order
    //             // indexing also dereferences the data array
    //         }
    //     }

    //     return result;
    // }

    // Exercise 2
    int arraySize = 20;
    int *array = malloc(arraySize * sizeof(int)); // allocate 20 bytes for this int array
    // type, pointer pointer variable = malloc(amount of bytes you want to allocate * one byte in bits in your variable/array)
    printf("Array\n");
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = i + 1; // ensures that assignment starts at 1 since i begins at 0
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("*****************\n");

    printf("FizzBuzz ran on the array\n");

    printf("*****************\n");
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = i + 1; // ensures that assignment starts at 1 since i begins at 0
        FizzBuzz(array[i]);
    }

    printf("*****************\n");

    printf("FizzBuzz ran on numbers 1 to 30\n");

    printf("*****************\n");
    for (int i = 1; i <= 30; i++)
    {
        FizzBuzz(i);
    }

    // Exercise 3

    // address of first element, total elements, the size of one element, pointer to function
    qsort(array, arraySize, sizeof(array[0]), compareIntegers);
    // recall that simple stating the function without () will be a pointer to the actual function
    printf("*****************\n");
    printf("Array sorted in descending order\n");
    printf("*****************\n");

    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
    free(array);
    return 0;
}

void FizzBuzz(int n)
{

    if (n % 3 == 0)
    {
        printf("Fizz\n");
    }
    if (n % 5 == 0)
    {
        printf("Buzz\n");
    }
    if ((n % 3 == 0) && (n % 5 == 0))
    {
        printf("FizzBuzz\n");
    }
}
int compareIntegers(const void *a, const void *b) // parameters are this way because qsort expects any data type
{
    int A = *(int *)a; // treat 'a' as a pointer to integers and retrieve that value
    int B = *(int *)b; // same with this
    return (A < B) - (A > B);
}
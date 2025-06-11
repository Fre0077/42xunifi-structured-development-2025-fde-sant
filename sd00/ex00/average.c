#include "average.h"

int main()
{
    int arr[] = {2, 1, 2};
    printf("output: %f\n", average(arr, 3));
    return (0);
}

float average(const int *arr, int size)
{
    if (arr == NULL || size <= 0)
        return (-1);
    float avarage = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0 || arr[i] > 100)
            continue;
        avarage += arr[i];
    }
    avarage /= size;
    return avarage;
}
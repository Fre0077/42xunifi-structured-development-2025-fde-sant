#include "critical_windows.h"

int main ()
{
    int arr[] = {70, 70, 60, 130, 50, 150, 170, 3, 90, 3, 4};
    printf("output: %d\n", count_critical_windows(arr, 11));
    return (0);
}

int count_critical_windows(const int *readings, int size)
{
    int avarage = 0, count = 0, ret = 0;
    for (int i = 0; i < size - 5; i++)
    {
        avarage = 0;
        count = 0;
        for (int j = 0; j < 5; j++)
        {
            if (readings[j + i] > 150)
                break;
            if (readings[j + i] >= 70)
                count++;
            avarage += readings[j + i];
        }
        if (avarage / 5 >= 90 && count >= 3)
            ret++;
    }
    return ret;
}
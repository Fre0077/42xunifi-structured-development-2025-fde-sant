#include "first_last.h"

int main ()
{
	int arr[] = {0, 1, 4, 3, 4, 1, 9};
	int	first, last;
	first_last(arr, 7, 1, &first, &last);
    printf("first = %d\nlast = %d\n", first, last);
    return (0);
}

void first_last(int arr[], int size, int target, int *first, int *last)
{
	if (arr == NULL || size <= 0)
        return (-1);
	*first = -1;
	*last = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
		{
			*last = i;
			if (*first == -1)
				*first = i;
		}
	}
}
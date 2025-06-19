#include "segmented_runs.h"

int main()
{
	int arr[] = {2, 3, 4, -1, 5, 6, -1, 1, 2, 3, 4};
	printf("output: %d\n", count_segments(arr, 11));
	return 0;
}

int count_segments(const int *arr, int size)
{
	int last;
	int ret = 0;
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (i == 0 || arr[i] == -1)
		{
			count = 0;
			last = arr[i];
		}
		if ((last == -1 || last < arr[i]) && arr[i] != -1)
			count++;
		if (count >= 3)
			ret++;
		last = arr[i];
	}
	return ret;
}
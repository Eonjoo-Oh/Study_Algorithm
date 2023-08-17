#include <stdio.h>

int	binary_search_recursive(int arr[], int target, int min, int max)
{
	int	mid;

	if (min > max)
		return (-1);
	mid = (min + max) / 2;
	if (arr[mid] == target)
		return (mid);
	else if (arr[mid] > target)
		return (binary_search_recursive(arr, target, min, mid - 1));
	else
		return (binary_search_recursive(arr, target, mid + 1, max));
}

int	binary_search(int arr[], int target)
{
	int	min;
	int	max;
	int	mid;

	min = 0;
	max = sizeof(arr) / sizeof(int) - 1;

	while (min <= max) {
		mid = (min + max) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] > target)
			max = mid - 1;
		else
			min = mid + 1;
	}
	return (-1);
}
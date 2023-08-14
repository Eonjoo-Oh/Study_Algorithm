#include <stdio.h>
#include <stdlib.h>

void	swap(int *arr, int i, int j)
{
	int	temp;

	if (i == j)
		return ;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int		is_descending(int *arr, int n)
{
	int	i;

	i = 0;

	while (i < n - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_ascending(int *arr, int n)
{
	int	i;

	i = 0;

	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;
	int	pivot_i;

	i = start;
	j = end;
	pivot_i = rand() % (end - start + 1) + start;
	pivot = arr[pivot_i];
	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			swap(arr, i, j);
			i++;
			j--;
		}
	}
	if (start < j)
		quick_sort(arr, start, j);
	if (i < end)
		quick_sort(arr, i, end);
}

int main()
{
	int	n;

	scanf("%d", &n);
	int	arr[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	if (is_descending(arr, n) == 1)
	{
		for(int i = n - 1; i >= 0; i--)
		{
			printf("%d\n", arr[i]);
		}
		return (0);
	}
	if (is_ascending(arr, n) == 0)
		quick_sort(arr, 0, n - 1);
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}

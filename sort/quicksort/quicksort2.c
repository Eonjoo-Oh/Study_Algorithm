#include <stdio.h>

void	swap(int *arr, int i, int j)
{
	int	temp;

	if (i == j)
		return ;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void	quick_sort(int *arr, int start, int end)
{
	int	i;
	int	j;
	int	pivot;

	i = start;
	j = end;
	pivot = arr[(start + end) / 2];

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
	quick_sort(arr, 0, n - 1);
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}

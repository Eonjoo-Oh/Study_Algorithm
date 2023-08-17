#include <stdio.h>

/* 피봇을 가장 마지막 요소로 정함, i는 pivot보다 작은 수, j는 현재 어디까지 검사했는지를 의미 */

void	swap(int *arr, int i, int j)
{
	int	temp;

	if (i == j)
		return ;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int divide_conquer(int *arr, int start, int pivot)
{
	int	i;
	int	j;

	i = start - 1;
	j = start;
	while (j < pivot)
	{
		if (arr[j] < arr[pivot])
		{
			i++;
			swap(arr, i, j);
		}
		j++;
	}
	swap(arr, i + 1, pivot);
	return (i + 1);
}

void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = divide_conquer(arr, start, end);
		quick_sort(arr, start, pivot - 1);
		quick_sort(arr, pivot + 1, end);
	}
	else
		return ;
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
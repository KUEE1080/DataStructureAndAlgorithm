#include <stdio.h>
#include <stdlib.h> 

void Swap(int arr[], int x, int y) // arr[x]와 arr[y]를 스왑합니다. 
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int Partition(int arr[], int left, int right)
{
	// arr : 입력받은 숫자 모음
	// 피봇의 위치는 가장 왼쪽에서 시작하고, quicksort의 성질을 이용하세요.
	int idx_pivot = left;
	for (int i = left + 1 ; i <= right; i++)
	{
		if (arr[idx_pivot] > arr[i])
		{
			Swap(arr, idx_pivot + 1, i);
			Swap(arr, idx_pivot, idx_pivot + 1);
			idx_pivot += 1;
		}
	}
	return idx_pivot;
}


void QuickSort(int arr[], int left, int right)
{
	// 둘로 나누어서 왼쪽과 오른쪽을 정렬합니다.  Partition 함수를 이용하세요.
	if (left < right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

//메인함수
int main()
{
	int n, i;
	int a[100];


	printf("몇개의 숫자로 정렬하시겠습니까?\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		a[i] = rand() % 1000;
	//n개의 수를 입력받음

	printf("정렬전 배열 :");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	QuickSort(a, 0, n - 1); //정렬

	printf("정렬후 배열 :");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
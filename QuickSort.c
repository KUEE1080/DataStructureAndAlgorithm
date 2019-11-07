#include <stdio.h>
#include <stdlib.h> 

void Swap(int arr[], int x, int y) // arr[x]�� arr[y]�� �����մϴ�. 
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

int Partition(int arr[], int left, int right)
{
	// arr : �Է¹��� ���� ����
	// �Ǻ��� ��ġ�� ���� ���ʿ��� �����ϰ�, quicksort�� ������ �̿��ϼ���.
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
	// �ѷ� ����� ���ʰ� �������� �����մϴ�.  Partition �Լ��� �̿��ϼ���.
	if (left < right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

//�����Լ�
int main()
{
	int n, i;
	int a[100];


	printf("��� ���ڷ� �����Ͻðڽ��ϱ�?\n");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		a[i] = rand() % 1000;
	//n���� ���� �Է¹���

	printf("������ �迭 :");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	QuickSort(a, 0, n - 1); //����

	printf("������ �迭 :");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
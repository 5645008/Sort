#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;
int move;
int compare;
double allmove;
double allcompare;


//������(��¿�)
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
			compare++;
		} while (low <= right && list[low] < pivot);
		do {
			high--;
			compare++;
		} while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);

		move++;
	} while (low < high);
	SWAP(list[left], list[high], temp);
	move++;
	for (int o = 0; o < n; o++)
		printf("%d ", list[o]);
	printf("\n");
	return high;
}


void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}


//������(��տ�)
int partition1(int list[], int left, int right)
{
	compare = 0;
	move = 0;
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
			compare++;
		} while (low <= right && list[low] < pivot);
		do {
			high--;
			compare++;
		} while (high >= left && list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);

		move++;
	} while (low < high);

	SWAP(list[left], list[high], temp);
	move++;
	allmove = allmove + move;
	allcompare = allcompare + compare;
	return high;
}


void quick_sort1(int list[], int left, int right)
{
	if (left < right) {
		int q = partition1(list, left, right);
		quick_sort1(list, left, q - 1);
		quick_sort1(list, q + 1, right);
	}
}



int main(void)
{
	int i;
	n = MAX_SIZE;
	allmove = 0;
	allcompare = 0;

	//������
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");
	printf("Quick Sort\n");
	quick_sort(list, 0, n - 1);

	//�������� 20ȸ ��� ���ϱ�
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		quick_sort1(list, 0, n - 1);
	}
	//20ȸ ��� ���
	printf("\n");
	printf("Average Move Count: %f\n", allmove / 20);
	printf("Average Comp Count: %f\n", allcompare / 20);


	return 0;
}
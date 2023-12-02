#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20

int sorted[MAX_SIZE];
int list[MAX_SIZE];
int n;
int move;
int compare;
int allmove;
int allcompare;


//�պ�����(��¿�)
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
		move++;
		compare++;
	}
	if (i > mid) 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			move++;
		}
	else 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
			move++;
		}
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++) 
		list[l] = sorted[l];
	for (int o = 0; o < n; o++)
		printf("%d ", list[o]);
	printf("\n");
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // ����Ʈ�� �յ����
		merge_sort(list, left, mid);     // �κи���Ʈ ����
		merge_sort(list, mid + 1, right);//�κи���Ʈ ����
		merge(list, left, mid, right);    // �պ�
	}
}


//�պ�����(��տ�)
void merge1(int list[], int left, int mid, int right)
{
	move = 0;
	compare = 0;
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// ���� ���ĵ� list�� �պ�
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
		move++;
		compare++;
	}
	if (i > mid) 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];
			move++;
		}
	else 	// ���� �ִ� ���ڵ��� �ϰ� ����
		for (l = i; l <= mid; l++) {
			sorted[k++] = list[l];
			move++;
		}
	// �迭 sorted[]�� ����Ʈ�� �迭 list[]�� ����
	for (l = left; l <= right; l++)
		list[l] = sorted[l];

	allmove = allmove + move;
	allcompare = allcompare + compare;
}

void merge_sort1(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // ����Ʈ�� �յ����
		merge_sort1(list, left, mid);     // �κи���Ʈ ����
		merge_sort1(list, mid + 1, right);//�κи���Ʈ ����
		merge1(list, left, mid, right);    // �պ�
	}
}

int main(void)
{
	int i;
	n = MAX_SIZE;
	allmove = 0;
	allcompare = 0;

	//�պ�����
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 100; // ���� �߻� ���� 0~99
	printf("Original List\n");
	for (int k = 0; k < n; k++)
		printf("%d ", list[k]);
	printf("\n\n");

	merge_sort(list,0, n-1);

	//�պ������� 20ȸ ��� ���ϱ�
	for (int s = 0; s < 20; s++) {
		for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
			list[i] = rand() % 100; // ���� �߻� ���� 0~99
		merge_sort1(list,0, n-1);
	}
	//20ȸ ��� ���
	printf("Average Move Count: %d\n", allmove / 20);
	printf("Average Compare Count: %d\n", allcompare / 20);


	return 0;
}